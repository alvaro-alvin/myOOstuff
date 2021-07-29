#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "pessoa.h"

using namespace std;

class Cliente: public Pessoa
{
private:
    std::string placa_ultima_compra;
    std::string placa_ultima_venda;


public:

    //construtor
    Cliente(std::string cpf, std::string nome, std::string sexo, std::string telefone, std::string placa_ultima_compra, std::string placa_ultima_venda);
    
    //geters

    virtual std::string get_cpf();
    virtual std::string get_nome();
    virtual std::string get_sexo();
    virtual std::string get_telefone();
    std::string get_placa_ultima_compra();
    std::string get_placa_ultima_venda();

    //seters

    virtual void set_cpf(std::string cpf);
    virtual void set_nome(std::string nome);
    virtual void set_sexo(std::string sexo);
    virtual void set_telefone(std::string telefone);
    void set_placa_ultima_compra(std::string placa);
    void set_placa_ultima_venda(std::string placa);
    void print();


};

#endif 
