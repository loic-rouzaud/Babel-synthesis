/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** GrapahicSystem
*/

#include "GraphicSystem.hpp"
#include <QLineEdit>
#include <QHBoxLayout>
#include <QLabel>

GraphicSystem::GraphicSystem(QWidget *parent) : QWidget(parent), getFortuneButton(new QPushButton(tr("Push")))
{
    setWindowTitle("SKYPE");

    m_model = new QStringListModel(this);
    QStringList names;
    names << "Contact1" << "Contact2" << "Contact3";
    m_model->setStringList(names);

    m_listView = new QListView(this);
    m_listView->setModel(m_model);

    m_searchEdit = new QLineEdit(this);
    m_portEdit = new QLineEdit(this);
    m_ipEdit = new QLineEdit(this);

    QHBoxLayout *addressLayout = new QHBoxLayout();
    addressLayout->addWidget(new QLabel("Adresse IP:"));
    addressLayout->addWidget(m_ipEdit);
    addressLayout->addWidget(new QLabel("Port:"));
    addressLayout->addWidget(m_portEdit);

    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchLayout->addWidget(new QLabel("Rechercher:"));
    searchLayout->addWidget(m_searchEdit);
    
    auto quitButton = new QPushButton(tr("Quit"));
    auto buttonBox = new QDialogButtonBox;
    connect(quitButton, &QAbstractButton::clicked, this, &QWidget::close);
    QHBoxLayout *quitButtonLayout = new QHBoxLayout();
    quitButtonLayout->addWidget(quitButton);

    auto connect = new QPushButton(tr("Connect"));
    auto buttonBox = new QDialogButtonBox;
    connect(quitButton, &QAbstractButton::clicked, this, &QWidget::close);
    QHBoxLayout *quitButtonLayout = new QHBoxLayout();
    quitButtonLayout->addWidget(quitButton);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(searchLayout);
    mainLayout->addLayout(addressLayout);
    mainLayout->addWidget(m_listView);
    mainLayout->addLayout(quitButtonLayout);
    setLayout(mainLayout);

    connect(m_searchEdit, &QLineEdit::textChanged, this, &GraphicSystem::filterList);
}

void GraphicSystem::filterList(const QString &text)
{
    QStringList names = m_model->stringList();
    names = names.filter(text, Qt::CaseInsensitive);
    m_model->setStringList(names);
}
