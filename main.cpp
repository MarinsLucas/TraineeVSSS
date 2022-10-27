#include "Jogo.h"

using namespace std;

int main()
{
    int a;
    point2f<int> bola; 
    bola.x = 150/2;
    bola.y = 130/2; 

  cout<<"teste"<<endl;
    Jogo jogo(5, 130, 150, 0.01, bola);

    for(int i=0;i<10;i++)
    {
        jogo.run();
        cin >> a;
    }
    //delete jogo;
}