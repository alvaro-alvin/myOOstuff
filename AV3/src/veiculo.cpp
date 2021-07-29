    #include "../include/veiculo.h"
    
    //contrutor
    Veiculo::Veiculo(std::string placa, std::string cor, std::string marca, 
    int potencia, float valor_compra, float valor_venda,
    int ano, std::string tipo, std::string nome){
        Veiculo::placa = placa;
        Veiculo::cor= cor;
        Veiculo::marca = marca;
        Veiculo::potencia = potencia;
        Veiculo::valor_compra = valor_compra;
        Veiculo::valor_venda = valor_venda;
        Veiculo::ano = ano;
        Veiculo::tipo = tipo;
        Veiculo::nome = nome;
        Veiculo::comentario = "\0";
        
    }

    //geters

    std::string Veiculo::get_placa(){
        return placa;
    }

    std::string Veiculo::get_cor(){
        return cor;
    }
    std::string Veiculo::get_marca(){
        return marca;
    }

    int Veiculo::get_potencia(){
        return potencia;
    }

    float Veiculo::get_valor_compra(){
        return valor_compra;
    }

    float Veiculo::get_valor_venda(){
        return valor_venda;
    }

    int Veiculo::get_ano(){
        return ano;
    }

    std::string Veiculo::get_tipo(){
        return tipo;
    }

    std::string Veiculo::get_nome(){
        return nome;
    }

    std::string Veiculo::get_comentario(){
        return comentario;
    }

    

    //seters

    void Veiculo::set_placa(std::string placa){
        Veiculo::placa = placa;
    }

    void Veiculo::set_cor(std::string cor){
        Veiculo::cor = cor;
    }

    void Veiculo::set_marca(std::string marca){
        Veiculo::marca = marca;
    }

    void Veiculo::set_potencia(int potencia){
        Veiculo::potencia = potencia;
    }

    void Veiculo::set_valor_compra(float valor_compra){
        Veiculo::valor_compra = valor_compra;
    }

    void Veiculo::set_valor_venda(float valor_venda){
        Veiculo::valor_venda = valor_venda;
    }

    void Veiculo::set_ano(int ano){
        Veiculo::ano = ano;
    }

    void Veiculo::set_tipo(std::string tipo){
        Veiculo::tipo = tipo;
    }

    void Veiculo::set_nome(std::string nome){
        Veiculo::nome = nome;
    }

    void Veiculo::set_comentario(std::string comentario){
        Veiculo::comentario = comentario;
    }

    void Veiculo::print(){
        cout << nome << " | " << marca << " | " << cor << " | " << ano << " | " << placa << " | " << potencia << " | " << valor_compra   << " | " << valor_venda << " | " << tipo << " | " << comentario <<  endl;
    }
    