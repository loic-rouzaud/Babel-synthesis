/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Core
*/



#ifndef CORE_HPP_
#define CORE_HPP_

#include <QApplication>

#include "Client.hpp"
#include "GraphicSystem.hpp"

class Core : public QApplication {
    
    Q_OBJECT

    public:
        Core(int ac, char **av);
        ~Core();

    protected:

    private:
        GraphicSystem *_graphicSystem;
        Client *_network;
};

#endif /* !CORE_HPP_ */
