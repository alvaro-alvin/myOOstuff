#include "../include/cliente.h"

Cliente::Cliente(std::string cpf, std::string nome, std::string sexo, std::string telefone, std::string placa_ultima_compra, std::string placa_ultima_venda){
    Cliente::cpf = cpf;
    Cliente::nome = nome;
    Cliente::sexo = sexo;
    Cliente::telefone = telefone;
    Cliente::placa_ultima_compra = placa_ultima_compra;
    Cliente::placa_ultima_venda = placa_ultima_venda;
}

std::string Cliente::get_cpf(){
    return cpf;
};

std::string Cliente::get_nome(){
    return nome;
};

std::string Cliente::get_sexo(){
    return sexo;
};

std::string Cliente::get_telefone(){
    return telefone;
};

std::string Cliente::get_placa_ultima_compra(){
    return placa_ultima_compra;
};

std::string Cliente::get_placa_ultima_venda(){
    return placa_ultima_venda;
};

void Cliente::set_cpf(std::string cpf){
    Cliente::cpf = cpf;
}

void Cliente::set_nome(std::string nome){
    Cliente::nome = nome;
}

void Cliente::set_sexo(std::string sexo){
    Cliente::sexo = sexo;
}

void Cliente::set_telefone(std::string telefone){
    Cliente::telefone = telefone;
}

void Cliente::set_placa_ultima_compra(std::string placa){
    Cliente::placa_ultima_compra = placa;
}

void Cliente::set_placa_ultima_venda(std::string placa){
    Cliente::placa_ultima_venda = placa;
}

void Cliente::print(){
    cout << cpf << " | " << nome << " | " << sexo << " | " << telefone << " | " << placa_ultima_compra << " | " << placa_ultima_venda << endl;
}

