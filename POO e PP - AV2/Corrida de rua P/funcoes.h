#include "estruturas.h"
#include <stdlib.h>

//funcao para mostra as informações de um veiculo
void print_veiculo(Veiculo carro);

//funcao para mostra as informações de um jogador
void print_jogador(Jogador pessoa);

//funcao que efetua a compra de um veiculo, recebe uma referencia do jogador e qual carro sera comprado
int comprar(Jogador* quem, Veiculo carro);

//funcao que melhora o carro do jogador, recebe uma referencia para o jogador
int melhorar_carro(Jogador* pessoa);

//funcao que da o premio ao jogador que ganhar, recebe como argumento uma referecia ao jogador
void ganhou(Jogador* pessoa);

// funcao que faz um jogador aceitar uma corrida e efetuar o pagamento
// recebe como arguemto uma referencia do jogador que aceita e o identificador da corrida
int aceita_corrida_num(Jogador* player, int num);

// calcula o resultado da corrida e retorna 1 se o primeiro jogador vencer
int resultado(Jogador player, Jogador npc);

void print_veiculo(Veiculo carro){
    printf("%s | categoria: %d | nível: %d | potencia: %d | Preco: R$%.2f\n", carro.nome, carro.categoria, carro.nivel, carro.potencia, carro.preco);
}

void print_jogador(Jogador pessoa){
    printf("Nome: %s\n Carro:", pessoa.nome);
    print_veiculo(pessoa.carro);
    printf("Dinheiro: R$%.2f\n Nível: %d\n", pessoa.banco.saldo, pessoa.nivel);
}

int comprar(Jogador* quem, Veiculo carro){
    if(quem->banco.saldo + quem->carro.preco/2 > carro.preco){
        quem->banco.saldo = quem->banco.saldo - (carro.preco - quem->carro.preco/2);
        quem->carro = carro;
        printf("carro adquirido com sucesso!\n");
        return 1;
    }
    else{
        printf("impossivel adquirir carro!\n");
        return 0;
    }
}

int melhorar_carro(Jogador* pessoa){
    if(pessoa->banco.saldo > 20000){
        pessoa->banco.saldo = pessoa->banco.saldo - 20000;
        pessoa->carro.nivel++;
        printf("carro melhorado com sucesso!\n");
        return 1;
    }
    else{
        printf("impossivel melhorar carro!\n");
        return 0;
    }
}

void ganhou(Jogador* pessoa){
    pessoa->banco.saldo = pessoa->banco.saldo + (2*pessoa->banco.ultima_saida);
    printf("R$%.2f foram adicionados a sua conta! saldo atual: R$%.2f\n", (2*pessoa->banco.ultima_saida), pessoa->banco.saldo);
}

int aceita_corrida_num(Jogador* player, int num){
    if(num == 0){
        if(player->banco.saldo < 1000){
            return 0;
        }
        else{
            player->banco.saldo = player->banco.saldo - 1000;
            player->banco.ultima_saida = 1000;
            printf("Entrada paga, saldo atual:%.2f\n", player->banco.saldo);
            return 1;
        }
    }
    if(num == 1){
        if(player->banco.saldo < 5000){
            return 0;
        }
        else{
            player->banco.saldo = player->banco.saldo - 5000;
            player->banco.ultima_saida = 5000;
            printf("Entrada paga, saldo atual:%.2f\n", player->banco.saldo);
            return 1;
        }
    }
    if(num == 2){
        if(player->banco.saldo < 10000){
            return 0;
        }
        else{
            player->banco.saldo = player->banco.saldo - 10000;
            player->banco.ultima_saida = 10000;
            printf("Entrada paga, saldo atual:%.2f\n", player->banco.saldo);
            return 1;
        }
    }
    if(num == 3){
        if(player->banco.saldo < 30000){
            return 0;
        }
        else{
            player->banco.saldo = player->banco.saldo - 30000;
            player->banco.ultima_saida = 30000;
            printf("Entrada paga, saldo atual:%.2f\n", player->banco.saldo);
            return 1;
        }
    }
    return 0;
}

int resultado(Jogador player, Jogador npc){
    int potuacao_player, pontuacao_npc;
    potuacao_player = (rand() % player.carro.potencia + player.carro.nivel) + player.nivel;
    pontuacao_npc = (rand() % npc.carro.potencia + npc.carro.nivel) + npc.nivel;
    printf("Voce esta correndo contra %s, que possui o carro: ", npc.nome);
    print_veiculo(npc.carro);
    //ganhou
    if(potuacao_player > pontuacao_npc){
        return 1;
    }
    //se empatar tenta de novo
    else if(potuacao_player == pontuacao_npc){
        return resultado(player, npc);
    }
    //perdeu
    else{
        return 0;
    }
}