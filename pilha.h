#ifndef PILHA_H
#define PILHA_H

#define ERRO -1
#define SIM 1
#define NAO 0

typedef struct Item
{
    int chave;
    struct Item *Proximo;
} Item;

typedef struct Pilha
{
    Item *Topo;
} Pilha;

Pilha *criarPilha();
int estaVazia(Pilha *p);
Item *criarItem(int x);
void empilhar(Pilha *p, int chave);
int desempilhar(Pilha *p);
int topo(Pilha *p);
void liberarPilha(Pilha *p);
int aplicarFuncao(char* funcao, int operando);

#endif
