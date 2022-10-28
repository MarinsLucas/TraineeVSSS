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

void strategy::goalKepper(Robot &robot, Bola bola)
{
    //Estratégia do Goleiro
    //o goleiro vai de 42 até 86 (área do gol)
  if(!(robot.pos.x))
  if(robot.pos.y > 42 && bola.pos.y < robot.pos.y)
  {
    robot.goal.x = robot.pos.x;
    robot.goal.y = bola.pos.y; 
  } else if(robot.pos.y < 86 && bola.pos.y > robot.pos.y)
  {
    robot.goal.x = robot.pos.x;
    robot.goal.y = bola.pos.y; 
  }
  else
  {
    robot.goal = robot.pos; 
  } 
  robot.goal.x = 120; 
  updateRobot(robot);
}

void strategy::defender(Robot robot, Bola bola)
{
  //Estratégia do zagueiro 
  if((robot.pos.y>86 && robot.pos.y<130) && (robot.pos.x>0 && robot.pos.x<=50))
  {
    //quadrante 1
  }
  else if((robot.pos.y>86 && robot.pos.y<130)&&(robot.pos.x>50 && robot.pos.x<=100))
  {
    //quadrante 2
  }
  else if((robot.pos.y>86 && robot.pos.y<130)&&(robot.pos.x>100 && robot.pos.x<150))
  {
    //quadrante 3
  }
  else if((robot.pos.y>42 && robot.pos.y<=86)&&(robot.pos.x>0 && robot.pos.x<=50))
  {
      //quadrante 4
  }
  else if((robot.pos.y>42 && robot.pos.y<=86)&&(robot.pos.x>50 && robot.pos.x<=100))
  {
      //quadrante 5
  }
  else if((robot.pos.y>42 && robot.pos.y<=86)&&(robot.pos.x>100 && robot.pos.x<150))
  {
      //quadrante 6
  }
  else if((robot.pos.y>0 && robot.pos.y<=42)&&(robot.pos.x>0 && robot.pos.x<=50))
  {
      //quadrante 7
  }
  else if((robot.pos.y>0 && robot.pos.y<=42)&&(robot.pos.x>50 && robot.pos.x<=100))
  {
      //quadrante 8
  }
  else if((robot.pos.y>0 && robot.pos.y<=42) &&(robot.pos.x>100 && robot.pos.x<150))
  {
      //quadrante 9
  }
}

void strategy::striker(Robot robot, Bola ball)
{
    //Estratégia do atacante
  
}

void strategy::decision(point2f<int> campSize, Robot *tr, Bola &bola)
{
    goalKepper(tr[0], bola);
    //defender(tr[0], bola);
    //striker(tr[0], bola);
    

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