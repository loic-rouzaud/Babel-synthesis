/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** TcpSocket
*/

#ifndef TCPSOCKET_HPP_
#define TCPSOCKET_HPP_

#include <QTcpSocket>

class TcpSocket : public QTcpSocket {
  Q_OBJECT

    public:
        TcpSocket(QObject* parent = nullptr);

    signals:
        void dataReceived(const QString& data);

    private slots:
        void onReadyRead();
        void onError(QAbstractSocket::SocketError error);

    private:
        void connectSignals();
};

#endif /* !TCPSOCKET_HPP_ */
