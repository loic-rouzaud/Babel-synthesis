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

    std::cout << "Sending message: " << message.toStdString() << std::endl;
    m_socket->write(data, data.length());
}

void Client::disconnectFromServer()
{
    m_socket->disconnectFromHost();
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Error: " << socketError;
    emit error(socketError);
}