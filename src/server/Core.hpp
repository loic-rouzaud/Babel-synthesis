/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** Core
*/



#ifndef CORE_HPP_
#define CORE_HPP_

#include <QApplication>
#include "INetwork.hpp"
#include "ISystem.hpp"


class Core : public QApplication {
    public:
        Core(int ac, char **av);
        ~Core();

    protected:
    private:
        Server *_server;
};

#endif /* !CORE_HPP_ */
