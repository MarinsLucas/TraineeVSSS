#ifndef STRATEGY_H
#define STRATEGY_H

#include "Util.h"
#include "Jogo.h"

using namespace std;

class strategy : util
{
    private:
        Robot teamRobots[3];
        Bola *bola;
        point2f centroidAtk, centroidDef; 
    public:
        strategy();
        ~strategy();
        void setBola(Bola &b);
        void decision(point2f campSize, Robot *tR, Bola &bola); //ideia: colocar referência para o outro time
        void goalKepper(Robot robot, Bola ball);
        void defender(Robot robot, Bola ball);
        void striker(Robot robot, Bola ball);
};

#endif