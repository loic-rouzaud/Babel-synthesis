/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** GrapahicSystem
*/

#include "GraphicSystem.hpp"

GraphicSystem::GraphicSystem(QWidget *parent) : QWidget(parent)
{
    QWidget* widget = dynamic_cast<QWidget*>(this);
    widget->setWindowTitle("SKYPE");

    m_portEdit = new QLineEdit(this);
    m_ipEdit = new QLineEdit(this);
    m_ipEditSearch = new QLineEdit(this);

    QHBoxLayout *addressLayout = new QHBoxLayout();
    addressLayout->addWidget(new QLabel("Adresse IP:"));
    addressLayout->addWidget(m_ipEdit);
    addressLayout->addWidget(new QLabel("Port:"));
    addressLayout->addWidget(m_portEdit);

    auto connectButton = new QPushButton(tr("connect"));
    QHBoxLayout *connectButtonLayout = new QHBoxLayout();
    connectButtonLayout->addWidget(connectButton);

    auto quitButton = new QPushButton(tr("Quit"));
    QHBoxLayout *quitButtonLayout = new QHBoxLayout();
    quitButtonLayout->addWidget(quitButton);

    QHBoxLayout *ipLineEdit = new QHBoxLayout();
    ipLineEdit->addWidget(new QLabel("IP:"));
    ipLineEdit->addWidget(m_ipEditSearch);

    auto searchButton = new QPushButton(tr("Search"));
    QHBoxLayout *searchButtonLayout = new QHBoxLayout();
    searchButtonLayout->addWidget(searchButton);

    QHBoxLayout *sendMessageLayout = new QHBoxLayout();
    sendMessageLayout->addWidget(new QLabel("Message:"));
    m_messageEdit = new QLineEdit(this);
    
    sendMessageLayout->addWidget(m_messageEdit);
    auto sendButton = new QPushButton(tr("Send"));
    sendMessageLayout->addWidget(sendButton);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(addressLayout);
    mainLayout->addLayout(connectButtonLayout);
    mainLayout->addLayout(ipLineEdit);
    mainLayout->addLayout(searchButtonLayout);
    mainLayout->addLayout(sendMessageLayout);
    mainLayout->addLayout(quitButtonLayout);
    setLayout(mainLayout);

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(connectButton, SIGNAL(clicked()), this, SLOT(onClickConnect()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(onClickSend()));
    // connect(searchButton, SIGNAL(clicked()), this, SLOT(ipSearch(m_ipEditSearch->text())));
}

void GraphicSystem::onClickSend()
{
    emit sendMessages(m_messageEdit->text());
}

void GraphicSystem::onClickConnect()
{
    emit sendConnect(m_ipEdit->text(), m_portEdit->text().toInt());
}

// void GraphicSystem::ipSearch(const QString& ip)