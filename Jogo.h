#ifndef JOGO_H
#define JOGO_H

#include "Strategy.h"

using namespace std;

struct Placar{
  short a; 
  short b;
};

struct Bola{
  point2f pos;
  point2f velocity;
  float sin;
}; 

class Jogo{
  private:
    point2f campo;
    strategy time_1;
    strategy time_2;
    Placar placar;
    int criterioParada;
    Bola bola;
    float atrito; 
    

  public:
    Jogo(int cP, int cAlt, int cLarg, float kat, Bola b);
    ~Jogo();
    bool checkState(Placar atual);
    void gameOver(); 
    void uptadeBall(float deltaTime);
    bool attackFault(strategy time);
    bool defenseFault(strategy time);
    
    void run();
};

 #endif