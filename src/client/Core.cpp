/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Core
*/

#include "Core.hpp"
#include <iostream>
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
    Client client;
    QApplication::setApplicationDisplayName(Client::tr("Fortune Client"));
    client.show();
    return app.exec();
}
