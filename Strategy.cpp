#include <iostream>
#include "Strategy.h"


using namespace std;

strategy::strategy(){
    teamRobots[0].pos.x = 75;
    teamRobots[1].pos.x = 75;
    teamRobots[2].pos.x = 75;

    teamRobots[0].pos.y = 65;
    teamRobots[1].pos.y = 65;
    teamRobots[2].pos.y = 65; 

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
	float horizontalDist = abs(dist(centroidDef, bola.pos) * angle(centroidDef, bola.pos).x);
	
	if(horizontalDist < tamCampo.x/3)
	{
  	if(bola.pos.y > 2*tamCampo.y/3) 
				robot.goal.y = 2*tamCampo.y/3;
	  else if(bola.pos.y < tamCampo.y/3) 
				robot.goal.y = tamCampo.y/3;
	  else if(bola.pos.y < robot.pos.y)
	  {
	    robot.goal.y = bola.pos.y;   
		}
	  else if(bola.pos.y > robot.pos.y)
	  {
	    robot.goal.y = bola.pos.y;   }
	  else
	  {
	    robot.goal = robot.pos; 
	  } 
	  robot.goal.x = centroidDef.x; 
	}
	else
	{
		robot.goal.x = centroidDef.x + direction*15; 
		robot.goal.y = tamCampo.y/2;
	}
  //chuta a bola, caso ela esteja próxima o suficiente
  if(dist(robot.pos, bola.pos) < 5) kick(robot, bola);
  
  updateRobot(robot);
}

void strategy::defender(Robot &robot, Bola &bola)
{
	float horizontalDist = abs(dist(centroidDef, bola.pos) * angle(centroidDef, bola.pos).x);
	
	//Line for debugging
	//cout<<horizontalDist<<endl; 
	
  //Estratégia do zagueiro 
	if ((horizontalDist >= 0 && horizontalDist < tamCampo.x/3) || (horizontalDist >= tamCampo.x/3 && horizontalDist<2*tamCampo.x/3))
	{
		//Nessa linha, eu acho interessante ele evitar entrar dentro da área do gol. 
		//Se manter sempre de maneira com que robot.pox.x < bola.pos.x -> para caso ele vá chutar, ele chute para frente. 
		cout<<"Quadrante 1, 2, 5, 7, 8"<<endl;
    
		//Ele tem que entrar na frente da bola		

		if(bola.pos.y < tamCampo.y/3)
		{
			//Quadrante 1,2,3
			robot.goal.x = (bola.pos.x - direction*2);
			robot.goal.y = bola.pos.y + 5;
			if(dist(robot.pos, bola.pos)<10 && robot.pos.x*direction < bola.pos.x*direction && bola.pos.y < robot.pos.y) kick(robot, bola);
		} else if( bola.pos.y > 2*tamCampo.y/3)
		{
			//Quadrante 7,8,9
			robot.goal.x = (bola.pos.x - direction*2);
			robot.goal.y = bola.pos.y - 5;
			if(dist(robot.pos, bola.pos)<10 && robot.pos.x*direction < bola.pos.x*direction && bola.pos.y > robot.pos.y) kick(robot, bola);
		}
		else
		{
			robot.goal.x = (bola.pos.x + bola.velocity.x*deltaTime - direction*2);
			robot.goal.y = bola.pos.y + bola.velocity.y*deltaTime;
			if(dist(robot.pos, bola.pos)<10 && robot.pos.x*direction < bola.pos.x*direction) kick(robot, bola);
		}
		cout<<"Quadrante 2, 5, 8"<<endl;

				
		if((bola.pos.y>tamCampo.y/3 && bola.pos.y<=2*tamCampo.y/3))
		{
			cout<<"Quadrante 4"<<endl;
			if(robot.goal.x <= 15)
			{
				//robo sai do meio
				robot.goal.x = 15; 
				
				if(bola.pos.x < 15)
				{
					robot.pos.y = bola.pos.y + 4;
				}
			}
		}
	}
	else if(horizontalDist > 2*tamCampo.x/3 && horizontalDist <= tamCampo.x)
  {
    cout<<"Quadrante 3, 6 ou 9"<<endl; 
		if(bola.pos.y < tamCampo.y/3)
		{
		//Quadrante 1,2,3
		robot.goal.x = (bola.pos.x + bola.velocity.x*deltaTime - direction*2);
		robot.goal.y = bola.pos.y + bola.velocity.y*deltaTime + 2;
		if(dist(robot.pos, bola.pos)<10 && robot.pos.x*direction < bola.pos.x*direction && bola.pos.y> robot.pos.y) kick(robot, bola);
		} else if( bola.pos.y > 2*tamCampo.y/3)
		{
		//Quadrante 7,8,9
		robot.goal.x = (bola.pos.x + bola.velocity.x*deltaTime - direction*2);
		robot.goal.y = bola.pos.y + bola.velocity.y*deltaTime -2;
			if(dist(robot.pos, bola.pos)<10 && robot.pos.x*direction < bola.pos.x*direction && bola.pos.y < robot.pos.y) kick(robot, bola);
		} 	
		else
		{
			robot.goal.x = bola.pos.x + bola.velocity.x*deltaTime - direction*2;
			robot.goal.y = bola.pos.y + bola.velocity.x*deltaTime*1.5; 
			if(dist(robot.pos, bola.pos)<10 && robot.pos.x*direction < bola.pos.x*direction) kick(robot, bola);
		}
	} 

	

	updateRobot(robot);
}

void strategy::striker(Robot &robot, Bola &bola)
{
	float horizontalDist = abs(dist(centroidDef, bola.pos) * angle(centroidDef, bola.pos).x);

	if(horizontalDist > 0 && horizontalDist < tamCampo.x/3)
	{
	  //atacante descansando
	  robot.goal.x = robot.pos.x;
    robot.goal.y = bola.pos.y + bola.velocity.y * deltaTime;
		cout<<"Quadrante 1, 4, 7"<<endl;
	}
    
	else if(horizontalDist > tamCampo.x/3 && horizontalDist<2*tamCampo.x/3)
	{

		if(bola.pos.y < tamCampo.y/3 || bola.pos.y > 2*tamCampo.y/3)
		{
			//Quadrante oito ou 2
			robot.goal.x = bola.pos.x;
			robot.goal.y = tamCampo.y/2;
		} else
		{
			//Quadrante 5
			robot.goal.x = (bola.pos.x + bola.velocity.x*deltaTime - direction*2);
			robot.goal.y = bola.pos.y + bola.velocity.y *deltaTime; 
		}
    
		cout<<"Quadrante 2, 5, 8"<<endl;
	}
	else if(horizontalDist > 2*tamCampo.x/3 && horizontalDist < tamCampo.x)	
	{
    	if(bola.pos.y < tamCampo.y/3 || bola.pos.y > 2*tamCampo.y/3)
		{
			//Quadrante oito ou 9
			robot.goal.x = bola.pos.x;
			robot.goal.y = tamCampo.y/2;
		} else
		{
			//Quadrante 6
			robot.goal.x = (bola.pos.x + bola.velocity.x*deltaTime - direction*2);
			robot.goal.y = bola.pos.y + bola.velocity.y *deltaTime; 
		}

		if(bola.pos.x*direction > centroidAtk.x - direction*15)
		{
			robot.goal.x = centroidAtk.y - direction*15; 
		}
		cout<<"Quadrante 3, 6, 9"<<endl;
	}
	
if(dist(robot.pos, bola.pos)<10 && robot.pos.x*direction < bola.pos.x*direction) kick(robot, bola);
updateRobot(robot);
}

void strategy::decision(point2f<int> &campSize, Robot *tR, Bola &bola)
{
    goalKepper(tR[0], bola);
	defender(tR[1], bola);
    striker(tR[2], bola);    

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
	//float vel = ((dist(robot.pos, robot.goal)/deltaTime > ROBOT_MAX_VELOCITY) ? ROBOT_MAX_VELOCITY : dist(robot.pos,robot.goal));
  robot.velocity.x = angle(robot.pos, robot.goal).x * ((dist(robot.pos, robot.goal)/deltaTime > ROBOT_MAX_VELOCITY) ? ROBOT_MAX_VELOCITY : dist(robot.pos,robot.goal));
  robot.velocity.y = angle(robot.pos, robot.goal).y * ((dist(robot.pos, robot.goal)/deltaTime > ROBOT_MAX_VELOCITY) ? ROBOT_MAX_VELOCITY : dist(robot.pos,robot.goal)); 
	
  robot.pos.x += robot.velocity.x*deltaTime;   
  robot.pos.y += robot.velocity.y*deltaTime; 

	if(robot.pos.x > tamCampo.x)
	{
		robot.pos.x = tamCampo.x;
		robot.velocity.x = 0;
	}
	else if(robot.pos.x < 0.1)
	{
		robot.pos.x = 0.1;
		robot.velocity.x = 0;
	}

	if(robot.pos.y > tamCampo.y)
	{
		robot.pos.y = tamCampo.y;
		robot.velocity.y = 0;
	}
	else if(robot.pos.y < 0.1)
	{
		robot.pos.y = 0.1;
		robot.velocity.y = 0;
	}
}

void strategy::kick(Robot &robot, Bola &bola)
{
  cout<<"OLHA O CHUUTE"<<endl; 
  
  bola.velocity.y = angle(robot.pos, bola.pos).y * 20;
  bola.velocity.x = angle(robot.pos, bola.pos).x * 20;
}

void strategy::setInitialPos(vector<point2f<float>> iPos)
{
	initialPos[0] = iPos.at(0);
	initialPos[1] = iPos.at(1);
	initialPos[2] = iPos.at(2);
};

void strategy::resetInitialPos()
{
	teamRobots[0].pos = initialPos[0];
	teamRobots[1].pos = initialPos[1];
	teamRobots[2].pos = initialPos[2];
}
