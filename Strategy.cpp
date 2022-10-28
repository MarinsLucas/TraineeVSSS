#include <iostream>
#include "Strategy.h"


using namespace std;

strategy::strategy(){
    teamRobots[0].pos.x = 100;
    teamRobots[1].pos.x = 100;
    teamRobots[2].pos.x = 100;

    teamRobots[0].pos.y = 75;
    teamRobots[1].pos.y = 50;
    teamRobots[2].pos.y = 100; 

    teamRobots[0].index = 1; 
    teamRobots[1].index = 2; 
    teamRobots[2].index = 3;
}

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
    //Estratégia do zagueiro
}

void strategy::striker(Robot robot, Bola ball)
{
    //Estratégia do atacante
}

void strategy::decision(point2f<int> campSize, Robot *tr, Bola &bola)
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

Robot* strategy::getTeam()
{
    return teamRobots; 
}

Robot* strategy::getRobot(int index)
{
  return &teamRobots[index];
}