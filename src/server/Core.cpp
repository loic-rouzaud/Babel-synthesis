/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Core
*/

#include "Core.hpp"
#include "Server.hpp"
#include <iostream>

Core::Core(int ac, char **av) : QApplication(ac, av)
{
    _graphicSystem = new GraphicSystem();
    Server *_server;
    std::cout << "Starting server..." << std::endl;
    _server = new Server();
    connect(_server, SIGNAL(jsonRefresh(QString)), _graphicSystem, SLOT(refresh(QString)));
}

Core::~Core()
{
}

int main(int ac, char **av)
{
    Core core(ac, av);
    return core.exec();
}
