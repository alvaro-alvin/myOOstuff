#ifndef Banco_H_INCLUDED
#define Banco_H_INCLUDED

using namespace std;

class Banco {
public:
    float saldo;
    float emprestimo;
    float juros;
    float ultima_saida;

    //construtor padrão
    Banco();
};

Banco::Banco(){
    saldo = 15000;
    emprestimo = 0;
    juros = 0.05;
    ultima_saida = 0;
}


#endif