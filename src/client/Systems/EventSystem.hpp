/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** EventSystem
*/

#ifndef EVENTSYSTEM_HPP_
#define EVENTSYSTEM_HPP_

#include "../Interface/ISystem.hpp"

class EventSystem {
    public:
        EventSystem();
        ~EventSystem();

    protected:
    private:
        void hangUp();
        void hangOut();
};

#endif /* !EVENTSYSTEM_HPP_ */
