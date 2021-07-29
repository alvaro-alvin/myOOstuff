#include "../../include/funcionario.h"

int main(){
    Funcionario* novo = new Funcionario("50224260057", "Hylson Fernandes", "m", "+5542947424343", 5, "vendedor", 3500, "1986-02-11");
    
    novo->print();
    
    return 0;
}