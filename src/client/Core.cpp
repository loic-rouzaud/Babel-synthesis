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
    QApplication app(ac, av);
    QApplication::setApplicationDisplayName(Client::tr("Fortune Client"));
    Client client;
    client.show();
    return app.exec();
}