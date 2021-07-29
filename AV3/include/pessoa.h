#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <iostream>
#include <stdio.h>

using namespace std;

class Pessoa
{
protected:
    std::string cpf;
    std::string nome;
    std::string sexo;
    std::string telefone;

public:
    //geters

    virtual std::string get_cpf() = 0;
    virtual std::string get_nome() = 0;
    virtual std::string get_sexo() = 0;
    virtual std::string get_telefone() = 0;

    //seters

    virtual void set_cpf(std::string cpf) = 0;
    virtual void set_nome(std::string nome) = 0;
    virtual void set_sexo(std::string sexo) = 0;
    virtual void set_telefone(std::string) = 0;
    
};

#endif 