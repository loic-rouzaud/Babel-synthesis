/*
** EPITECH PROJECT, 2023
** Babel-synthesis
** File description:
** GrapahicSystem
*/

#ifndef GRAPAHICSYSTEM_HPP_
#define GRAPAHICSYSTEM_HPP_

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE

class GraphicSystem : public QWidget {
    Q_OBJECT

    public:
        GraphicSystem(QWidget *parent = nullptr);
        ~GraphicSystem();

    private:
        QLineEdit *nameLine;
        QTextEdit *addressText;
};

#endif /* !GRAPAHICSYSTEM_HPP_ */
