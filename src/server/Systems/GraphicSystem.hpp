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
        void sendConnect(QString host, quint16 port);

    public slots:
        void onClickSend();
        void OnClickConnect();
        
    private:
        QStringListModel *m_model = nullptr;
        QListView *m_listView = nullptr;
        QLineEdit *m_searchEdit = nullptr;
        QLineEdit *m_messageEdit = nullptr;
        QLineEdit *m_portEdit = nullptr;
        QLineEdit *m_ipEdit = nullptr;
        QLineEdit *portLineEdit = nullptr;
};

#endif /* !GRAPAHICSYSTEM_HPP_ */
