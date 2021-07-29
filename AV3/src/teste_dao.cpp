#include "../include/dao.h"
#include "../include/empresa.h"

int main(){

    Dao* dao = new Dao("postgres", "aaos0706", "localhost", "5432", "Garagem");

    Empresa* empresa = new Empresa(dao, "Santos Garagem");
    /*
    Cliente* novo1 = new Cliente("92520083069", "Airton Schunke", "m", "+5551977554400", std::string(), std::string());
    if(!dao->adiciona_cliente(novo1))
        cout << "erro" << endl;
    */

    /*
    Funcionario* novo = new Funcionario("50224260057", "Hylson Fernandes", "m", "+5542947424343", 5, "vendedor", 3500, "1986-02-11");
    if(!dao->adiciona_funcionario(novo))
        cout << "erro" << endl;
    */

    /*
    Veiculo* novo3 = new Veiculo("CRA8F13", "Branco", "Chevrolet", 60, 15000, 17000, 2012, "Carro", "Corsa");
    if(!dao->adiciona_veiculo(novo3))
        cout << "erro" << endl;
    */

    cout << "CLIENTES:" << endl;
    for(int i = 0; i<dao->cliente.size(); i++){
        dao->cliente[i]->print();
    }

    dao->modifica_cliente("79188922071", "ultima_venda", "MQB3F78");

    /*
    dao->remove_cliente("92520083069");

    cout << "CLIENTES:" << endl;
    for(int i = 0; i<dao->cliente.size(); i++){
        dao->cliente[i]->print();
    }
    */

    cout << "FUNCIONARIOS:" << endl;
    for(int i = 0; i<dao->funcionario.size(); i++){
        dao->funcionario[i]->print();
    }

    /*
    dao->remove_funcionario("88455338083");

    cout << "FUNCIONARIOS:" << endl;
    for(int i = 0; i<dao->funcionario.size(); i++){
        dao->funcionario[i]->print();
    }
    */

    cout << "VEICULOS:" << endl;
    for(int i = 0; i<dao->veiculo.size(); i++){
        dao->veiculo[i]->print();
    }

    /*
    dao->remove_veiculo("HVI9D40");

    cout << "VEICULOS:" << endl;
    for(int i = 0; i<dao->veiculo.size(); i++){
        dao->veiculo[i]->print();
    }
    */

    empresa->print();

    
    return 0;
}