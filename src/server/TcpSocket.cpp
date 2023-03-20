/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** TcpSocket
*/

#include "TcpSocket.hpp"

MyTcpSocket::MyTcpSocket(QObject *parent) : QObject(parent)
{
}

void MyTcpSocket::doConnect()
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    qDebug() << "connecting...";

    socket->connectToHost("google.com", 80);

    if(!socket->waitForConnected(5000)) {
        qDebug() << "Error: " << socket->errorString();
    }
}

void MyTcpSocket::connected()
{
    qDebug() << "connected...";

    socket->write("test");
}

void MyTcpSocket::disconnected()
{
    qDebug() << "disconnected...";
}

void MyTcpSocket::bytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
}

void MyTcpSocket::readyRead()
{
    qDebug() << "reading...";

    qDebug() << socket->readAll();
}