#ifndef STRATEGY_H
#define STRATEGY_H

#include "Util.h"

using namespace std;

class strategy : public util
{
    private:
        Robot teamRobots[3];
        Bola *bola;
        point2f<int> centroidAtk, centroidDef; 
    public:
        strategy();
        ~strategy();
        Robot* getTeam();        Robot* getRobot(int index);
        void setBola(Bola &b);
        void decision(point2f<int> campSize, Robot *tR, Bola &bola); //ideia: colocar referência para o outro time
        void goalKepper(Robot robot, Bola ball);
        void defender(Robot robot, Bola ball);
        void striker(Robot robot, Bola ball);
};

#endif