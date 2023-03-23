/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** jsonManager
*/

#ifndef JSONMANAGER_HPP_
#define JSONMANAGER_HPP_

#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>

class JsonManager {
    public:
        JsonManager();
        ~JsonManager();

        void createUser(QString clientAddress);
        void changeStatus(QString clientAddress);

    protected:
    private:
};

#endif /* !JSONMANAGER_HPP_ */
