#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
//#include <caca_conio.h>

#include "Jogador.hpp"
#include "Banco.hpp"
#include "Gerenciador_corrida.hpp"

using namespace std;

enum num_commando {
    eCorrer,
    eCarro,
    eBanco,
    eComprar,
    eStatus,
    eSair,
    eErro1,
};

enum num_categoria {
    eOffroad,
    eDrift,
    eArrancada,
    eCorrida,
    eErro2,
};

num_commando hashit_com (std::string const& comando) {

    if (comando == "correr") return eCorrer;
    if (comando == "carro") return eCarro;
    if (comando == "banco") return eBanco;
    if (comando == "comprar") return eComprar;
    if (comando == "status") return eStatus;
    if (comando == "sair") return eSair;
    return eErro1;
}

num_categoria hashit_cat (std::string const& categoria) {

    if (categoria == "offroad") return eOffroad;
    if (categoria == "drift") return eDrift;
    if (categoria == "arrancada") return eArrancada;
    if (categoria == "corrida") return eCorrida;
    return eErro2;
}


int main(){
    Veiculo* carro_padrao = new Veiculo();

    Veiculo* carro[4][4];

    carro[0][0] = new Veiculo("Gaiola", "offroad", 3, 5000);
    carro[0][1] = new Veiculo("Mini ALL", "offroad", 5, 28000);
    carro[0][2] = new Veiculo("Mitsubishi Lancer", "offroad", 7, 56000);
    carro[0][3] = new Veiculo("Toyota Hilux", "offroad", 10, 120000);  

    carro[1][0] = new Veiculo("Gaiola", "drift", 3, 5000);
    carro[1][1] = new Veiculo("Mini ALL", "drift", 5, 28000);
    carro[1][2] = new Veiculo("Mitsubishi Lancer", "drift", 7, 56000);
    carro[1][3] = new Veiculo("Toyota Hilux", "drift", 10, 120000); 

    carro[2][0] = new Veiculo("Gaiola", "arrancada", 3, 5000);
    carro[2][1] = new Veiculo("Mini ALL", "arrancada", 5, 28000);
    carro[2][2] = new Veiculo("Mitsubishi Lancer", "arrancada", 7, 56000);
    carro[2][3] = new Veiculo("Doge Viper", "arrancada", 10, 120000); 

    carro[3][0] = new Veiculo("Honda Civic 98", "corrida", 4, 7000);
    carro[3][1] = new Veiculo("Chevrolet Camaro", "corrida", 6, 100000);
    carro[3][2] = new Veiculo("Nissan GT", "corrida", 8, 120000);
    carro[3][3] = new Veiculo("Lamborguini Galeardo", "corrida", 10, 700000);   
    


    Jogador* npc[4][4];

    npc[0][0] = new Jogador((char*)"Romario", carro[0][0], 0);
    npc[0][1] = new Jogador((char*)"Brenda", carro[0][1], 1);
    npc[0][2] = new Jogador((char*)"Ricardo", carro[0][2], 2);
    npc[0][3] = new Jogador((char*)"Lazaro", carro[0][3], 5);

    npc[1][0] = new Jogador((char*)"Eliane", carro[1][0], 0);
    npc[1][1] = new Jogador((char*)"Gustavo", carro[1][1], 2);
    npc[1][2] = new Jogador((char*)"Lucas", carro[1][2], 4);
    npc[1][3] = new Jogador((char*)"Celso", carro[1][3], 6);

    npc[2][0] = new Jogador((char*)"Suelen", carro[2][0], 0);
    npc[2][1] = new Jogador((char*)"Marcos", carro[2][1], 1);
    npc[2][2] = new Jogador((char*)"Luiz", carro[2][2], 3);
    npc[2][3] = new Jogador((char*)"Fernada", carro[2][3], 5);

    npc[3][0] = new Jogador((char*)"Joao", carro[3][0], 0);
    npc[3][1] = new Jogador((char*)"Maria", carro[3][1], 2);
    npc[3][2] = new Jogador((char*)"Carlos", carro[3][2], 4);
    npc[3][3] = new Jogador((char*)"Hylson", carro[3][3], 7);
    

    bool sair = false;
    bool sub_sair = false;
    char comando[10];
    char nome[20];
    int vitorias = 0;
    printf("escolha seu nome:");
    fgets(nome, sizeof(nome), stdin);

    string _nome(nome);
    Jogador* jogador = new Jogador(_nome, carro_padrao);

    printf("\nPrimeiramente compre um carro, voce tem R$10000,\ndepois faca corridas para ganhar dinheiro,\nmelhorar seu carro ou comprar novos,\ne subir de nivel\n\n");

    //loop principal
    while(!sair){
        sub_sair = false;

        printf("O que voce deseja fazer?\n");
        printf("-------------------------------------\n");
        printf("Para correr digite: Correr\n");
        printf("Para ver e melhorar seu carro: Carro\n");
        printf("Para ver seu dinheiro digite: Banco\n");
        printf("Para ir a loja de carros digite: Comprar\n");
        printf("Para saber seu status: Status\n");
        printf("Para Sair digite: Sair\n\n");


        scanf("%9s", comando);
        string comando_s(comando);
        //converte para minusculo
        for_each(comando_s.begin(), comando_s.end(), [](char & c) {
        c = ::tolower(c);
        });


        switch (hashit_com(comando_s))
        {
        case eCorrer:
            printf("Selecionado: Correr\n");
            int i1;
            i1 = (int)hashit_cat(jogador->carro.categoria);
            while(!sub_sair){
                printf("Qual corrida deseja participar?\n");
                printf("1 - Iniciante | valor de entrada R$1000\n");
                printf("2 - Intermediario | valor de entrada R$5000\n");
                printf("3 - Dificil | valor de entrada R$10000\n");
                printf("4 - Profissional | valor de entrada R$30000\n");
                printf("5 - Voltar\n");
                int j;
                scanf("%d", &j);
                j--;
                if(j == 4){
                    sub_sair = true;
                }
                if(jogador->aceita_corrida_num(j)){
                    Gerenciador_corrida gerenciador(jogador, npc[i1][j]);
                    if(gerenciador.resultado()){
                        printf("Voce ganhou, parabens!\n");
                        jogador->ganhou();
                        vitorias++;
                        if(vitorias%10 == 0 && jogador->nivel<10){
                            jogador->nivel++;
                            printf("Parabens, voce subiu de nivel, agora seu nivel é: %d", jogador->nivel);
                        }
                        
                    }
                    else{
                        printf("Voce perdeu, que pena, saldo atual: R$%.2f\n", jogador->banco.saldo);
                    }
                }
            }

            break;

        case eCarro:
            printf("Selecionado: Carro\n");
            char* sub_comando;
                while (!sub_sair){
                    printf("Seu carro:\n");
                    jogador->carro.print();
                    printf("Deseja aumentar o nivel do seu carro por R$20.000?(s/n)");
                    scanf("%s", sub_comando);
                    if(!strcmp(sub_comando, "n") || !strcmp(sub_comando, "N")){
                        sub_sair = true;
                    }
                    else {
                        if(!strcmp(sub_comando, "s") || !strcmp(sub_comando, "S")){
                            jogador->melhorar_carro();
                        }
                        else{
                            printf("Comando inválido");
                        }
                    }
                }   
            break;

        case eBanco:
            printf("Selecionado: Banco\n");
            printf("Banco nao operante\n");
            break;

        case eComprar:
            printf("Selecionado: Comprar\n");
            char* v1;
            while(!sub_sair){
                for(int i = 0; i<4 ; i++){
                    for(int j = 0; j<4; j++){
                        printf("%d %d -> ", i, j);
                        carro[i][j]->print();
                        printf("-----------------------------------------------------------------------------------------\n");
                    }
                }
                printf("Qual carro deseja comprar?(caso não queira digite 'n')");
                scanf("%s", v1);
                if(!strcmp(v1, "n") || !strcmp(v1, "N")){
                    sub_sair = true;
                }
                else {
                    int a2, a1 = stoi(v1);
                    printf("Proximo numero: ");
                    scanf("%d", &a2);
                    printf("%d %d\n", a1, a2);
                    if((a1 >=0 && a1 <4) && (a2 >=0 && a2 <4)){
                        jogador->comprar(carro[a1][a2]);
                    }
                }
            }
            break;

        case eStatus:
                jogador->print();
            break;

        case eSair:
            printf("Selecionado: Sair\n");
            sair = true;
            break;
        
        default:
            printf("comando não correspondente, tente de novo:\n");
            break;
        }
    }

}