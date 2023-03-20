/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);

signals:
    void newConnection();

private slots:
    void handleNewConnection();
    void handleReadyRead();
    void handleDisconnected();

private:
    QTcpServer *m_server;
    QList<QTcpSocket*> m_clients;
};

#endif /* !SERVER_HPP_ */
