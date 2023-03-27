/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** GrapahicSystem
*/

#ifndef GRAPAHICSYSTEM_HPP_
#define GRAPAHICSYSTEM_HPP_

#include <QWidget>
#include <QStringListModel>
#include <QDialogButtonBox>
#include <QListView>
#include <QPushButton>
#include <QLineEdit>
#include <QObject>
#include <QHBoxLayout>
#include <QLabel>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QStringList>
#include <iostream>


class GraphicSystem : public QWidget
{
    Q_OBJECT

    public:
        GraphicSystem(QWidget *parent = nullptr);
        ~GraphicSystem();
        void displayJsonFile(const QString &fileName, QListView *listView);

    public slots:
        void refresh(QString clientAddress);
    
    protected:
    private:
};

#endif /* !GRAPAHICSYSTEM_HPP_ */
