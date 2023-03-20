/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Core
*/

#include "Core.hpp"
#include "QApplication"

Core::Core()
{
}

Core::~Core()
{
}

int main(int ac, char **av)
{
    QCoreApplication a(ac, av);
    Server server;
    QObject::connect(&server, &Server::newConnection, [](){
        qDebug() << "New client connected";
    });
    return a.exec();
}
