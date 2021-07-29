#include "../include/empresa.h"

Empresa::Empresa(Dao* dao, std::string nome){
    Empresa::nome = nome;
    saldo_veiculos = 0;
    for(int i = 0; i<dao->veiculo.size(); i++){
        saldo_veiculos = saldo_veiculos + dao->veiculo[i]->get_valor_venda() - dao->veiculo[i]->get_valor_compra();
    }

    despesas_funcionarios = 0;
    for(int i = 0; i<dao->funcionario.size(); i++){
        despesas_funcionarios = despesas_funcionarios - dao->funcionario[i]->get_salario();
    }
    numero_veiculos_venda = 0;
    for(int i = 0; i<dao->veiculo.size(); i++){
        if(dao->veiculo[i]->get_valor_venda() == 0){
            numero_veiculos_venda++;
        }
       
    }

    numero_funcionarios = dao->funcionario.size();
    total_vendas = 0;
    for(int i = 0; i<dao->funcionario.size(); i++){
        total_vendas = total_vendas + dao->funcionario[i]->get_vendas();
    }
}

void Empresa::print(){
    cout << "Nome: " << nome << endl;
    cout << "Saldo veiculos: " << saldo_veiculos << endl;
    cout << "Despesa com funcionarios: " << despesas_funcionarios << endl;
    cout << "Veiculos a venda: " << numero_veiculos_venda << endl;
    cout << "Numero de Funcionarios: " << numero_funcionarios << endl;
    cout << "Total de vendas: " << total_vendas << endl;
}