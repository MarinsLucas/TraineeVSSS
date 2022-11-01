#ifndef JOGO_H
#define JOGO_H

#include "Strategy.h"
#include "pbPlots.hpp"
#include "supportLib.hpp"

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
    bool printFrameByFrame; 
  public:
    Jogo(int cP, int cAlt, int cLarg, float kat, point2f<float> b, bool bFbF, strategy &time1, strategy &time2);
    ~Jogo();
    bool checkState(Placar atual);
    void gameOver(); 
    void uptadeBall(float deltaTime);
    bool attackFault(strategy time);
    bool defenseFault(strategy time);
    void run();
    void resetInitialPos();
    void printFrame();
    void restartJogo();
    void goal();
};

 #endif