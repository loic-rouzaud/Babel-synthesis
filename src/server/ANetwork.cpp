/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** ANetwork
*/

#include "ANetwork.hpp"

ANetwork::ANetwork()
{
    m_server = new QTcpServer();
    _tcpSocket = new TcpSocket(m_server);
    connect(m_server, &QTcpServer::newConnection, _tcpSocket, &TcpSocket::handleNewConnection);
    connect(_tcpSocket, SIGNAL(newClient(QString)), this, SLOT(OnNewClient(QString)));
    connect(_tcpSocket, SIGNAL(disconnected(QString)), this, SLOT(OnDisconnected(QString)));
}


ANetwork::~ANetwork()
{
}

void ANetwork::OnNewClient(QString clientAddress)
{
    qDebug() << "New client connected: " << clientAddress;
    
}

void ANetwork::OnDisconnected(QString clientAddress)
{
    qDebug() << "Client disconnected: " << clientAddress;
}
