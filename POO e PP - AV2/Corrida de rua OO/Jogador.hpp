#ifndef Jogador_H_INCLUDED
#define Jogador_H_INCLUDED
#include <string.h>
#include "Banco.hpp"
#include "Veiculo.hpp"

using namespace std;


//armazena um vetor 2d (x,y)
class Jogador {
public:
    string nome;
    Veiculo carro;
    Banco banco;
    int nivel;

    //construtor para o jogador principal
    Jogador(string _nome, Veiculo* _carro);

    //construtor para os NPCs
    Jogador(string _nome, Veiculo* _carro, int _nivel);

    // O jogador compra um carro
    bool comprar(Veiculo* carro);

    // Mostra no console as informações do jogador
    void print();

    // Melhora o carro do jogador se ele tiver dinheiro
    bool melhorar_carro();

    // Entra em uma corrida se o jogador tiver dinheiro
    bool aceita_corrida_num(int num);

    // O jogador recebe o premio de vitoria 
    void ganhou();
};

Jogador::Jogador(string _nome, Veiculo* _carro){
    nome = _nome;
    carro = *_carro;
    banco = Banco();
    nivel = 0;
}


Jogador::Jogador(string _nome, Veiculo* _carro, int _nivel){
    nome = _nome;
    carro = *_carro;
    banco = Banco();
    nivel = _nivel;
}

bool Jogador::comprar(Veiculo* novo_carro){
    if(banco.saldo + carro.preco/2 > novo_carro->preco){
        banco.saldo = banco.saldo - (novo_carro->preco - carro.preco/2);
        carro = *novo_carro;
        printf("carro adquirido com sucesso!\n");
        return true;
    }
    else{
        printf("impossivel adquirir carro!\n");
        return false;
    }
}

bool Jogador::melhorar_carro(){
    if(banco.saldo > 20000){
        banco.saldo = banco.saldo - 20000;
        carro.nivel++;
        printf("carro melhorado com sucesso!\n");
        return true;
    }
    else{
        printf("impossivel melhorar carro!\n");
        return false;
    }
}

void Jogador::print(){
    printf("Nome: %s\n Carro:", nome.c_str());
    carro.print();
    printf("Dinheiro: R$%.2f\n Nível: %d\n", banco.saldo, nivel);
}

bool Jogador::aceita_corrida_num(int num){
    if(num == 0){
        if(banco.saldo < 1000){
            return false;
        }
        else{
            banco.saldo = banco.saldo - 1000;
            banco.ultima_saida = 1000;
            printf("Entrada paga, saldo atual:%.2f\n", banco.saldo);
            return true;
        }
    }
    if(num == 1){
        if(banco.saldo < 5000){
            return false;
        }
        else{
            banco.saldo = banco.saldo - 5000;
            banco.ultima_saida = 5000;
            printf("Entrada paga, saldo atual:%.2f\n", banco.saldo);
            return true;
        }
    }
    if(num == 2){
        if(banco.saldo < 10000){
            return false;
        }
        else{
            banco.saldo = banco.saldo - 10000;
            banco.ultima_saida = 10000;
            printf("Entrada paga, saldo atual:%.2f\n", banco.saldo);
            return true;
        }
    }
    if(num == 3){
        if(banco.saldo < 30000){
            return false;
        }
        else{
            banco.saldo = banco.saldo - 30000;
            banco.ultima_saida = 30000;
            printf("Entrada paga, saldo atual:%.2f\n", banco.saldo);
            return true;
        }
    }
    return false;
}

void Jogador::ganhou(){
    banco.saldo = banco.saldo + (2*banco.ultima_saida);
    printf("R$%.2f foram adicionados a sua conta! saldo atual: R$%.2f\n", (2*banco.ultima_saida), banco.saldo);
}

#endif