#ifndef Veiculo_H_INCLUDED
#define Veiuclo_H_INCLUDED

#include <string>
#include <stdio.h>
#include "Jogador.hpp"

using namespace std;



class Veiculo {
public:
    string nome;
    string categoria;
    int potencia;
    int nivel;
    float preco;

    //construtor
    Veiculo();

    // construtor
    Veiculo(string _nome, string _categoria, int _potencia, float _preco);

    //mostra no console as informações do Veiculo
    void print();

    // recebe uma cópia de outro veiculo
    Veiculo& operator=(const Veiculo & v);
};

Veiculo& Veiculo::operator=(const Veiculo & copy)
{
    nome = copy.nome;
    categoria = copy.categoria;
    potencia = copy.potencia;
    nivel = copy.nivel;
    preco = copy.preco;

    return *this;
}

Veiculo::Veiculo(){
    nome = "";
    categoria = "";
    potencia = 0;
    nivel = 0;
    preco = 0;
}

Veiculo::Veiculo(string _nome, string _categoria, int _potencia, float _preco){
    nome = _nome;
    categoria = _categoria;
    potencia = _potencia;
    nivel = 0;
    preco = _preco;
}

void Veiculo::print(){
    printf("%s | categoria: %s | nível: %d | potencia: %d | Preco: R$%.2f\n", nome.c_str(), categoria.c_str(), nivel, potencia, preco);
}


#endif
