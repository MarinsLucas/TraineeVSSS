#include <iostream>
#include "Jogo.h"

Jogo::Jogo(int cP, int cAlt, int cLarg, float kat, Bola b)
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
    bola = b; 

    //Configuração do coeficiente de atrito
    atrito = 9.82*kat; 
}

Jogo::~Jogo()
{
        //~Util time2
}

void Jogo::run()
{
    while(true)
    {
        //time1.decision(bola.pos)
        //time2.decision(bola.pos)

        uptadeBall(0.5);

        if(checkState(placar))
        {
            gameOver();
        }
    }
    

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
    bola.velocity.x -= atrito * deltaTime;
    bola.velocity.y -= atrito * deltaTime;

    bola.sin = bola.velocity.y/(bola.velocity.x*bola.velocity.x + bola.velocity.y*bola.velocity.y);
}

