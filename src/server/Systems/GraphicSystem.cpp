/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** GrapahicSystem
*/

#include "GraphicSystem.hpp"

GraphicSystem::GraphicSystem(QWidget *parent) : QWidget(parent)
{
    QListView *listView = new QListView();
    displayJsonFile("DataBase.json", listView);
    if (listView->isVisible()) {
        std::cout << "refreshing" << std::endl;
        listView->close();
        QListView *listView = new QListView();
        displayJsonFile("DataBase.json", listView);
        listView->show();
    } else {
        displayJsonFile("DataBase.json", listView);
        listView->show();
    }
}

GraphicSystem::~GraphicSystem()
{
}

void GraphicSystem::displayJsonFile(const QString& fileName, QListView* listView)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: Could not open file" << fileName;
        return;
    }
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull()) {
        qDebug() << "Error: Failed to parse JSON data from file" << fileName;
        return;
    }

    QStringList stringList;
    QJsonArray jsonArray = jsonDoc.array();
    for (int i = 0; i < jsonArray.size(); ++i) {
        QJsonObject jsonObj = jsonArray.at(i).toObject();
        QString name = jsonObj.keys().at(0);
        bool isConnected = jsonObj["isConnected"].toBool();
        QString connectionStatus = isConnected ? "Connected" : "Not Connected";
        stringList.append(name + ": " + connectionStatus);
    }
    QStringListModel* model = new QStringListModel(stringList, listView);
    listView->setModel(model);
}

void GraphicSystem::refresh(QString clientAddress)
{
    GraphicSystem();
}