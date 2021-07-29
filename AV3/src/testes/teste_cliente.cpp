#include "../../include/cliente.h"

int main(){

    Cliente* novo = new Cliente("12332112345", "Pessoa Teste", "m", "+554712345678", std::string(), std::string());

    novo->print();
    return 0;
}