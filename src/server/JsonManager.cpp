/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** jsonManager
*/

#include "JsonManager.hpp"

JsonManager::JsonManager()
{
}

JsonManager::~JsonManager()
{
}

void JsonManager::createUser(QString clientAddress)
{
    QFile jsonFile("DataBase.json");
    jsonFile.open(QIODevice::ReadWrite | QIODevice::Text);

    QJsonDocument jsonDoc;
    if (!jsonFile.isOpen() || jsonFile.size() == 0) {
        QJsonObject jsonObject;
        jsonObject[QString("ipAddress1")] = clientAddress;
        jsonObject[QString("isConnected")] = true;

        QJsonArray jsonArray;
        jsonArray.append(jsonObject);
        jsonDoc = QJsonDocument(jsonArray);
    } else {
        QByteArray jsonData = jsonFile.readAll();
        QJsonDocument jsonDocExisting = QJsonDocument::fromJson(jsonData);

        QJsonArray jsonArrayExisting = jsonDocExisting.array();
        int index = -1;
        for (int i = 0; i < jsonArrayExisting.size(); i++) {
            QJsonObject obj = jsonArrayExisting[i].toObject();
            if (obj["ipAddress" + QString::number(i+1)] == clientAddress) {
                index = i;
                if (!obj["isConnected"].toBool()) {
                    obj["isConnected"] = true;
                    jsonArrayExisting.replace(i, obj);
                }
                break;
            }
        }

        QJsonObject jsonObject;
        if (index < 0) {
            int count = jsonArrayExisting.size() + 1;
            jsonObject[QString("ipAddress") + QString::number(count)] = clientAddress;
            jsonObject[QString("isConnected")] = true;
            jsonArrayExisting.append(jsonObject);
        }
        jsonDoc = QJsonDocument(jsonArrayExisting);
    }
    jsonFile.resize(0);
    jsonFile.write(jsonDoc.toJson());
    jsonFile.close();
}

void JsonManager::changeStatus(QString clientAddress)
{
    QFile jsonFile("DataBase.json");
    jsonFile.open(QIODevice::ReadWrite | QIODevice::Text);

    QJsonDocument jsonDoc;
    if (!jsonFile.isOpen() || jsonFile.size() == 0) {
        jsonFile.close();
        return;
    } else {
        QByteArray jsonData = jsonFile.readAll();
        QJsonDocument jsonDocExisting = QJsonDocument::fromJson(jsonData);

        QJsonArray jsonArrayExisting = jsonDocExisting.array();
        for (int i = 0; i < jsonArrayExisting.size(); i++) {
            QJsonObject obj = jsonArrayExisting[i].toObject();
            if (obj["ipAddress" + QString::number(i+1)] == clientAddress) {
                obj["isConnected"] = false;
                jsonArrayExisting[i] = obj;
                break;
            }
        }
        jsonDoc = QJsonDocument(jsonArrayExisting);
    }
    jsonFile.resize(0);
    jsonFile.write(jsonDoc.toJson());
    jsonFile.close();
}

