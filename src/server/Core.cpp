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
    Server *_server;
    std::cout << "Starting server..." << std::endl;
    _server = new Server();
}

Core::~Core()
{
}

int main(int ac, char **av)
{
    Core core(ac, av);
    return core.exec();
}
