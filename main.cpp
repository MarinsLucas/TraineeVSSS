#include "Jogo.h"


using namespace std;

Jogo* customConfiguration()
{
  strategy time_1;
  strategy time_2; 
  point2f<float> bola; 
  point2f<float> campo; 
  vector<point2f<float>> initialPosTime1;
  vector<point2f<float>> initialPosTime2;
  point2f<float> aux; 
  bool fbf;
  int criterioParada;
  float kat; 

  cout<<"Entre com posição da bola (x)"<<endl;
  cin>>bola.x;
  cout<<"Entre com posição da bola (y)"<<endl;
  cin>>bola.y;

  cout<<"========Time 1========"<<endl;
  cout<<"Posição Robo 1 (x) :";
  cin>>aux.x;
  cout<<"Posição Robo 1 (y):";
  cin>>aux.y;
  initialPosTime1.push_back(aux);

  cout<<"Posição Robo 2 (x) :";
  cin>>aux.x;
  cout<<"Posição Robo 2 (y):";
  cin>>aux.y;
  initialPosTime1.push_back(aux);

  cout<<"Posição Robo 3 (x) :";
  cin>>aux.x;
  cout<<"Posição Robo 3 (y):";
  cin>>aux.y;
  initialPosTime1.push_back(aux);
  time_1.setInitialPos(initialPosTime1);

  cout<<"========Time 2========"<<endl;
  cout<<"Posição Robo 1 (x) :";
  cin>>aux.x;
  cout<<"Posição Robo 1 (y):";
  cin>>aux.y;
  initialPosTime2.push_back(aux);

  cout<<"Posição Robo 2 (x) :";
  cin>>aux.x;
  cout<<"Posição Robo 2 (y):";
  cin>>aux.y;
  initialPosTime2.push_back(aux);

  cout<<"Posição Robo 3 (x) :";
  cin>>aux.x;
  cout<<"Posição Robo 3 (y):";
  cin>>aux.y;
  initialPosTime2.push_back(aux);
  time_2.setInitialPos(initialPosTime2);

  cout<<"====Configurações Gerais===="<<endl;
  cout<<"Deseja execução gráfica do código? (0 ou 1)"<<endl;
  int a;
  cin>>a;
  fbf = a==1;
  cout<<"Tamanho horizontal do campo (padrão = 150)"<<endl;
  cin>>campo.x;
  cout<<"Tamanho vertical do campo (padrão = 130)"<<endl;
  cin>>campo.y;
  cout<<"Gols para finalizar a partida"<<endl;
  cin>>criterioParada; 
  cout<<"Coeficiente de atrito entre bola e campo"<<endl;
  cin>>kat; 

  return new Jogo(criterioParada, campo.y, campo.x, kat, bola, fbf, time_1, time_2);
}

int main()
{

  int a;
  Jogo *jogo; 

  int customInputs = 0;
  cout<<"Bem vindo ao Projeto Trainee VSSS 2022 Time 1 da Rinobot"<<endl;
  cout<<"Você pode criar um jogo customizado (1)"<<endl;
  cout<<"Ou um jogo prédefinido (2)"<<endl;

  while(customInputs != 1 && customInputs !=2)
  {
    cin>>customInputs;
    if(customInputs == 1)
    {
      jogo = customConfiguration();
    }
    else if(customInputs == 2)
    {
      point2f<float> bola; 
      bola.x = 150/2; 
      bola.y = 130/2 ; 

      strategy time_1;
      strategy time_2; 

      vector<point2f<float>> initialPosTime1;
      point2f<float> aux; 

      aux.x = 135;
      aux.y = 25; 
      initialPosTime1.push_back(aux);
      aux.x = 135;
      aux.y = 105; 
      initialPosTime1.push_back(aux);
      aux.x = 95;
      aux.y = 105;
      initialPosTime1.push_back(aux);

      time_1.setInitialPos(initialPosTime1);

      vector<point2f<float>> initialPosTime2;

      aux.x = 15;
      aux.y = 95; 
      initialPosTime2.push_back(aux);
      aux.x = 55;
      aux.y = 95; 
      initialPosTime2.push_back(aux);
      aux.x = 55;
      aux.y = 25;
      initialPosTime2.push_back(aux);

      time_2.setInitialPos(initialPosTime2);

      //Jogo::Jogo(int cP, int cAlt, int cLarg, float kat, point2f<float> b, strategy a, strategy b)
      jogo = new Jogo(1, 130, 150, 0.01, bola, true, time_1, time_2);
    }

  }

  for(int i=0;i<100;i++)
  {
      if(!jogo->run()) break;
      cin >> a;
  }
} 