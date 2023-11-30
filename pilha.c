#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

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
float aplicarFuncao(char *funcao, Pilha *p)
{
    float operando;
    if (strcmp(funcao, "log") == 0 || strcmp(funcao, "sen") == 0 || strcmp(funcao, "cos") == 0 || strcmp(funcao, "tan") == 0)
    {
        operando = desempilhar(p);
    }

    if (strcmp(funcao, "log") == 0)
    {
        return (float)log10(operando);
    }
    else if (strcmp(funcao, "sen") == 0)
    {
        return (float)sin(operando);
    }
    else if (strcmp(funcao, "cos") == 0)
    {
        return (float)cos(operando);
    }
    else if (strcmp(funcao, "tan") == 0)
    {
        return (float)tan(operando);
    }
    else
    {
        printf("Função desconhecida: %s\n", funcao);
        exit(ERRO);
    }
}
int estaVazia(Pilha *p)
{
    return p->Topo == NULL ? SIM : NAO;
}

Item *criarItem(float x)
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

void empilhar(Pilha *p, float chave)
{
    Item *novoItem = criarItem(chave);
    novoItem->Proximo = p->Topo;
    p->Topo = novoItem;
}

float desempilhar(Pilha *p)
{
    if (estaVazia(p))
    {
        printf("Erro: Pilha vazia, não é possível desempilhar.\n");
        exit(ERRO);
    }
    Item *temp = p->Topo;
    float chave = temp->chave;
    p->Topo = temp->Proximo;
    free(temp);
    return chave;
}

float topo(Pilha *p)
{
    if (estaVazia(p))
    {
        printf("Erro: Pilha vazia, não há elementos para visualizar.\n");
        exit(ERRO);
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
