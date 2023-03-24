/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** ANetwork
*/

#ifndef ANETWORK_HPP_
#define ANETWORK_HPP_

#include <QtCore>
#include <QString>
#include <QtNetwork>
#include <QTcpSocket>
#include "TcpSocket.hpp"
#include <QObject>
#include <memory>

class ANetwork : public QObject {

    Q_OBJECT

    public:
        ANetwork();
        ~ANetwork();

    public slots:
        virtual void OnNewClient(QString clientAddress) = 0;
        virtual void OnDisconnected(QString clientAddress) = 0;

    protected:
        QTcpServer *m_server;
    private:
        TcpSocket *_tcpSocket = nullptr;

};

#endif /* !ANETWORK_HPP_ */
