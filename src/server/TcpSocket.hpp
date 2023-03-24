/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** TcpSocket
*/

#ifndef TCPSOCKET_HPP_
#define TCPSOCKET_HPP_

// #include "JsonManager.hpp"

#include <QTcpSocket>
#include <QObject>
#include <QAbstractSocket>
#include <QDebug>
#include <QTcpServer>
#include <QList>
#include <iostream>

class TcpSocket : public QObject
{
    Q_OBJECT

    public:
        explicit TcpSocket(QTcpServer *server, QObject *parent = 0);
    
    signals:
        void newClient(QString clientAddress);
        void disconnected(QString clientAddress);
    
    public slots:
        void handleNewConnection();
        void handleDisconnected();

    private:
        QTcpServer *_server;
        QList<QTcpSocket *> m_clients;
};

#endif /* !TCPSOCKET_HPP_ */
