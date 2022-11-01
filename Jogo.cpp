#include <iostream>
#include "Jogo.h"

Jogo::Jogo(int cP, int cAlt, int cLarg, float kat, point2f<float> b, bool bFbF)
{
    //Configuração do critério de parada
    criterioParada = cP;

    //Configuração do campo
    campo.x = cLarg;
    campo.y = cAlt;

    //Configuração de placar
    placar.a = 0;
    placar.b = 0;

    //Configuração da bola
    bola.pos.x = b.x; 
    bola.pos.y = b.y;
    bola.velocity.x = 0; 
    bola.velocity.y = 0;
    point2f<float> c1,c2; 
  
    c1.x = 0;
    c1.y = 65; 
    c2.x = 150; 
    c2.y = 65; 

		//Configuração do time
    time_1.setCentroid(c1, c2, campo);
    time_2.setCentroid(c2,c1, campo);
    
    //Configuração do coeficiente de atrito
    atrito = 9.82*kat; 
    time_1.setDeltaTime(0.5);
    time_2.setDeltaTime(0.5);

    //print frameByFrame
    printFrameByFrame = bFbF;

}

Jogo::~Jogo()
{
        //~Util time2
}

void Jogo::printFrame()
{
  bool success;
  StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
  RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
  imageReference->image = CreateImage(1080, 720, GetWhite());

  vector<double> xs{time_1.getRobot(0)->pos.x, time_1.getRobot(1)->pos.x, time_1.getRobot(2)->pos.x};
  vector<double> ys{time_1.getRobot(0)->pos.y, time_1.getRobot(1)->pos.y, time_1.getRobot(2)->pos.y};

  //imprime time 1
  success = DrawScatterPlot(imageReference, 1080, 720, &xs, &ys, errorMessage, CreateRGBColor(1.0 , 0.0 , 0.0));

  //imprime time 2
  xs = {time_2.getRobot(0)->pos.x, time_2.getRobot(1)->pos.x, time_2.getRobot(2)->pos.x};
  ys = {time_2.getRobot(0)->pos.y, time_2.getRobot(1)->pos.y, time_2.getRobot(2)->pos.y};
  success = DrawScatterPlot(imageReference, 1080, 720, &xs, &ys, errorMessage, CreateRGBColor(0.0 , 0.0 , 1.0));
  
  //imprime bola
  xs = {bola.pos.x};
  ys = {bola.pos.y};
  success = DrawScatterPlot(imageReference, 1080, 720, &xs, &ys, errorMessage, CreateRGBColor(0.0 , 0.0 , 0.0));

  if(success){
  vector<double> *pngdata = ConvertToPNG(imageReference->image);
  WriteToFile(pngdata, "example1.png");
  DeleteImage(imageReference->image);
  }else{
    cerr << "Error: ";
    for(wchar_t c : *errorMessage->string){
      wcerr << c;
    }
    cerr << endl;
  }

	FreeAllocations();
}

void Jogo::run()
{
  time_1.decision(campo, time_1.getTeam(), bola);
  time_2.decision(campo, time_2.getTeam(), bola);

  cout<<"Time 1"<<endl;
  Robot *robot;
  for(int i =0; i< 3;i++)
  {
      robot =time_1.getRobot(i);
      cout<<"Robo "<<robot->index<<":\nPos: ("<< robot->pos.x<<","<<robot->pos.y<<")\nGoal: ("<<robot->goal.x<<","<<robot->goal.y<<")"<<endl<<endl;
  }

  cout<<"Time 2"<<endl;
  for(int i =0; i< 3;i++)
  {
      robot =time_2.getRobot(i);
      cout<<"Robo "<<robot->index<<":\nPos: ("<< robot->pos.x<<","<<robot->pos.y<<")\nGoal: ("<<robot->goal.x<<","<<robot->goal.y<<")"<<endl<<endl;
  }
  
  //delete robot; 

  cout<<"Posição Bola: (" << bola.pos.x << "," << bola.pos.y << ")" << endl;
  cout<<"Velocidade Bola: ("<<bola.velocity.x <<","<<bola.velocity.y<<")"<<endl;
  
  uptadeBall(0.5);

  if(checkState(placar))
  {
      gameOver();
  }
  
  if(printFrameByFrame)
    printFrame();
  
  return;
}

bool Jogo::checkState(Placar atual)
{
    if(atual.a >= criterioParada || atual.b >= criterioParada)  
        return true; 
    else
        return false; 
}

void Jogo::gameOver()
{
    //fim de jogo
}

void Jogo::uptadeBall(float deltaTime)
{
    bola.pos.x += bola.velocity.x * deltaTime;
    bola.pos.y += bola.velocity.y * deltaTime;
    bola.velocity.x -= atrito * deltaTime * ((bola.velocity.x > 0) ? 1 : ((bola.velocity.x < 0) ? -1 : 0));
    bola.velocity.y -= atrito * deltaTime * ((bola.velocity.y > 0) ? 1 : ((bola.velocity.y < 0) ? -1 : 0));

    if(abs(bola.velocity.x) < 0.3)
        bola.velocity.x = 0;
    if(abs(bola.velocity.y) < 0.3)
        bola.velocity.y = 0;

    if(bola.pos.x > campo.x)
    {
      bola.velocity.x *=-1; 
      bola.pos.x = campo.x; 
    }else if(bola.pos.x < 0)
    {
      bola.velocity.x *=-1;
      bola.pos.x = 0; 
    }

    if(bola.pos.y > campo.y)
    {
      bola.pos.y = campo.y;
      bola.velocity.y *=-1; 
    }else if(bola.pos.y < 0)
    {
      bola.pos.y = 0; 
      bola.velocity.y *=-1;
    }
  
    bola.sin = bola.velocity.y/(bola.velocity.x*bola.velocity.x + bola.velocity.y*bola.velocity.y);
}

