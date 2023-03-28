/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "JsonManager.hpp"
#include "ANetwork.hpp"
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

class Server: public ANetwork
{
    Q_OBJECT

    public:
        explicit Server();

    signals:
        void jsonRefresh(QString clientAddress);

    public slots:
        void OnNewClient(QString clientAddress) override;
        void OnDisconnected(QString clientAddress) override;

    private:
        JsonManager *m_jsonManager = nullptr;
};

#endif /* !SERVER_HPP_ */
