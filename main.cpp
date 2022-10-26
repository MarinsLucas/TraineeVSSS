#include <iostream>>
#include "Jogo.h"

using namespace std;

int main()
{
    int a;
    Bola bola;
    bola.pos.x = 150 / 2;
    bola.pos.y = 130 / 2;
    bola.velocity.x = 0;
    bola.velocity.y = 0;

    Jogo *jogo = new Jogo(5, 130, 150, 0.01, bola);

    while (true)
    {
        jogo->run();

        cin >> a;
    }

    delete jogo;
}