#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

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
        exit(EXIT_FAILURE);
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

float aplicarFuncao(char* funcao, float operando) {
    if (strcmp(funcao, "log") == 0) {
        return (float)log10(operando);
    } else if (strcmp(funcao, "sen") == 0) {
        return (float)sin(operando);
    } else if (strcmp(funcao, "cos") == 0) {
        return (float)cos(operando);
    } else if (strcmp(funcao, "tan") == 0) {
        return (float)tan(operando);
    } else {
        printf("Função desconhecida: %s\n", funcao);
        exit(1);
    }
}

char* postFixToInfix(char entrada[]) {
    Pilha *temp = criarPilha();
    char* saida = (char*)malloc(100 * sizeof(char));
    char funcao2[4];

    if (saida == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    saida[0] = '\0';  // Initialize the string

    for (int i = 0; entrada[i] != '\0'; i++) {
        if (isdigit(entrada[i]) || (entrada[i] == '.' && isdigit(entrada[i + 1]))) {
            double operando = strtod(&entrada[i], NULL);
            while (isdigit(entrada[i]) || entrada[i] == '.') {
                i++;
            }
            empilhar(temp, operando);
        } else if (isalpha(entrada[i])) {
            char funcao[4] = {0};
            int j = 0;
            while (isalpha(entrada[i]) && j < 3) {
                funcao[j++] = entrada[i++];
            }
            char temporaria[100];
            sprintf(temporaria, " %s(%.2f)", funcao, desempilhar(temp));
            strcpy(funcao2, temporaria);
        } else if (entrada[i] == '+' || entrada[i] == '-' || entrada[i] == '*' || entrada[i] == '/' || entrada[i] == '^') {
            char temporario2[100];
            
            if(isalpha(entrada[i - 2])){
                sprintf(temporario2, "%s %c %s", saida, entrada[i], funcao2);
                strcpy(saida, temporario2);
                continue;
            }
            
            float operando2 = desempilhar(temp);
            float operando1 = desempilhar(temp);
            
            sprintf(temporario2, " (%.2f %c %.2f)", operando1, entrada[i], operando2);
            strcat(saida, temporario2);
        }
    }

    return saida;
}