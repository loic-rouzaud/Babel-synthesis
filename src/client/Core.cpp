/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Core
*/

#include <QApplication>
#include "Core.hpp"

Core::Core()
{
}

Core::~Core()
{
}

int main(int ac, char *av[])
{
    QCoreApplication a(ac, av);

    Client client;
    client.connectToServer("localhost", 1234);
    client.sendMessage("Hello, server!");
    QObject::connect(&client, &Client::messageReceived, [](QString message){
        qDebug() << "Received message from server: " << message;
    });
    return a.exec();
}