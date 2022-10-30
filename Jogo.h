#ifndef JOGO_H
#define JOGO_H

#include "Strategy.h"

using namespace std;

class Jogo{
  private:
    point2f<int> campo;
    strategy time_1;
    strategy time_2;
    Placar placar;
    int criterioParada;  // quantidade máxima de gols
    Bola bola;      //Bola
    float atrito;   //coeficiente de atrito entre bola e campo
  public:
    Jogo(int cP, int cAlt, int cLarg, float kat, point2f<float> b);
    ~Jogo();
    bool checkState(Placar atual);
    void gameOver(); 
    void uptadeBall(float deltaTime);
    bool attackFault(strategy time);
    bool defenseFault(strategy time);
    void run();
};

 #endif