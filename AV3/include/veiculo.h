#ifndef VEICULO_H_INCLUDED
#define VEICULO_H_INCLUDED

#include <iostream>

using namespace std;

class Veiculo
{
private:
    std::string placa;
    std::string cor;
    std::string marca;
    int potencia;
    float valor_compra;
    float valor_venda;
    int ano;
    std::string tipo;
    std::string nome;
    std::string comentario;
    


public:

    //contrutor
    Veiculo(std::string placa, std::string cor, std::string marca, 
    int potencia, float valor_compra, float valor_venda,
    int ano, std::string tipo, std::string nome);

    //geters

    std::string get_placa();
    std::string get_cor();
    std::string get_marca();
    int get_potencia();
    float get_valor_compra();
    float get_valor_venda();
    int get_ano();
    std::string get_tipo();
    std::string get_comentario();
    std::string get_nome();

    //seters

    void set_placa(std::string placa);
    void set_cor(std::string cor);
    void set_marca(std::string marca);
    void set_potencia(int potencia);
    void set_valor_compra(float valor_compra);
    void set_valor_venda(float valor_venda);
    void set_ano(int ano);
    void set_tipo(std::string tipo);
    void set_comentario(std::string comentario);
    void set_nome(std::string nome);
    
    void print();
};

#endif 