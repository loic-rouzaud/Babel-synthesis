/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Server
*/

#include "Server.hpp"

Server::Server(QWidget *parent) : QWidget(parent)
{
    m_jsonManager = new JsonManager();
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
}

void Server::handleNewConnection()
{
    QTcpSocket *client = m_server->nextPendingConnection();
    connect(client, &QTcpSocket::disconnected, this, &Server::handleDisconnected);

    QString clientAddress = client->peerAddress().toString();
    m_clients.append(client);
    std::cout << "New client connected, IP: " << clientAddress.toStdString() << std::endl;
    std::cout << "Number of clients: " << m_clients.size() << std::endl;
    m_jsonManager->createUser(clientAddress);
}

void Server::handleDisconnected()
{
    QTcpSocket *client = static_cast<QTcpSocket*>(sender());
    QString clientAddress = client->peerAddress().toString();
    m_jsonManager->changeStatus(clientAddress);
    m_clients.removeOne(client);
    client->deleteLater();
    std::cout << "Client disconnected" << std::endl;
    std::cout << "Number of clients connected: " << m_clients.size() << std::endl;
}