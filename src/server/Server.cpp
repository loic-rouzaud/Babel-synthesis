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
    std::cout << "Server is running on " << ipAddress.toStdString() << ":" << m_server->serverPort() << std::endl;
}



void Server::handleNewConnection()
{
    QTcpSocket *client = m_server->nextPendingConnection();
    // m_status = true;
    connect(client, &QTcpSocket::readyRead, this, &Server::handleReadyRead);
    connect(client, &QTcpSocket::disconnected, this, &Server::handleDisconnected);

    m_clients.append(client);
    emit newConnection();
}

void Server::handleReadyRead()
{
    QTcpSocket *client = static_cast<QTcpSocket*>(sender());

    while (client->bytesAvailable() > 0) {
        QByteArray data = client->readAll();

        client->write("Message received!");
    }
}

void Server::handleDisconnected()
{
    QTcpSocket *client = static_cast<QTcpSocket*>(sender());
    // m_status = false;
    m_clients.removeOne(client);
    client->deleteLater();
}

// void readSocketData() {
//     while(QAbstractSocket::m_pTcpSocket->bytesAvailable()) {
//         QByteArray receivedData = m_pTcpSocket->readAll();     
//     }
// }