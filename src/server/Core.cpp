/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Core
*/

#include "Core.hpp"
#include <QApplication>
#include <QtWidgets>

Core::Core()
{
}

Core::~Core()
{
}

int main(int ac, char **av)
{
    QApplication app(ac, av);
    QApplication::setApplicationDisplayName(Server::tr("Babel Server"));
    Server server;
    server.show();
    return app.exec();
}
