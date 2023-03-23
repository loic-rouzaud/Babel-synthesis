/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "JsonManager.hpp"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QHostAddress>
#include <QMessageBox>
#include <Qwidget>
#include <QString>
#include <QNetworkInterface>
#include <iostream>

class Server : public QWidget
{
    Q_OBJECT

    public:
        explicit Server(QWidget *parent = nullptr);
        void createUser(QString clientAddress);
        void changeStatus(QString clientAddress);

    signals:
        void newConnection();

    public slots:
        void handleNewConnection();
        void handleDisconnected();

    private:
        QTcpServer *m_server = nullptr;
        QList<QTcpSocket*> m_clients;
        JsonManager *m_jsonManager = nullptr;
};

#endif /* !SERVER_HPP_ */
