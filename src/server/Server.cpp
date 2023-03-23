/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Server
*/

#include "Server.hpp"
#include <iostream>

Server::Server(QWidget *parent) : QWidget(parent)
{
    m_server = new QTcpServer(this);
    if (!m_server->listen()) {
        QMessageBox::critical(this, tr("Server"), tr("Unable to start the server: %1.").arg(m_server->errorString()));
        close();
        return;
    }
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }

    if (ipAddress.isEmpty()) {
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    }
    std::cout << "Server is running on " << ipAddress.toStdString() << std::endl;
    std::cout << "Port: " << m_server->serverPort() << std::endl;
    connect(m_server, &QTcpServer::newConnection, this, &Server::handleNewConnection);
    // connect(this, Server::youCanWrite(), this, Server::jsonManager());
}

void Server::handleNewConnection()
{
    QTcpSocket *client = m_server->nextPendingConnection();
    connect(client, &QTcpSocket::disconnected, this, &Server::handleDisconnected);

    QString clientAddress = client->peerAddress().toString();
    m_clients.append(client);
    std::cout << "New client connected, IP: " << clientAddress.toStdString() << std::endl;
    std::cout << "Number of clients: " << m_clients.size() << std::endl;
    jsonManager(clientAddress);
}

void Server::jsonManager(QString clientAddress)
{
    QFile jsonFile("DataBase.json");
    jsonFile.open(QIODevice::ReadWrite | QIODevice::Text);

    QJsonDocument jsonDoc;
    if (!jsonFile.isOpen() || jsonFile.size() == 0) {
        QJsonObject jsonObject;
        jsonObject[QString("ipAddress1")] = clientAddress;
        jsonObject[QString("isConnected")] = true;

        QJsonArray jsonArray;
        jsonArray.append(jsonObject);
        jsonDoc = QJsonDocument(jsonArray);
    } else {
        QByteArray jsonData = jsonFile.readAll();
        QJsonDocument jsonDocExisting = QJsonDocument::fromJson(jsonData);

        QJsonArray jsonArrayExisting = jsonDocExisting.array();
        int index = -1;
        for (int i = 0; i < jsonArrayExisting.size(); i++) {
            QJsonObject obj = jsonArrayExisting[i].toObject();
            if (obj["ipAddress" + QString::number(i+1)] == clientAddress) {
                index = i;
                break;
            }
        }

        QJsonObject jsonObject;
        if (index >= 0) {
            jsonObject[QString("ipAddress") + QString::number(index+1)] = clientAddress;
            jsonObject[QString("isConnected")] = true;
            jsonArrayExisting[index] = jsonObject;
        } else {
            int count = jsonArrayExisting.size() + 1;
            jsonObject[QString("ipAddress") + QString::number(count)] = clientAddress;
            jsonObject[QString("isConnected")] = true;
            jsonArrayExisting.append(jsonObject);
        }
        jsonDoc = QJsonDocument(jsonArrayExisting);
    }
    jsonFile.resize(0);
    jsonFile.write(jsonDoc.toJson());
    jsonFile.close();
}

void Server::handleDisconnected()
{
    QTcpSocket *client = static_cast<QTcpSocket*>(sender());
    m_clients.removeOne(client);
    client->deleteLater();
    std::cout << "Client disconnected" << std::endl;
    std::cout << "Number of clients connected: " << m_clients.size() << std::endl;
}