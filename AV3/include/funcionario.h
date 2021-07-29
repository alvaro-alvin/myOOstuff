#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED
#include <iostream>
#include "pessoa.h"

using namespace std;

class Funcionario: public Pessoa
{
private:
    int vendas;
    std::string funcao;
    float salario;
    std::string nascimento;
    std::string comentario;

public:

    //construtor
    Funcionario(std::string cpf, std::string nome, std::string sexo,
    std::string telefone, int vendas, std::string funcao, float salario,
    std::string nascimento);


    //getters

    virtual std::string get_cpf();
    virtual std::string get_nome();
    virtual std::string get_sexo();
    virtual std::string get_telefone();
    int get_vendas();
    std::string get_funcao();
    float get_salario();
    std::string get_nascimento();
    std::string get_comentario();

    //setters

    virtual void set_cpf(std::string cpf);
    virtual void set_nome(std::string nome);
    virtual void set_sexo(std::string sexo);
    virtual void set_telefone(std::string telefone);
    void set_vendas(int vendas);
    void set_funcao(std::string funcao);
    void set_salario(float salario);
    void set_nascimento(std::string data);
    void set_comentario(std::string comentario);

    //-----

    void print();
    
};

#endif 
