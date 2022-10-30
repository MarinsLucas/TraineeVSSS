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

void strategy::goalKepper(Robot &robot, Bola &bola)
{
    //Estratégia do Goleiro
    //o goleiro vai de 42 até 86 (área do gol)
  if(bola.pos.y > 2*tamCampo.y/3) robot.goal.y = 2*tamCampo.y/3;
  else if(bola.pos.y < tamCampo.y/3) robot.goal.y = tamCampo.y/3;
  else if(bola.pos.y < robot.pos.y)
  {
    robot.goal.y = bola.pos.y;   } 
  else if(bola.pos.y > robot.pos.y)
  {
    robot.goal.y = bola.pos.y;   }
  else
  {
    robot.goal = robot.pos; 
  } 
  robot.goal.x = centroidDef.x; 

  //chuta a bola, caso ela esteja próxima o suficiente
  if(dist(robot.pos, bola.pos) < 4) kick(robot, bola);
  
  updateRobot(robot);
}

void strategy::defender(Robot robot, Bola bola)
{
  //Estratégia do zagueiro 
  if((robot.pos.y>86 && robot.pos.y<=130))
  {
    if(robot.pos.x>=0 && robot.pos.x<=tamCampo.x/3)
    {
      cout<<"Quadrante 1" <<endl;
    }
    else if((robot.pos.x>50 && robot.pos.x<=2*tamCampo.x/3))
    {
      cout<<"Quadrante 2"<<endl;
    }
    else
    {
      cout<<"Quadrante 3"<<endl;
    }
  }
  else if((robot.pos.y>42 && robot.pos.y<=86))
  {
    if((robot.pos.x>=0 && robot.pos.x<=tamCampo.x/3))
    {
      cout<<"Quadrante 4"<<endl;
    }
    else if((robot.pos.x>50 && robot.pos.x<=2*tamCampo.x/3))
    {
      cout<<"Quadrante 5"<<endl;
    }
    else
    {
      cout<<"Quadrante 6"<<endl;
    }
  }
  else if((robot.pos.y>=0 && robot.pos.y<=42))
  {
    if((robot.pos.x>=0 && robot.pos.x<=tamCampo.x/3))
    {
      cout<<"Quadrante 7"<<endl;
    }
    else if((robot.pos.x>50 && robot.pos.x<=2*tamCampo.x/3))
    {
      cout<<"Quadrante 8"<<endl;
    }
    else
    {
      cout<<"Quadrante 9"<<endl;

    }
  }

}

void strategy::striker(Robot robot, Bola ball)
{
    //Estratégia do atacante
  
}

void strategy::decision(point2f<int> &campSize, Robot *tR, Bola &bola)
{
    goalKepper(tR[0], bola);
    defender(tR[1], bola);
    //striker(tR[0], bola);
    

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

void strategy::updateRobot(Robot &robot)
{
  robot.velocity.x = angle(robot.pos, robot.goal).x * ROBOT_MAX_VELOCITY;
  robot.velocity.y = angle(robot.pos, robot.goal).y * ROBOT_MAX_VELOCITY; 
  
  robot.pos.x += robot.velocity.x*deltaTime;  
  robot.pos.y += robot.velocity.y*deltaTime; 
}

void strategy::kick(Robot &robot, Bola &bola)
{
  //cout<<"OLHA O CHUUTE"<<endl; 
  
  bola.velocity.y = angle(robot.pos, bola.pos).x * 10;
  bola.velocity.x = angle(robot.pos, bola.pos).y * 10;
}