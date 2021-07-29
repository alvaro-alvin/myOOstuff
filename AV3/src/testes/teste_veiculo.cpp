#include "../../include/veiculo.h"

int main(){
    Veiculo* novo = new Veiculo("CRA8F13", "Branco", "Chevrolet", 60, 15000, 17000, 2012, "Carro", "Corsa");

    novo->print();

    return 0;
}