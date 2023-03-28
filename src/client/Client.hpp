/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

// #include "../server/ANetwork.hpp"

#include <QObject>
#include <QTcpSocket>
#include <QtWidgets>
#include <QtNetwork>
#include <QIODevice>
#include <iostream>

class Client : public QObject
{
    Q_OBJECT

    public:
        explicit Client(QObject *parent = nullptr);
        ~Client();
        void disconnectFromServer();

    signals:
        void messageReceived(QString message);
        void error(QAbstractSocket::SocketError socketError);

    public slots:
        void onSendMessage(QString message);
        void connectToServer(QString host, quint16 port);
        void displayError(QAbstractSocket::SocketError socketError);

    private:
        QTcpSocket *m_socket;
};


#endif /* !CLIENT_HPP_ */
