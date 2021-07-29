#include "../include/io_functions.h"

void add_veiculo(){
  std::string placa;
  std::string cor;
  std::string marca;
  int potencia;
  float valor_compra;
  float valor_venda;
  int ano;
  std::string tipo;
  std::string nome;

  std::cout << "ADICIONAR VEICULO" << std::endl;

  std::cout << "Digite a placa: ";
  std::cin >> placa;

  std::cout << "Digite a cor: ";
  std::cin >> cor;

  std::cout << "Digite a marca:";
  std::cin >> marca;

  std::cout << "Digite a potencia:";
  std::cin >> potencia;

  std::cout << "Digite o valor de compra:";
  std::cin >> valor_compra;

  std::cout << "Digite o valor de venda (se não foi vendido digite 0): ";
  std::cin >> valor_venda;

  std::cout << "Digite o nome: ";
  std::cin >> nome;

  std::cout << "Digite o tipo (carro, moto, suv, camionte, ...): ";
  std::cin >> tipo;

  std::cout << "Digite ano: ";
  std::cin >> ano;

  Veiculo* novo = new Veiculo(placa.c_str(), cor.c_str(), marca.c_str(), potencia, valor_compra, valor_venda, ano, tipo.c_str(), nome.c_str());
  
  if(!global::dao->adiciona_veiculo(novo)){
    std::cerr << "erro ao adicionar! verifique as onformações acima!" << std::endl;
    return ;
  }
  else
    std::cout << "reinicie a aplicação para que o novo carro apareça na interface" << std::endl;
    return ;
}

void rm_veiculo(){


  std::string placa;

  std::cout << "REMOVER VEICULO" << std::endl;

  std::cout << "Digite a placa: ";
  std::cin >> placa;

  if(!global::dao->remove_veiculo(placa)){
    std::cerr << "erro ao remover! verifique as onformações acima!" << std::endl;
    return ;
  }
  else
    std::cout << "reinicie a aplicação para que a modificação apareça na interface" << std::endl;
    return ;
}

void mod_veiculo(){

  std::string placa;
  std::string campo;
  std::string tipo;
  std::string valor_str;
  int valor_int;
  float valor_float;

  std::cout << "MODIFICAR VEICULO" << std::endl;

  std::cout << "Digite a placa: ";
  std::cin >> placa;

  std::cout << "Digite o campo que sera alterado: ";
  std::cin >> campo;

  std::cout << "Digite o tipo de valor que sera inserido(string, int, float): ";
  std::cin >> tipo;

  if(tipo == "string"){
    std::cout << "Digite o novo valor: ";
    std::cin >> valor_str;
    if(!global::dao->modifica_veiculo(placa, campo, valor_str)){
      std::cerr << "erro ao modificar! verifique as onformações acima!" << std::endl;
      return ;
    }
    else
      std::cout << "reinicie a aplicação para que a modificação apareça na interface" << std::endl;
    return ;
  }
  if(tipo == "float"){
    std::cout << "Digite o novo valor: ";
    std::cin >> valor_float;
    if(!global::dao->modifica_veiculo(placa, campo, valor_float)){
      std::cerr << "erro ao modificar! verifique as onformações acima!" << std::endl;
      return ;
    }
    else
      std::cout << "reinicie a aplicação para que a modificação apareça na interface" << std::endl;
    return ;
  }
  if(tipo == "int"){
    std::cout << "Digite o novo valor: ";
    std::cin >> valor_int;
    if(!global::dao->modifica_veiculo(placa, campo, valor_int)){
      std::cerr << "erro ao modificar! verifique as onformações acima!" << std::endl;
      return ;
    }
    else
      std::cout << "reinicie a aplicação para que a modificação apareça na interface" << std::endl;
    return ;
  }

  std::cerr << "tipo não confere, abortando operação..." << std::endl;
  return;
  
}

void print_veiculos(){
  cout << "  Nome  |  Marca  |  Cor  |  Ano  |  Placa | Potencia | Valor de compra | Valor de venda | Tipo | Comentario" << endl;
  for(int i = 0; i<global::dao->veiculo.size(); i++){
    global::dao->veiculo[i]->print();
  }
}

void add_funcionario(){
  
  std::string cpf;
  std::string p_nome;
  std::string s_nome;
  std::stringstream nome;

  std::string sexo;
  std::string telefone;
  int vendas;
  float salario;
  std::string funcao;
  std::string nascimento;

  std::cout << "ADICIONAR FUNCIONARIO" << std::endl;
  

  std::cout << "Digite o cpf: ";
  std::cin >> cpf;
  
  std::cout << "Digite o primeiro nome: ";
  std::cin >> p_nome;
  
  std::cout << "Digite o sobrenome: ";
  std::cin >> s_nome;

  nome << p_nome << " " << s_nome;

  std::cout << "Digite o sexo (m, f, n): ";
  std::cin >> sexo;
  

  std::cout << "Digite a data de nascimento (AAAA-MM-DD): ";
  std::cin >> nascimento;
  

  std::cout << "Digite o telefone (ex: +5547912345678): ";
  std::cin >> telefone;
  

  std::cout << "Digite o numero de vendas: ";
  std::cin >> vendas;
  

  std::cout << "Digite o salario: ";
  std::cin >> salario;
  

  std::cout << "Digite a funcao: ";
  std::cin >> funcao;
  

  Funcionario* novo = new Funcionario(cpf.c_str(), nome.str().c_str(), sexo.c_str(), telefone.c_str(), vendas, funcao.c_str(), salario, nascimento.c_str());
  
  if(!global::dao->adiciona_funcionario(novo)){
    std::cerr << "erro ao adicionar! verifique as onformações acima!" << std::endl;
    return ;
  }
  else
      return ;
}

void rm_funcionario(){


  std::string cpf;

  std::cout << "REMOVER FUNCIONARIO" << std::endl;

  std::cout << "Digite o cpf: ";
  std::cin >> cpf;

  if(!global::dao->remove_funcionario(cpf)){
    std::cerr << "erro ao remover! verifique as onformações acima!" << std::endl;
    return ;
  }
  else
    return ;
}

void mod_funcionario(){

  std::string cpf;
  std::string campo;
  std::string tipo;
  std::string valor_str;
  int valor_int;
  float valor_float;

  std::cout << "MODIFICAR FUNCIONARIO" << std::endl;

  std::cout << "Digite o CPF: ";
  std::cin >> cpf;

  std::cout << "Digite o campo que sera alterado: ";
  std::cin >> campo;

  std::cout << "Digite o tipo de valor que sera inserido(string, int, float): ";
  std::cin >> tipo;

  if(tipo == "string"){
    std::cout << "Digite o novo valor: ";
    std::cin >> valor_str;
    if(!global::dao->modifica_funcionario(cpf, campo, valor_str)){
      std::cerr << "erro ao modificar! verifique as onformações acima!" << std::endl;
      return ;
    }
    else
    return ;
  }
  if(tipo == "float"){
    std::cout << "Digite o novo valor: ";
    std::cin >> valor_float;
    if(!global::dao->modifica_funcionario(cpf, campo, valor_float)){
      std::cerr << "erro ao modificar! verifique as onformações acima!" << std::endl;
      return ;
    }
    else
    return ;
  }
  if(tipo == "int"){
    std::cout << "Digite o novo valor: ";
    std::cin >> valor_int;
    if(!global::dao->modifica_funcionario(cpf, campo, valor_int)){
      std::cerr << "erro ao modificar! verifique as onformações acima!" << std::endl;
      return ;
    }
    else

    return ;
  }

  std::cerr << "tipo não confere, abortando operação..." << std::endl;
  return;
  
}

void print_funcionarios(){
  cout << "CPF         | Nome            | Sexo |   Telefone   | N° vendas |   Cargo   |  Salario  | Data de nascimento | Comentario " <<  endl;
  for(int i = 0; i<global::dao->funcionario.size(); i++){
    global::dao->funcionario[i]->print();
  }
}


void add_cliente(){

  std::string cpf;
  std::string p_nome;
  std::string s_nome;
  std::stringstream nome;

  std::string sexo;
  std::string telefone;
  std::cout << "ADICIONAR CLIENTE" << std::endl;
  

  std::cout << "Digite o cpf: ";
  std::cin >> cpf;
  
  std::cout << "Digite o primeiro nome: ";
  std::cin >> p_nome;
  
  std::cout << "Digite o sobrenome: ";
  std::cin >> s_nome;

  nome << p_nome << " " << s_nome;

  std::cout << "Digite o sexo (m, f, n): ";
  std::cin >> sexo;  

  std::cout << "Digite o telefone (ex: +5547912345678): ";
  std::cin >> telefone;
    

  Cliente* novo = new Cliente(cpf.c_str(), nome.str().c_str(), sexo.c_str(), telefone.c_str(), std::string(), std::string());
  
  if(!global::dao->adiciona_cliente(novo)){
    std::cerr << "erro ao adicionar! verifique as onformações acima!" << std::endl;
    return ;
  }
  else
      return ;
}

void rm_cliente(){


  std::string cpf;

  std::cout << "REMOVER CLIENTE" << std::endl;

  std::cout << "Digite o cpf: ";
  std::cin >> cpf;

  if(!global::dao->remove_cliente(cpf)){
    std::cerr << "erro ao remover! verifique as onformações acima!" << std::endl;
    return ;
  }
  else
    return ;
}

void mod_cliente(){

  std::string cpf;
  std::string campo;
  std::string tipo;
  std::string valor_str;
  int valor_int;
  float valor_float;

  std::cout << "MODIFICAR CLIENTE" << std::endl;

  std::cout << "Digite o CPF: ";
  std::cin >> cpf;

  std::cout << "Digite o campo que sera alterado: ";
  std::cin >> campo;

  std::cout << "Digite o tipo de valor que sera inserido(string, int, float): ";
  std::cin >> tipo;

  if(tipo == "string"){
    std::cout << "Digite o novo valor: ";
    std::cin >> valor_str;
    if(!global::dao->modifica_cliente(cpf, campo, valor_str)){
      std::cerr << "erro ao modificar! verifique as onformações acima!" << std::endl;
      return ;
    }
    else
    return ;
  }
  if(tipo == "float"){
    std::cout << "Digite o novo valor: ";
    std::cin >> valor_float;
    if(!global::dao->modifica_cliente(cpf, campo, valor_float)){
      std::cerr << "erro ao modificar! verifique as onformações acima!" << std::endl;
      return ;
    }
    else
    return ;
  }
  if(tipo == "int"){
    std::cout << "Digite o novo valor: ";
    std::cin >> valor_int;
    if(!global::dao->modifica_cliente(cpf, campo, valor_int)){
      std::cerr << "erro ao modificar! verifique as onformações acima!" << std::endl;
      return ;
    }
    else
    return ;
  }

  std::cerr << "tipo não confere, abortando operação..." << std::endl;
  return;
  
}

void print_clientes(){
  cout << "CPF         | Nome            | Sexo | Telefone | Ultimo veiculo comprado | Ultimo veiculo vendido" <<  endl;
  for(int i = 0; i<global::dao->cliente.size(); i++){
    global::dao->cliente[i]->print();
  }
}