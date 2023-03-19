/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** TcpSocket
*/

#include "TcpSocket.hpp"

TcpSocket::TcpSocket(QObject* parent)
    : QTcpSocket(parent) {
  connectSignals();
}

void TcpSocket::connectSignals() {
  connect(this, &TcpSocket::readyRead, this, &TcpSocket::onReadyRead);
  connect(this, &TcpSocket::errorOccurred, this, &TcpSocket::onError);
}

void TcpSocket::onReadyRead() {
  QString data = QString::fromUtf8(readAll().data());
  emit dataReceived(data);
}

void TcpSocket::onError(QAbstractSocket::SocketError error) {
  qWarning() << "Socket error: " << error;
}
