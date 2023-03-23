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
#include <QList>
#include <QHostAddress>
#include <QMessageBox>
#include <Qwidget>
#include <QString>
#include <QNetworkInterface>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>

class Server : public QWidget
{
    Q_OBJECT

    public:
        explicit Server(QWidget *parent = nullptr);
        void jsonManager(QString clientAddress);
        void changeStatus(QString clientAddress);

    signals:
        void newConnection();

    private slots:
        void handleNewConnection();
        void handleDisconnected();

    private:
        QTcpServer *m_server = nullptr;
        QList<QTcpSocket*> m_clients;
        bool m_status = false;
};

#endif /* !SERVER_HPP_ */
