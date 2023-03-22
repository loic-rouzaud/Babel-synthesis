/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(int ac, char **av) : QApplication(ac, av)
{
    _server = new Server();
    // QObject::connect(tcpServer, SIGNAL(newConnection), this, SLOT(handleNewConnection));
}

Core::~Core()
{
}

int main(int ac, char **av)
{
    Core core(ac, av);
    return core.exec();
}
