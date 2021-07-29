#include "../include/dao.h"

Dao::Dao(std::string user, std::string password, std::string host, std::string port, std::string database){
    url << "postgresql://" << user;
    url << ":" << password << "@" << host << ":" << port << "/" << database;
    
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Querry
        pqxx::work txn(conn);
        //obtem os clientes
        pqxx::result res{txn.exec("select * from clientes")};
        int totCol = res.columns();
        //adiciona os clientes
        if(!res.empty()){
            for(auto row: res){
                Cliente* cl = new Cliente(row[0].c_str(), row[1].c_str(), row[2].c_str(), row[3].c_str(), row[4].c_str(), row[5].c_str() );
                cliente.push_back(cl);
            }
        }
        //txn.commit();
        
        res = txn.exec("select * from funcionarios");
        totCol = res.columns();
        //adiciona os funcionarios
        if(!res.empty()){
            for(auto row: res){
                Funcionario* fn = new Funcionario(row[0].c_str(), row[1].c_str(), row[2].c_str(), row[3].c_str(), atoi(row[4].c_str()), row[5].c_str(), (float)atof(row[6].c_str()), row[7].c_str());
                funcionario.push_back(fn);
            }
        }
        //txn.commit();
        
        res = txn.exec("select * from veiculos");
        totCol = res.columns();
        //adiciona os veiculos
        if(!res.empty()){
            for(auto row: res){
                Veiculo* vl = new Veiculo(row[0].c_str(), row[1].c_str(), row[2].c_str(), atoi(row[3].c_str()), (float)atof(row[4].c_str()), (float)atof(row[5].c_str()), atoi(row[6].c_str()), row[7].c_str(), row[9].c_str());
                //vl->print();
                veiculo.push_back(vl);
            }
        }
        txn.commit();
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }

}

bool Dao::adiciona_cliente(Cliente *novo){
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Query
        pqxx::work txn(conn);
        //obtem os clientes
        std::stringstream q = cliente_to_query(novo);
        //executa a query
        pqxx::result res{txn.exec(q.str())};

        cliente.push_back(novo);
        
        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    cout << "adição do cliente ocorreu com sucesso!" << endl;
    return true;
    
}

bool Dao::remove_cliente(std::string cpf){
    bool encontrou = false;
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Query
        pqxx::work txn(conn);
        //monta a query de remoção
        std::stringstream q;
        q << "DELETE FROM clientes WHERE cpf = \'" << cpf << "\';";
        //executa a query
        pqxx::result res{txn.exec(q.str())};
        
        int pos = 0;
        //encontra no vector
        for(int i =0; i<cliente.size(); i++){
            if(cliente[i]->get_cpf() == cpf){
                pos = i;
                encontrou = true;
                i = cliente.size();
            }
        }
        
        //remove o elemnto do vector
        if(encontrou)
            cliente.erase (cliente.begin() + pos);

        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    if(!encontrou){
        cout << "Cliente não encontrado no banco de dados" << endl;
        return false;
    }
    else{
        cout << "remoção do cliente ocorreu com sucesso!" << endl;
        return true;
    }
    
}

bool Dao::modifica_cliente(std::string cpf, std::string campo, std::string novo_valor){
    bool encontrou = false;
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Query
        pqxx::work txn(conn);
        //monta a query de remoção
        std::stringstream q;
        q << "UPDATE clientes SET " << campo << " = \'" << novo_valor << "\' WHERE cpf = \'" << cpf <<"\';";
        //executa a query
        pqxx::result res{txn.exec(q.str())};
        
        int pos = 0;
        //encontra no vector
        for(int i =0; i<cliente.size(); i++){
            if(cliente[i]->get_cpf() == cpf){
                pos = i;
                encontrou = true;
                i = cliente.size();
            }
        }
        
        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    if(!encontrou){
        cout << "Cliente não encontrado no banco de dados" << endl;
        return false;
    }
    else{
        cout << "modificação do cliente ocorreu com sucesso!" << endl;
        return true;
    }
    
}

bool Dao::modifica_cliente(std::string cpf, std::string campo, float novo_valor){
    bool encontrou = false;
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Query
        pqxx::work txn(conn);
        //monta a query de remoção
        std::stringstream q;
        q << "UPDATE clientes SET " << campo << " = " << novo_valor << " WHERE cpf = \'" << cpf <<"\';";
        //executa a query
        pqxx::result res{txn.exec(q.str())};
        
        int pos = 0;
        //encontra no vector
        for(int i =0; i<cliente.size(); i++){
            if(cliente[i]->get_cpf() == cpf){
                pos = i;
                encontrou = true;
                i = cliente.size();
            }
        }
        
        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    if(!encontrou){
        cout << "Cliente não encontrado no banco de dados" << endl;
        return false;
    }
    else{
        cout << "modificação do cliente ocorreu com sucesso!" << endl;
        return true;
    }
    
}

bool Dao::modifica_cliente(std::string cpf, std::string campo, int novo_valor){
    bool encontrou = false;
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Query
        pqxx::work txn(conn);
        //monta a query de remoção
        std::stringstream q;
        q << "UPDATE clientes SET " << campo << " = " << novo_valor << " WHERE cpf = \'" << cpf <<"\';";
        //executa a query
        pqxx::result res{txn.exec(q.str())};
        
        int pos = 0;
        //encontra no vector
        for(int i =0; i<cliente.size(); i++){
            if(cliente[i]->get_cpf() == cpf){
                pos = i;
                encontrou = true;
                i = cliente.size();
            }
        }
        
        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    if(!encontrou){
        cout << "Cliente não encontrado no banco de dados" << endl;
        return false;
    }
    else{
        cout << "modificação do cliente ocorreu com sucesso!" << endl;
        return true;
    }
    
}

bool Dao::adiciona_funcionario(Funcionario *novo){
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Querry
        pqxx::work txn(conn);
        //obtem os clientes
        std::stringstream q = funcionario_to_query(novo);
        //executa a query
        pqxx::result res{txn.exec(q.str())};

        funcionario.push_back(novo);

        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    cout << "adição do funcionario ocorreu com sucesso!" << endl;

    return true;
}

bool Dao::remove_funcionario(std::string cpf){
    bool encontrou = false;
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Query
        pqxx::work txn(conn);
        //monta a query de remoção
        std::stringstream q;
        q << "DELETE FROM funcionarios WHERE cpf = \'" << cpf << "\';";
        //executa a query
        pqxx::result res{txn.exec(q.str())};
        
        
        int pos = 0;
        //encontra no vector
        for(int i =0; i<funcionario.size(); i++){
            if(funcionario[i]->get_cpf() == cpf){
                pos = i;
                encontrou = true;
                i = funcionario.size();
            }
        }
        
        //remove o elemnto do vector
        if(encontrou)
            funcionario.erase (funcionario.begin() + pos);

        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    if(!encontrou){
        cout << "Funcionario não encontrado no banco de dados" << endl;
        return false;
    }
    else{
        cout << "remoção do funcionario ocorreu com sucesso!" << endl;
        return true;
    }
    
}

bool Dao::modifica_funcionario(std::string cpf, std::string campo, std::string novo_valor){
    bool encontrou = false;
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Query
        pqxx::work txn(conn);
        //monta a query de remoção
        std::stringstream q;
        q << "UPDATE funcionarios SET " << campo << " = \'" << novo_valor << "\' WHERE cpf = \'" << cpf <<"\';";
        //executa a query
        pqxx::result res{txn.exec(q.str())};
        
        int pos = 0;
        //encontra no vector
        for(int i =0; i<funcionario.size(); i++){
            if(funcionario[i]->get_cpf() == cpf){
                pos = i;
                encontrou = true;
                i = funcionario.size();
            }
        }
        
        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    if(!encontrou){
        cout << "Funcionario não encontrado no banco de dados" << endl;
        return false;
    }
    else{
        cout << "modificação do funcionario ocorreu com sucesso!" << endl;
        return true;
    }
    
}

bool Dao::modifica_funcionario(std::string cpf, std::string campo, float novo_valor){
    bool encontrou = false;
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Query
        pqxx::work txn(conn);
        //monta a query de remoção
        std::stringstream q;
        q << "UPDATE funcionarios SET " << campo << " = " << novo_valor << " WHERE cpf = \'" << cpf <<"\';";
        //executa a query
        pqxx::result res{txn.exec(q.str())};
        
        int pos = 0;
        //encontra no vector
        for(int i =0; i<funcionario.size(); i++){
            if(funcionario[i]->get_cpf() == cpf){
                pos = i;
                encontrou = true;
                i = funcionario.size();
            }
        }
        
        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    if(!encontrou){
        cout << "Funcionario não encontrado no banco de dados" << endl;
        return false;
    }
    else{
        cout << "modificação do funcionario ocorreu com sucesso!" << endl;
        return true;
    }
    
}

bool Dao::modifica_funcionario(std::string cpf, std::string campo, int novo_valor){
    bool encontrou = false;
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Query
        pqxx::work txn(conn);
        //monta a query de remoção
        std::stringstream q;
        q << "UPDATE funcionarios SET " << campo << " = " << novo_valor << " WHERE cpf = \'" << cpf <<"\';";
        //executa a query
        pqxx::result res{txn.exec(q.str())};
        
        int pos = 0;
        //encontra no vector
        for(int i =0; i<funcionario.size(); i++){
            if(funcionario[i]->get_cpf() == cpf){
                pos = i;
                encontrou = true;
                i = funcionario.size();
            }
        }
        
        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    if(!encontrou){
        cout << "Funcionario não encontrado no banco de dados" << endl;
        return false;
    }
    else{
        cout << "modificação do funcionario ocorreu com sucesso!" << endl;
        return true;
    }
    
}


bool Dao::adiciona_veiculo(Veiculo *novo){
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Querry
        pqxx::work txn(conn);
        //obtem os clientes
        std::stringstream q = veiculo_to_query(novo);
        //executa a query
        pqxx::result res{txn.exec(q.str())};

        veiculo.push_back(novo);

        txn.commit();    
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    cout << "adição do veiculo ocorreu com sucesso!" << endl;
    return true;
}


bool Dao::remove_veiculo(std::string placa){
    bool encontrou = false;
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Query
        pqxx::work txn(conn);
        //monta a query de remoção
        std::stringstream q;
        q << "DELETE FROM veiculos WHERE placa = \'" << placa << "\';";
        //executa a query
        pqxx::result res{txn.exec(q.str())};
        
        int pos = 0;
        //encontra no vector
        for(int i =0; i<veiculo.size(); i++){
            if(veiculo[i]->get_placa() == placa){
                pos = i;
                encontrou = true;
                i = veiculo.size();
            }
        }
        
        //remove o elemnto do vector
        if(encontrou)
            veiculo.erase (veiculo.begin() + pos);

        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    if(!encontrou){
        cout << "Veiculo não encontrado no banco de dados" << endl;
        return false;
    }
    else{
        cout << "remoção do veiculo ocorreu com sucesso!" << endl;
        return true;
    }
    
}

bool Dao::modifica_veiculo(std::string placa, std::string campo, std::string novo_valor){
    bool encontrou = false;
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Query
        pqxx::work txn(conn);
        //monta a query de remoção
        std::stringstream q;
        q << "UPDATE veiculos SET " << campo << " = \'" << novo_valor << "\' WHERE placa = \'" << placa <<"\';";
        //executa a query
        pqxx::result res{txn.exec(q.str())};
        
        int pos = 0;
        //encontra no vector
        for(int i =0; i<veiculo.size(); i++){
            if(veiculo[i]->get_placa() == placa){
                pos = i;
                encontrou = true;
                i = veiculo.size();
            }
        }
        
        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    if(!encontrou){
        cout << "Veiculo não encontrado no banco de dados" << endl;
        return false;
    }
    else{
        cout << "modificação do veiculo ocorreu com sucesso!" << endl;
        return true;
    }
    
}

bool Dao::modifica_veiculo(std::string placa, std::string campo, float novo_valor){
    bool encontrou = false;
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Query
        pqxx::work txn(conn);
        //monta a query de remoção
        std::stringstream q;
        q << "UPDATE veiculos SET " << campo << " = " << novo_valor << " WHERE placa = \'" << placa <<"\';";
        //executa a query
        pqxx::result res{txn.exec(q.str())};
        
        int pos = 0;
        //encontra no vector
        for(int i =0; i<veiculo.size(); i++){
            if(veiculo[i]->get_placa() == placa){
                pos = i;
                encontrou = true;
                i = veiculo.size();
            }
        }
        
        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    if(!encontrou){
        cout << "Veiculo não encontrado no banco de dados" << endl;
        return false;
    }
    else{
        cout << "modificação do veiculo ocorreu com sucesso!" << endl;
        return true;
    }
    
}

bool Dao::modifica_veiculo(std::string placa, std::string campo, int novo_valor){
    bool encontrou = false;
    try{
        //faz a conexão
        pqxx::connection conn{url.str()};
        //Query
        pqxx::work txn(conn);
        //monta a query de remoção
        std::stringstream q;
        q << "UPDATE veiculos SET " << campo << " = " << novo_valor << " WHERE placa = \'" << placa <<"\';";
        //executa a query
        pqxx::result res{txn.exec(q.str())};
        
        int pos = 0;
        //encontra no vector
        for(int i =0; i<veiculo.size(); i++){
            if(veiculo[i]->get_placa() == placa){
                pos = i;
                encontrou = true;
                i = veiculo.size();
            }
        }
        
        txn.commit();    
        conn.disconnect();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return false;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    if(!encontrou){
        cout << "Veiculo não encontrado no banco de dados" << endl;
        return false;
    }
    else{
        cout << "modificação do veiculo ocorreu com sucesso!" << endl;
        return true;
    }
    
}


std::stringstream Dao::cliente_to_query(Cliente* cl){
    std::stringstream q;
    q << "INSERT INTO clientes (cpf, nome, sexo, telefone, ultima_compra, ultima_venda) VALUES (\'" << cl->get_cpf() << "\', \'" << cl->get_nome() << "\', \'" << cl->get_sexo() << "\', \'" << cl->get_telefone() << "\', \'" << cl->get_placa_ultima_compra() << "\', \'" << cl->get_placa_ultima_venda() << "\');";
    return q;
}

std::stringstream Dao::funcionario_to_query(Funcionario* fn){
    std::stringstream q;
    q << "INSERT INTO funcionarios (cpf, nome, sexo, telefone, vendas, funcao, salario, nascimento) VALUES (\'" << fn->get_cpf() << "\', \'" << fn->get_nome() << "\', \'" << fn->get_sexo() << "\', \'" << fn->get_telefone() << "\', " << fn->get_vendas() << ", \'" << fn->get_funcao() << "\', " << fn->get_salario() << ", \'" << fn->get_nascimento() << "\');";
    return q;
}

std::stringstream Dao::veiculo_to_query(Veiculo* vl){
    std::stringstream q;
    q << "INSERT INTO veiculos (placa, cor, marca, potencia, valor_compra, valor_venda, ano, tipo, nome) VALUES (\'" << vl->get_placa() << "\', \'" << vl->get_cor() << "\', \'" << vl->get_marca() << "\', " << vl->get_potencia() << ", " << vl->get_valor_compra() << ", " << vl->get_valor_venda() << ", " << vl->get_ano() << ", \'" << vl->get_tipo() << "\', \'" << vl->get_nome() <<"\');";
    return q;
}