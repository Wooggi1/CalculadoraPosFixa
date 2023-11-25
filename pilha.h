#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    float num;
    Item *prox;
} Item;

typedef struct Pilha {
    Item *topo;
} Pilha;

int estavazia(Pilha a);
Pilha criarPilha();
void destruirPilha(Pilha a);
float somar(Pilha a);
float subtrair(Pilha a);
float multiplicar(Pilha a);
float dividir(Pilha a);
float logaritmo(Pilha a);
float cosseno(Pilha a);
float seno(Pilha a);
float tangente(Pilha a);
