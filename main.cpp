#include "Jogo.h"


using namespace std;

int main()
{
    int a;
	
    point2f<float> bola; 
    bola.x = 150/2; 
    bola.y = 130/2 ; 

    strategy time_1;
    strategy time_2; 

    vector<point2f<float>> initialPosTime1;
    point2f<float> aux; 

    aux.x = 100;
    aux.y = 65; 
    initialPosTime1.push_back(aux);
    aux.x = 100;
    aux.y = 25; 
    initialPosTime1.push_back(aux);
    aux.x = 100;
    aux.y = 100;
    initialPosTime1.push_back(aux);

    time_1.setInitialPos(initialPosTime1);

    vector<point2f<float>> initialPosTime2;

    aux.x = 50;
    aux.y = 65; 
    initialPosTime2.push_back(aux);
    aux.x = 50;
    aux.y = 25; 
    initialPosTime2.push_back(aux);
    aux.x = 50;
    aux.y = 100;
    initialPosTime2.push_back(aux);

    time_2.setInitialPos(initialPosTime2);

		//Jogo::Jogo(int cP, int cAlt, int cLarg, float kat, point2f<float> b, strategy a, strategy b)
    Jogo jogo(3, 130, 150, 0.01, bola, true, time_1, time_2);

    for(int i=0;i<100;i++)
    {
        jogo.run();
        cin >> a;
    }
} 
