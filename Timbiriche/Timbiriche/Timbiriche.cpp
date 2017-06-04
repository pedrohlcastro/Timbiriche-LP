#include "Timbiriche.h"
#include "ui_Timbiriche.h"

#include <QDebug>
#include <bits/stdc++.h>

Timbiriche::Timbiriche(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Timbiriche)
{
    ui->setupUi(this);

    for(int i = 0; i < 7; i++){
        for(int j=0; j < 4; j++){
            LineButton* b = this->findChild<LineButton*>(QString("line%1%2").arg(i).arg(j));
            if(b){
                QObject::connect(b, SIGNAL(clicked(bool)),this,SLOT(handleButton()) );
                QObject::connect(ui->actionNovo,SIGNAL(triggered(bool)),b,SLOT(reset()));
            }
        }

    }
    QObject::connect(ui->actionSaida,SIGNAL(triggered(bool)),qApp,SLOT(quit()));
    memset(this->jogo,0,sizeof(this->jogo));
}

Timbiriche::~Timbiriche()
{
    delete ui;
}

void Timbiriche::handleButton(){
    static int player1=0,player2=0;
    LineButton *button = qobject_cast<LineButton*>(QObject::sender());
    std::string nome = button->objectName().toUtf8().constData();
    int linha = (char)nome[4] - '0';
    int coluna = nome[5] - '0';
    int linhaAcima = linha - 1;
    int linhaBaixo = linha + 1;
    int colunaEsq = coluna - 1;
    int colunaDir = coluna + 1;
    int testeEsq = 0;
    int testeDir = 0;
    int labelI,labelJ;
    this->jogo[linha][coluna] = 1;
    if(button->mode() == Qt::Vertical){
        if(this->jogo[linha][colunaEsq] == 1 && colunaEsq >= 0) testeEsq++;
        if(this->jogo[linhaAcima][colunaEsq] == 1 && colunaEsq >= 0 && linhaAcima >= 0) testeEsq++;
        if(this->jogo[linhaBaixo][colunaEsq] == 1 && colunaEsq >= 0 && linhaBaixo < 7) testeEsq++;

        if(this->jogo[linha][colunaDir] == 1 && colunaDir < 7) testeDir++;
        if(this->jogo[linhaBaixo][coluna] == 1 && linhaBaixo < 7) testeDir++;
        if(this->jogo[linhaAcima][coluna] == 1 && linhaAcima >= 0) testeDir++;
        if(testeDir == 3){
            labelI = linha;
            labelJ = coluna + 1;
        }
        if(testeEsq == 3){
            labelI = linha;
            labelJ = coluna;
        }
    }
    else{
        if(this->jogo[linhaBaixo][coluna] == 1 && linhaBaixo < 7) testeDir++;
        if(this->jogo[linhaBaixo + 1][coluna] == 1 && (linhaBaixo +1) < 7) testeDir++;
        if(this->jogo[linhaBaixo][colunaDir] == 1 && linhaBaixo < 7 && colunaDir < 7) testeDir++;

        if(this->jogo[linhaAcima][coluna] == 1 && linhaAcima >= 0) testeEsq++;
        if(this->jogo[linhaAcima -1][coluna] == 1 && (linhaAcima - 1) >= 0) testeEsq++;
        if(this->jogo[linhaAcima][colunaDir] == 1 && linhaAcima >= 0 && colunaDir < 7) testeEsq++;
        if(testeDir == 3){
            labelI = linha + 1;
            labelJ = coluna + 1;
        }
        if(testeEsq == 3){
            labelI = linha - 1;
            labelJ = coluna + 1;
        }
    }
    //pontuacao e set label
    if(this->player && (testeDir == 3 || testeEsq == 3)){
        player1++;
        //tem que setar o box na posicao labelI,labelJ
    }
    if(!this->player && (testeDir == 3 || testeEsq == 3)){
        player2++;
        //tem que setar o box na posicao labelI,labelJ
    }

    if(this->player){
        button->setColor(Qt::blue);
    }

    qDebug() << "PLAYER 1: " << player1 << " -- PLAYER 2: " << player2 << endl;
    if(!this->player) button->setColor(Qt::red);
    if(testeEsq != 3 && testeDir != 3)this->player = !this->player;
}
