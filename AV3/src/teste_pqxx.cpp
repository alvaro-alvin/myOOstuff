#include <iostream>
#include <iomanip>
#include <pqxx/pqxx>

//para compilar: 
// g++ teste_pqxx.cpp -lpq -lpqxx -o teste_pqxx -std=c++20

using namespace std;

int main(int argc, char* argv[]){

    std::array<int, 6> wCol = {11, 20, 4, 14, 13, 13};
    std::stringstream ss;

    char mPass[20];
    memset (mPass, '\0', sizeof(mPass));

    

    //"postgresql://<user>:<password>@<host>:<port>/<database>";
        ss << "postgresql://" << argv[3];
        ss << ":" << mPass << "@" << argv[1] << ":" << argv[2] << "/" << argv[4];


    try {
        //faz a conexao
        pqxx::connection conn{"postgresql://postgres:aaos0706@localhost:5432/Garagem"};
        //Postgres querry 
        pqxx::work txn(conn);
        //resultado da querry
        pqxx::result res{txn.exec("select * from clientes")};

        if(!res.empty()){

            int totCol = res.columns();
            std::cout << "----------------------------------------------------------------" << std::endl;

            std::cout << "|";
            for( int i = 0; i < totCol; i++){
                std::cout << std::setfill(' ') << std::setw(wCol[i]) << std::left << res.column_name(i) << "|";
            }

            std::cout << std::endl;
            std::cout << "----------------------------------------------------------------" << std::endl;

            for(auto row: res){
                std::cout << "|";
                for( int i = 0; i < totCol; i++){
                    std::cout << std::setfill(' ') << std::setw(wCol[i]) << std::left << row[i].c_str() << "|";
                }
                std::cout << std::endl;
            }

            std::cout << "----------------------------------------------------------------" << std::endl;

        }
        txn.commit();
    }
    catch (pqxx::sql_error const &e){
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query was : " << e.query() << std::endl;
        return 2;
    }
    catch (std::exception const &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;

}