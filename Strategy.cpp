#include "Strategy.h"
#include <iostream>

using namespace std;

strategy::strategy(){}

strategy::~strategy(){}

void strategy::setBola(Bola &b)
{
    bola = &b; 
}

void strategy::goalKepper(Robot robot, Bola bola)
{
    //Estratégia do Goleiro
}

void strategy::defender(Robot robot, Bola bola)
{
    //Estratégiad o zagueiro
}

void strategy::striker(Robot robot, Bola ball)
{
    //Estratégia do atacante
}

void strategy::decision(point2f campSize, Robot *tr, Bola &bola)
{
    goalKepper(tr[0], bola);
    defender(tr[0], bola);
    striker(tr[0], bola);
    

    //Verifica as posições dos jogadores, para que não saiam do campo
    for(auto robot : teamRobots)
    {
        if(robot.pos.x > campSize.x)
        {
            robot.pos.x = campSize.x;
        }
        else if(robot.pos.x < 0)
        {
            robot.pos.x = 0; 
        }

        if(robot.pos.y > campSize.y)
        {
            robot.pos.x =  campSize.x;
        }
        else if(robot.pos.y < 0)
        {
            robot.pos.y = 0 ; 
        }
    }

    
}