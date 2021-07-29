#include "../include/funcionario.h"

Funcionario::Funcionario(std::string cpf, std::string nome, std::string sexo, std::string telefone, int vendas, std::string funcao, float salario, std::string nascimento){
    Funcionario::cpf = cpf;
    Funcionario::nome = nome;
    Funcionario::sexo = sexo;
    Funcionario::telefone = telefone;
    Funcionario::vendas = vendas;
    Funcionario::funcao = funcao;
    Funcionario::salario = salario;
    Funcionario::nascimento = nascimento;
    Funcionario::comentario = "\0";
}

std::string Funcionario::get_cpf(){
    return cpf;
};

std::string Funcionario::get_nome(){
    return nome;
};

std::string Funcionario::get_sexo(){
    return sexo;
};

std::string Funcionario::get_telefone(){
    return telefone;
};

int Funcionario::get_vendas(){
    return vendas;
};

std::string Funcionario::get_funcao(){
    return funcao;
};

float Funcionario::get_salario(){
    return salario;
};

std::string Funcionario::get_nascimento(){
    return nascimento;
};

std::string Funcionario::get_comentario(){
    return comentario;
};


void Funcionario::set_cpf(std::string cpf){
    Funcionario::cpf = cpf;
}

void Funcionario::set_nome(std::string nome){
    Funcionario::nome = nome;
}

void Funcionario::set_sexo(std::string sexo){
    Funcionario::sexo = sexo;
}

void Funcionario::set_telefone(std::string telefone){
    Funcionario::telefone = telefone;
}

void Funcionario::set_vendas(int vendas){
    Funcionario::vendas = vendas;
}

void Funcionario::set_funcao(std::string funcao){
    Funcionario::funcao = funcao;
}

void Funcionario::set_salario(float salario){
    Funcionario::salario = salario;
}

void Funcionario::set_nascimento(std::string data){
    Funcionario::nascimento = data;
}

void Funcionario::set_comentario(std::string comentario){
    Funcionario::comentario = comentario;
}


void Funcionario::print(){
    cout << cpf << " | " << nome << " | " << sexo << " | "  << telefone << " | " << vendas << "         | " << funcao << "   | " << salario   << " | " << nascimento << " | " << comentario <<  endl;
}

