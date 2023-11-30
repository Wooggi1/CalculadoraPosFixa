#ifndef PILHA_H
#define PILHA_H

#define ERRO -1
#define SIM 1
#define NAO 0

typedef struct Item
{
    float chave;
    struct Item *Proximo;
} Item;

typedef struct Pilha
{
    Item *Topo;
} Pilha;

Pilha *criarPilha();
int estaVazia(Pilha *p);
Item *criarItem(float x);
void empilhar(Pilha *p, float chave);
float desempilhar(Pilha *p);
float topo(Pilha *p);
void liberarPilha(Pilha *p);
float aplicarFuncao(char *funcao, float operando);
char *postFixToInfix(char *entrada);
#endif
