#include <stdio.h>
typedef struct 
{
    char nome[20];
    int categoria;
    int potencia;
    int nivel;
    float preco;
} Veiculo;

typedef struct 
{
    float saldo;
    float emprestimo;
    float juros;
    float ultima_saida;
} Banco;

typedef struct 
{
    char nome[20];
    Veiculo carro;
    Banco banco;
    int nivel;
} Jogador;
