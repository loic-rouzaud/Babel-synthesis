/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include "../server/ANetwork.hpp"

#include <QObject>
#include <QTcpSocket>
#include <iostream>
#include <string>

class Client : public QObject
{
    Q_OBJECT

public:
    explicit Client(QObject *parent = nullptr);
    ~Client();

    void connectToServer(QString host, int port);
    void sendMessage(QByteArray message);
    void disconnectFromServer();

signals:
    void messageReceived(QString message);
    void error(QAbstractSocket::SocketError socketError);

private slots:
    void readyRead();
    void connected();
    void disconnected();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket *m_socket;
};


#endif /* !CLIENT_HPP_ */
