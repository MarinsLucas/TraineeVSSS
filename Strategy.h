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
        int direction;
        float deltaTime;
        point2f<int> tamCampo; 
    public: 
        strategy();
        ~strategy();
        Robot* getTeam();        Robot* getRobot(int index);
        void setBola(Bola &b);
        void decision(point2f<int> &campSize, Robot *tR, Bola &bola); //ideia: colocar referência para o outro time
        void goalKepper(Robot &robot, Bola &ball);
        void defender(Robot robot, Bola ball);
        void striker(Robot robot, Bola ball);
        void updateRobot(Robot &robot);
        void setDeltaTime(float dt){deltaTime = dt;};
        void setCentroid(point2f<int> cA, point2f<int> cD, point2f<int> campSize){centroidAtk = cA; centroidDef = cD; setDirection(); tamCampo = campSize; };
        void setDirection(){direction = ((centroidAtk.x - centroidDef.x) > 0) ? 1 : -1;};
        void kick(Robot &robot, Bola &bola);
};

#endif