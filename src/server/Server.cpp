/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Server
*/

#include "Server.hpp"
#include <iostream>

Server::Server(QObject *parent) : QObject(parent)
{
    m_server = new QTcpServer(this);

    connect(m_server, &QTcpServer::newConnection, this, &Server::handleNewConnection);

    if (!m_server->listen(QHostAddress::Any, 1234)) {
        qWarning() << "Failed to listen on port 1234";
    }
}

void Server::handleNewConnection()
{
    QTcpSocket *client = m_server->nextPendingConnection();
    connect(client, &QTcpSocket::readyRead, this, &Server::handleReadyRead);
    connect(client, &QTcpSocket::disconnected, this, &Server::handleDisconnected);

    m_clients.append(client);
    
    std::cout << "New connection" << std::endl;
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
    m_clients.removeOne(client);
    client->deleteLater();
}