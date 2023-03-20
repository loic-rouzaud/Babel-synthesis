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
#include <QListView>
#include <QLineEdit>
#include <QtWidgets>

class GraphicSystem : public QWidget
{
    Q_OBJECT

    public:
        GraphicSystem(QWidget *parent = nullptr);

    private slots:
        void filterList(const QString &text);

    private:
        QStringListModel *m_model;
        QListView *m_listView;
        QLineEdit *m_searchEdit;
        QLineEdit *m_portEdit;
        QLineEdit *m_ipEdit;
        QPushButton *getFortuneButton = nullptr;
        QLineEdit *portLineEdit = nullptr;


};

#endif /* !GRAPAHICSYSTEM_HPP_ */
