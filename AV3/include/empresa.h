#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

#include <iostream>
#include <vector>
#include "dao.h"

using namespace std;

class Empresa
{
private:
    

public:
    std::string nome;
    float saldo_veiculos;
    float despesas_funcionarios;
    int numero_veiculos_venda;
    int numero_funcionarios;
    int total_vendas;

    //construtor

    Empresa(Dao* dao, std::string nome);

    //geters


    //seters

    void print();
};

#endif 