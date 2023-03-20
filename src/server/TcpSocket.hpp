/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** TcpSocket
*/

#ifndef TCPSOCKET_HPP_
#define TCPSOCKET_HPP_

#include <QTcpSocket>
#include <QObject>
#include <QAbstractSocket>
#include <QDebug>

class MyTcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpSocket(QObject *parent = 0);
    
    void doConnect();

        signals:
    
    public slots:
        void connected();
        void disconnected();
        void bytesWritten(qint64 bytes);
        void readyRead();

    private:
        QTcpSocket *socket;
    
};

#endif /* !TCPSOCKET_HPP_ */
