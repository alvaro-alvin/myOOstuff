#include <stdio.h>
#include <string.h>


#include "funcoes.h"


int main(){
    Veiculo carro_padrao = {"Sem veiculo", 0, 0, 0, 0};

    Veiculo carro[4][4] = {
        [0][0] = {"Gaiola", 0, 3, 0, 5000},
        [0][1] = {"Mini ALL", 0, 5, 0, 28000},
        [0][2] = {"Mitsubishi Lancer", 0, 7, 0, 56000},
        [0][3] = {"Toyota Hilux", 0, 10, 0, 120000},

        [1][0] = {"Gaiola", 1, 3, 0, 5000},
        [1][1] = {"Mini ALL", 1, 5, 0, 28000},
        [1][2] = {"Mitsubishi Lancer", 1, 7, 0, 56000},
        [1][3] = {"Toyota Hilux", 1, 10, 0, 120000},

        [2][0] = {"Gaiola", 2, 3, 0, 5000},
        [2][1] = {"Mini ALL", 2, 5, 0, 28000},
        [2][2] = {"Mitsubishi Lancer", 2, 7, 0,  56000},
        [2][3] = {"Doge Viper", 2, 10, 0,  120000},

        [3][0] = {"Honda Civic 98", 3, 4, 0,  7000},
        [3][1] = {"Chevrolet Camaro", 3, 6, 0,  100000},
        [3][2] = {"Nissan GT", 3, 8, 0,  120000},
        [3][3] = {"Lamborguini Galeardo", 3, 10, 0,  700000}
    };

    Jogador npc[4][4] = {
        [0][0] =  {"Romario", carro[0][0], 0, 0},
        [0][1] =  {"Brenda", carro[0][1], 0,  1},
        [0][2] =  {"Ricardo", carro[0][2], 0,  2},
        [0][3] =  {"Lazaro", carro[0][3], 0,  5},

        [1][0] =  {"Eliane", carro[1][0], 0,  0},
        [1][1] =  {"Gustavo", carro[1][1], 0,  2},
        [1][2] =  {"Lucas", carro[1][2], 0,  4},
        [1][3] =  {"Celso", carro[1][3], 0,  6},

        [2][0] =  {"Suelen", carro[2][0], 0,  0},
        [2][1] =  {"Marcos", carro[2][1], 0,  1},
        [2][2] =  {"Luiz", carro[2][2], 0,  3},
        [2][3] =  {"Fernada", carro[2][3], 0,  5},

        [3][0] =  {"Joao", carro[3][0], 0,  0},
        [3][1] =  {"Maria", carro[3][1], 0,  2},
        [3][2] =  {"Carlos", carro[3][2], 0,  4},
        [3][3] =  {"Hylson", carro[3][3], 0,  7}
    };
 
    

    int sair = 0;
    int sub_sair = 0;
    int comando;
    int vitorias = 0;

    //string _nome(nome);
    Banco banco = {(float)10000, (float)0, (float)0.01, (float)0};
    Jogador jogador =  {"", carro_padrao, banco, 0};

    printf("\nPrimeiramente compre um carro, voce tem R$10000,\ndepois faca corridas para ganhar dinheiro,\nmelhorar seu carro ou comprar novos,\ne subir de nivel\n\n");

    //loop principal
    while(!sair){
        sub_sair = 0;

        printf("O que voce deseja fazer?\n");
        printf("-------------------------------------\n");
        printf("Para correr digite: 1\n");
        printf("Para ver e melhorar seu carro: 2\n");
        printf("Para ver seu dinheiro digite: 3\n");
        printf("Para ir a loja de carros digite: 4\n");
        printf("Para saber seu status: 5\n");
        printf("Para Sair digite: 6\n\n");


        scanf("%d", &comando);

        switch (comando)
        {
        case 1:
            printf("Selecionado: Correr\n");
            int i1;
            i1 = jogador.carro.categoria;
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
                    sub_sair = 1;
                }
                if(aceita_corrida_num(&jogador, j)){
                    if(resultado(jogador, npc[i1][j])){
                        printf("Voce ganhou, parabens!\n");
                        ganhou(&jogador);
                        vitorias++;
                        if(vitorias%10 == 0 && jogador.nivel<10){
                            jogador.nivel++;
                            printf("Parabens, voce subiu de nivel, agora seu nivel é: %d", jogador.nivel);
                        }
                        
                    }
                    else{
                        printf("Voce perdeu, que pena, saldo atual: R$%.2f\n", jogador.banco.saldo);
                    }
                }
            }
            break;

        case 2:
            printf("Selecionado: Carro\n");
            char* sub_comando;
                while (!sub_sair){
                    printf("Seu carro:\n");
                    print_veiculo(jogador.carro);
                    printf("Deseja aumentar o nivel do seu carro por R$20.000?(s/n)");
                    scanf("%s", sub_comando);
                    if(!strcmp(sub_comando, "n") || !strcmp(sub_comando, "N")){
                        sub_sair = 1;
                    }
                    else {
                        if(!strcmp(sub_comando, "s") || !strcmp(sub_comando, "S")){
                            melhorar_carro(&jogador);
                        }
                        else{
                            printf("Comando inválido");
                        }
                    }
                }   
            break;

        case 3:
            printf("Selecionado: Banco\n");
            printf("Banco nao operante\n");
            break;

        case 4:
            printf("Selecionado: Comprar\n");
            char* v1;
            while(!sub_sair){
                for(int i = 0; i<4 ; i++){
                    for(int j = 0; j<4; j++){
                        printf("%d %d -> ", i, j);
                        //carro[i][j]->print();
                        print_veiculo(carro[i][j]);
                        printf("-----------------------------------------------------------------------------------------\n");
                    }
                }
                printf("Qual carro deseja comprar?(caso não queira digite 'n')");
                scanf("%s", v1);
                if(!strcmp(v1, "n") || !strcmp(v1, "N")){
                    sub_sair = 1;
                }
                else {
                    int a2, a1 = atoi(v1);
                    printf("Proximo numero: ");
                    scanf("%d", &a2);
                    printf("%d %d\n", a1, a2);
                    if((a1 >=0 && a1 <4) && (a2 >=0 && a2 <4)){
                        //jogador->comprar(carro[a1][a2]);
                        comprar(&jogador, carro[a1][a2]);
                    }
                }
            }
            break;

        case 5:
                print_jogador(jogador);
            break;

        case 6:
            printf("Selecionado: Sair\n");
            sair = 1;
            break;
        
        default:
            printf("comando não correspondente, tente de novo:\n");
            break;
        }
    }
}