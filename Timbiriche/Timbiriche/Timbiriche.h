#ifndef TIMBIRICHE_H
#define TIMBIRICHE_H

#include <QMainWindow>

namespace Ui {
class Timbiriche;
}

class Timbiriche : public QMainWindow
{
    Q_OBJECT

public:
    explicit Timbiriche(QWidget *parent = 0);
    ~Timbiriche();
    bool player = false;
    int jogo[7][4]; //jogo

private:
    Ui::Timbiriche *ui;
private slots:
    void handleButton();
};

#endif // TIMBIRICHE_H
