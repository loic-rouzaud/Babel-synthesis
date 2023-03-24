/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** TcpSocket
*/

#include "TcpSocket.hpp"

TcpSocket::TcpSocket(QTcpServer *m_server, QObject *parent) : QObject(parent)
{
    this->_server = m_server;
    if (this->_server == nullptr) {
        std::cout << "Server is null" << std::endl;
    }
}

void TcpSocket::handleNewConnection()
{   
    QTcpSocket *client = _server->nextPendingConnection();
    connect(client, &QTcpSocket::disconnected, this, &TcpSocket::handleDisconnected);

    QString clientAddress = client->peerAddress().toString();
    m_clients.append(client);
    std::cout << "New client connected, IP: " << clientAddress.toStdString() << std::endl;
    std::cout << "Number of clients: " << m_clients.size() << std::endl;
    emit newClient(clientAddress);
}

void TcpSocket::handleDisconnected()
{
    QTcpSocket *client = static_cast<QTcpSocket*>(sender());
    QString clientAddress = client->peerAddress().toString();
    emit disconnected(clientAddress);
    
    m_clients.removeOne(client);
    client->deleteLater();
    std::cout << "Client disconnected" << std::endl;
    std::cout << "Number of clients connected: " << m_clients.size() << std::endl;
}