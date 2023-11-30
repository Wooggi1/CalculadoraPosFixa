#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define SIM 1
#define NAO 0
#define ERRO -1

typedef struct Item
{
    float chave;
    struct Item *Proximo;
} Item;

typedef struct
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
float aplicarFuncao(char *funcao, Pilha *p);
char *postFixToInfix(char entrada[]);

#endif // PILHA_H_INCLUDED
