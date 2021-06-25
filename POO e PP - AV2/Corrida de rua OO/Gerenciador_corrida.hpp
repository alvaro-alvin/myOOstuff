#ifndef Gerenciador_corrida_H_INCLUDED
#define Gerenciador_corrida_H_INCLUDED

#include <stdlib.h>  
#include "Jogador.hpp"


using namespace std;


//armazena um vetor 2d (x,y)
class Gerenciador_corrida {
public:
    //armazena os jogadores que irao interagir
    Jogador* corredor[2];

    //constutor 
    Gerenciador_corrida(Jogador* player, Jogador* npc);

    //se o primeiro jogador vencer retorna positivo 
    bool resultado();

};

Gerenciador_corrida::Gerenciador_corrida(Jogador* player, Jogador* npc){
    corredor[0] = player;
    corredor[1] = npc;
}

bool Gerenciador_corrida::resultado(){
    int player, npc;
    player = (rand() % corredor[0]->carro.potencia + corredor[0]->carro.nivel) + corredor[0]->nivel;
    npc = (rand() % corredor[1]->carro.potencia + corredor[1]->carro.nivel) + corredor[1]->nivel;
    printf("Voce esta correndo contra %s, que possui o carro: ", corredor[1]->nome.c_str());
    corredor[1]->carro.print();
    //ganhou
    if(player > npc){
        return true;
    }
    //se empatar tenta de novo
    else if(player == npc){
        return resultado();
    }
    //perdeu
    else{
        return false;
    }
}


#endif
