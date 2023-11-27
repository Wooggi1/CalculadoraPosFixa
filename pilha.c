#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

Pilha *criarPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p == NULL)
    {
        printf("Erro: Falha ao alocar memória para a pilha.\n");
        exit(ERRO);
    }
    p->Topo = NULL;
    return p;
}

int estaVazia(Pilha *p)
{
    if (p->Topo == NULL)
        return SIM;
    else
        return NAO;
}

Item *criarItem(int x)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    if (novoItem == NULL)
    {
        printf("Erro: falha ao alocar memória para o item.\n");
        exit(ERRO);
    }
    novoItem->chave = x;
    novoItem->Proximo = NULL;
    return novoItem;
}

void empilhar(Pilha *p, int chave)
{
    Item *novoItem = criarItem(chave);
    novoItem->Proximo = p->Topo;
    p->Topo = novoItem;
}

int desempilhar(Pilha *p)
{
    if (estaVazia(p))
    {
        printf("Erro: Pilha vazia, não é possível desempilhar.\n");
        exit(EXIT_FAILURE);
    }
    Item *temp = p->Topo;
    int chave = temp->chave;
    p->Topo = temp->Proximo;
    free(temp);
    return chave;
}

int topo(Pilha *p)
{
    if (estaVazia(p))
    {
        printf("Erro: Pilha vazia, não há elementos para visualizar.\n");
        exit(EXIT_FAILURE);
    }
    return p->Topo->chave;
}

void liberarPilha(Pilha *p)
{
    while (!estaVazia(p))
    {
        desempilhar(p);
    }
    free(p);
}

int aplicarFuncao(char* funcao, int operando) {
    if (strcmp(funcao, "log") == 0) {
        return (int)log10(operando);
    } else if (strcmp(funcao, "sen") == 0) {
        return (int)sin(operando);
    } else if (strcmp(funcao, "cos") == 0) {
        return (int)cos(operando);
    } else if (strcmp(funcao, "tan") == 0) {
        return (int)tan(operando);
    } else {
        printf("Função desconhecida: %s\n", funcao);
        exit(EXIT_FAILURE);
    }
}
