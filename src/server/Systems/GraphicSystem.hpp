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

class GraphicSystem : public QWidget
{
    Q_OBJECT

    public:
        GraphicSystem(QWidget *parent = nullptr);

    signals:
        void sendMessages(QString message);

    private slots:
        void filterList(const QString &text);

    public slots:
        void onClickSend();
        

    private:
        QStringListModel *m_model;
        QListView *m_listView;
        QLineEdit *m_searchEdit;
        QLineEdit *m_messageEdit;
        QLineEdit *m_portEdit;
        QLineEdit *m_ipEdit;
        QLineEdit *portLineEdit = nullptr;
};

#endif /* !GRAPAHICSYSTEM_HPP_ */
