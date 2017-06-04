#include "LineButton.h"

LineButton::LineButton(QWidget *parent) : QPushButton(parent), m_mode(Qt::Vertical),m_color(Qt::transparent) //inicia o modo em HORIZONTAL
{
    this->updateStyleSheet();
}


LineButton::~LineButton(){

}

void LineButton::updateStyleSheet(){
    QString rgba= m_color.name(QColor::HexArgb);

    this->setStyleSheet(QString("\
               QPushButton { \
                   border: 0px solid transparent; \
               } \
               QPushButton[mode=\"1\"] { \
                   border-top-width: 15px; \
               } \
               QPushButton[mode=\"2\"] { \
                   border-left-width: 15px; \
               } \
               QPushButton:hover { \
                   border-image: url(':/dotts'); \
               } \
               QPushButton[mode=\"1\"]:!enabled { \
                  border-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,       \
                                stop:0 white, stop: 0.2 white, stop: 0.5 %1,  \
                                stop: 0.8 white, stop:1 white);               \
                }                                                              \
               QPushButton[mode=\"2\"]:!enabled { \
                   border-color: %1; \
               } \
               QPushButton[mode=\"2\"]:!enabled { \
               border-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,        \
                               stop:0 white, stop: 0.2 white, stop: 0.5 %1, \
                               stop: 0.8 white, stop:1 white);              \
               }\
    ").arg(rgba));
}
void LineButton::reset(){
    this->setColor(Qt::transparent);
    this->setEnabled(true);
}
void LineButton::setMode(Qt::Orientation mode){
    if(mode != m_mode){
        m_mode = mode;
        emit modeChanged(m_mode); //emite a mudança de valor, esse metodo e implementado auto pelo QT
    }
}

void LineButton::setColor(QColor color){
    if(color != m_color){
        m_color = color;
        emit colorChanged(color);
        this->setEnabled(false);
        this->updateStyleSheet();
    }
}

