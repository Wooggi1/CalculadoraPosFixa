#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <ctype.h>
#include <math.h>
#include <string.h>

// Adicionar declarações de funções
float aplicarFuncao(char *funcao, Pilha *p);
char *postFixToInfix(char entrada[]);

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
