#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <ctype.h>
#include <math.h>
#include <string.h>

float aplicarFuncao(char *funcao, Pilha *p);

char *postFixToInfix(char entrada[])
{
    Pilha *temp = criarPilha();
    char *saida = (char *)malloc(100 * sizeof(char));

    if (saida == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(ERRO);
    }

    saida[0] = '\0'; // Inicialize a string

    for (int i = 0; entrada[i] != '\0'; i++)
    {
        if (isdigit(entrada[i]) || (entrada[i] == '.' && isdigit(entrada[i + 1])))
        {
            double operando = strtod(&entrada[i], NULL);
            while (isdigit(entrada[i]) || entrada[i] == '.')
            {
                i++;
            }
            empilhar(temp, operando);

            char temporaria[100];
            sprintf(temporaria, "%.2f ", operando);
            strcat(saida, temporaria);
        }
        else if (isalpha(entrada[i]))
        {
            char funcao[5] = {0}; // Aumente o tamanho para 5 para acomodar "sen", "cos", "tan", etc.
            int j = 0;
            while (isalpha(entrada[i]) && j < 4)
            {
                funcao[j++] = entrada[i++];
            }
            char temporaria[100];
            sprintf(temporaria, "%s(%.2f) ", funcao, desempilhar(temp));
            strcat(saida, temporaria);
        }
        else if (entrada[i] == '+' || entrada[i] == '-' || entrada[i] == '*' || entrada[i] == '/' || entrada[i] == '^')
        {
            float operando2 = desempilhar(temp);
            float operando1 = desempilhar(temp);

            char temporario2[100];
            sprintf(temporario2, "(%.2f %c %.2f) ", operando1, entrada[i], operando2);
            strcat(saida, temporario2);

            empilhar(temp, operando1);
            empilhar(temp, operando2);
        }
    }

    liberarPilha(temp);

    return saida;
}

int main()
{
    char entrada[100];
    printf("Digite a expressao: ");
    fgets(entrada, 100, stdin);

    Pilha *pilhaOperandos = criarPilha();

    for (int i = 0; entrada[i] != '\0'; i++)
    {
        if (isdigit(entrada[i]) || (entrada[i] == '.' && isdigit(entrada[i + 1])))
        {
            double operando = strtod(&entrada[i], NULL);
            while (isdigit(entrada[i]) || entrada[i] == '.')
            {
                i++;
            }
            empilhar(pilhaOperandos, operando);
        }
        else if (isalpha(entrada[i]))
        {
            char funcao[5] = {0}; // Aumente o tamanho para 5 para acomodar "sen", "cos", "tan", etc.
            int j = 0;
            while (isalpha(entrada[i]) && j < 4)
            {
                funcao[j++] = entrada[i++];
            }
            empilhar(pilhaOperandos, aplicarFuncao(funcao, pilhaOperandos));
            i--;
        }
        else if (entrada[i] == '+' || entrada[i] == '-' || entrada[i] == '*' || entrada[i] == '/' || entrada[i] == '^')
        {
            float operando2 = desempilhar(pilhaOperandos);
            float operando1 = desempilhar(pilhaOperandos);

            switch (entrada[i])
            {
            case '+':
                empilhar(pilhaOperandos, operando1 + operando2);
                break;
            case '-':
                empilhar(pilhaOperandos, operando1 - operando2);
                break;
            case '*':
                empilhar(pilhaOperandos, operando1 * operando2);
                break;
            case '/':
                empilhar(pilhaOperandos, operando1 / operando2);
                break;
            case '^':
                empilhar(pilhaOperandos, pow((double)operando1, (double)operando2));
                break;
            }
        }
    }

    char *saida = postFixToInfix(entrada);
    float resultado = topo(pilhaOperandos);
    printf("Resultado: %.3f\n", resultado);
    printf("Expressao infixa: %s\n", saida);

    liberarPilha(pilhaOperandos);

    return 0;
}
