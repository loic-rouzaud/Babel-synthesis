/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** ANetwork
*/

#ifndef ANETWORK_HPP_
#define ANETWORK_HPP_

#include <QtWidgets>
#include <QtCore>
#include <QDialog>
#include <QString>
#include <QList>

class ANetwork {
    public:
        ANetwork();
        ~ANetwork();

    protected:
    private:
        void sendData();
        void getData();
        void CreateNewUser();

};

#endif /* !ANETWORK_HPP_ */
