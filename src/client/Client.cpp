/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Client
*/

#include <QtWidgets>
#include <QtNetwork>
#include "Client.hpp"

Client::Client(QObject *parent) : QObject(parent)
{
    m_socket = new QTcpSocket(this);

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(m_socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
}

Client::~Client()
{
    m_socket->disconnectFromHost();
    delete m_socket;
}

void Client::connectToServer(QString host, int port)
{
    m_socket->connectToHost(host, port);
}

void Client::sendMessage(QByteArray message)
{
    QByteArray data;
    data.append(message);
    m_socket->write(data);
}

void Client::disconnectFromServer()
{
    m_socket->disconnectFromHost();
}

void Client::readyRead()
{
    QByteArray data = m_socket->readAll();
    QString message(data);
    emit messageReceived(message);
}

void Client::connected()
{
    qDebug() << "Connected to server.";
}

void Client::disconnected()
{
    qDebug() << "Disconnected from server.";
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Error: " << socketError;
    emit error(socketError);
}