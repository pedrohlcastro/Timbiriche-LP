#ifndef LINEBUTTON_H
#define LINEBUTTON_H
#include <QPushButton>

class LineButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(Qt::Orientation mode READ mode WRITE setMode NOTIFY modeChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

public:
    explicit LineButton(QWidget *parent = 0);
    virtual ~LineButton();
    Qt::Orientation mode() const{ return m_mode; } //get do mode
    QColor color() const { return m_color; }
signals:
    void modeChanged(Qt::Orientation mode); //signal de quando o modo for alterado
    void colorChanged(QColor color);
public slots:
    void setMode(Qt::Orientation mode); //set do mode
    void setColor(QColor color); //set do mode
    void reset(); //reset color
private:
    Qt::Orientation m_mode; //0 - Hor 1- Ver
    QColor m_color;
private slots:
    void updateStyleSheet();

};

#endif // LINEBUTTON_H
