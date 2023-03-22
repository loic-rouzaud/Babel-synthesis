/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(int ac, char **av) : QApplication(ac, av)
{
    _network = new Client();
    _graphicSystem = new GraphicSystem();
    QObject::connect(_graphicSystem, SIGNAL(sendConnect(QString, quint16)), _network, SLOT(connectToServer(QString, quint16)));
    QObject::connect(_graphicSystem, SIGNAL(sendMessages(QString)), _network, SLOT(onSendMessage(QString)));
    _graphicSystem->show();

}

Core::~Core()
{
}

int main(int ac, char **av)
{
    Core core(ac, av);
    return core.exec();
}