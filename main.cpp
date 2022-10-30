#include "Jogo.h"

using namespace std;

int main()
{
    int a;
    point2f<float> bola; 
    bola.x = 104;
    bola.y = 35; 
  
    Jogo jogo(5, 130, 150, 0.01, bola);

    for(int i=0;i<100;i++)
    {
        jogo.run();
        cin >> a;
    }
}