// /*
// ** EPITECH PROJECT, 2023
// ** Babel-synthesis
// ** File description:
// ** TcpSocket
// */

// #include "TcpSocket.hpp"

// TcpSocket::TcpSocket(QObject *parent) : QObject(parent)
// {
//     m_jsonManager = new JsonManager();
// }

// void TcpSocket::handleNewConnection()
// {
//     QTcpSocket *client = m_server->nextPendingConnection();
//     connect(client, &QTcpSocket::disconnected, this, &TcpSocket::handleDisconnected);

//     QString clientAddress = client->peerAddress().toString();
//     m_clients.append(client);
//     std::cout << "New client connected, IP: " << clientAddress.toStdString() << std::endl;
//     std::cout << "Number of clients: " << m_clients.size() << std::endl;
//     m_jsonManager->createUser(clientAddress);
// }

// void TcpSocket::handleDisconnected()
// {
//     QTcpSocket *client = static_cast<QTcpSocket*>(sender());
//     QString clientAddress = client->peerAddress().toString();
//     m_jsonManager->changeStatus(clientAddress);
//     m_clients.removeOne(client);
//     client->deleteLater();
//     std::cout << "Client disconnected" << std::endl;
//     std::cout << "Number of clients connected: " << m_clients.size() << std::endl;
// }