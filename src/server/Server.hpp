/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <QDialog>
#include <QString>
#include <QList>

QT_BEGIN_NAMESPACE
class QLabel;
class QTcpServer;
QT_END_NAMESPACE

class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);

private slots:
    void sendFortune();

private:
    void initServer();

    QLabel *statusLabel = nullptr;
    QTcpServer *tcpServer = nullptr;
    QList<QString> fortunes;
};

#endif /* !SERVER_HPP_ */
