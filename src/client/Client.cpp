/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Client
*/

#include "Client.hpp"

Client::Client(QObject *parent) : QObject(parent)
{
    m_socket = new QTcpSocket(this);

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(m_socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

Client::~Client()
{
    m_socket->disconnectFromHost();
    delete m_socket;
}

void Client::connectToServer(QString host, quint16 port)
{
    m_socket->connectToHost(host, port);
}

void Client::onSendMessage(QString message)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream << message.length();
    data.append(message.toUtf8());

    m_socket->write(data, data.length());
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