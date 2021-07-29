#ifndef DAO_H_INCLUDED
#define DAO_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <pqxx/pqxx>
#include "cliente.h"
#include "funcionario.h"
#include "veiculo.h"

using namespace std;

class Dao
{
private:
    //variaveis de conexao com BD
    //url de conexao
    std::stringstream url;

    //retorna um query para adicionar o cliente
    std::stringstream cliente_to_query(Cliente* cl);
    //retorna um query para adicionar o funcionario
    std::stringstream funcionario_to_query(Funcionario* fn);
    //retorna um query para adicionar o funcionario
    std::stringstream veiculo_to_query(Veiculo* vl);
    
public:

    //armazena os clientes
    vector<Cliente*> cliente;
    //armazena os funcionarios
    vector<Funcionario*> funcionario;
    //armazena os veiculos
    vector<Veiculo*> veiculo;

    /*
    Construtor
    Faz a conexão com o banco e carrega as tabelas nos objetos
    */
    Dao(std::string user, std::string password, std::string host, std::string port, std::string database);
    
    bool adiciona_cliente(Cliente *novo);

    bool remove_cliente(std::string cpf);

    bool modifica_cliente(std::string cpf, std::string campo, std::string novo_valor);

    bool modifica_cliente(std::string cpf, std::string campo, int novo_valor);

    bool modifica_cliente(std::string cpf, std::string campo, float novo_valor);



    bool adiciona_funcionario(Funcionario *novo);

    bool remove_funcionario(std::string cpf);

    bool modifica_funcionario(std::string cpf, std::string campo, std::string novo_valor);

    bool modifica_funcionario(std::string cpf, std::string campo, int novo_valor);

    bool modifica_funcionario(std::string cpf, std::string campo, float novo_valor);



    bool adiciona_veiculo(Veiculo *novo);

    bool remove_veiculo(std::string placa);

    bool modifica_veiculo(std::string placa, std::string campo, std::string novo_valor);

    bool modifica_veiculo(std::string placa, std::string campo, int novo_valor);

    bool modifica_veiculo(std::string placa, std::string campo, float novo_valor);
};

#endif 