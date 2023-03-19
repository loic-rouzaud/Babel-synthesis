/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Core
*/

#include "Core.hpp"

Core::Core()
{
}

Core::~Core()
{
}

int main(int ac, char *av[])
{
    QApplication app(ac, av);
    QApplication::setApplicationDisplayName(Server::tr("Fortune Server"));
    Server server;
    server.show();
    return app.exec();
}
