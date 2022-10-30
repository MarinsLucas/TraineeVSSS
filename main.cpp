#include "Jogo.h"

using namespace std;

int main()
{
    int a;
	
    point2f<float> bola; 
    bola.x = 150/2; 
    bola.y = 30; 

		//Jogo::Jogo(int cP, int cAlt, int cLarg, float kat, point2f<float> b)
    Jogo jogo(5, 130, 150, 0.01, bola);

    for(int i=0;i<100;i++)
    {
        jogo.run();
        cin >> a;
    }
}