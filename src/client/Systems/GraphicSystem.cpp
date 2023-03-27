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

    m_model = new QStringListModel(this);
    QStringList names;
    m_model->setStringList(names);

    m_listView = new QListView(this);
    m_listView->setModel(m_model);

    m_portEdit = new QLineEdit(this);
    m_ipEdit = new QLineEdit(this);

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

    QHBoxLayout *sendMessageLayout = new QHBoxLayout();
    sendMessageLayout->addWidget(new QLabel("Message:"));
    m_messageEdit = new QLineEdit(this);
    
    sendMessageLayout->addWidget(m_messageEdit);
    auto sendButton = new QPushButton(tr("Send"));
    sendMessageLayout->addWidget(sendButton);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(addressLayout);
    displayFileData("../server/DataBase.json");
    mainLayout->addLayout(connectButtonLayout);
    mainLayout->addWidget(m_listView);
    mainLayout->addLayout(quitButtonLayout);
    mainLayout->addLayout(sendMessageLayout);
    setLayout(mainLayout);

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(connectButton, SIGNAL(clicked()), this, SLOT(OnClickConnect()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(onClickSend()));
}

void GraphicSystem::onClickSend()
{
    emit sendMessages(m_messageEdit->text());
}

void GraphicSystem::OnClickConnect()
{
    emit sendConnect(m_ipEdit->text(), m_portEdit->text().toInt());
}

void GraphicSystem::displayFileData(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: Could not open file" << fileName;
        return;
    }

    QStringList names;
    QByteArray fileData = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    if (!jsonDoc.isArray()) {
        qDebug() << "Error: Invalid JSON file format" << fileName;
        return;
    }

    QJsonArray jsonArray = jsonDoc.array();
    for (int i = 0; i < jsonArray.size(); ++i) {
        QJsonObject jsonObj = jsonArray.at(i).toObject();
        QString name = jsonObj["name"].toString();
        names.append(name);
    }

    m_model = new QStringListModel(names, this);
    m_listView->setModel(m_model);
}