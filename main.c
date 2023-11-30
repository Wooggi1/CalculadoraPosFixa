#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <ctype.h>
#include <math.h>
#include <string.h>

int main()
{
    char entrada[100];
    printf("Digite a expressao: ");
    fgets(entrada, 100, stdin);

    Pilha *pilhaOperandos = criarPilha();

    // Mover a declaração da variável result para o início da função main
    double result;

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
            float operando = desempilhar(pilhaOperandos);
            char funcao[4] = {0};
            int j = 0;
            while (isalpha(entrada[i]) && j < 3)
            {
                funcao[j++] = entrada[i++];
            }
            empilhar(pilhaOperandos, aplicarFuncao(funcao, operando));
            i--;
        }
        else if (entrada[i] == '+' || entrada[i] == '-' || entrada[i] == '*' || entrada[i] == '/' || entrada[i] == '^')
        {
            // Remover a declaração da variável funcao2, pois ela não é usada
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
                result = pow((double)operando1, (double)operando2);
                empilhar(pilhaOperandos, result);
                break;
            }
        }
    }

    char saida[100];
    float resultado = topo(pilhaOperandos);
    printf("Resultado: %.3f\n", resultado);
    printf("Expressao infixa: ");
    strcpy(saida, postFixToInfix(entrada));
    puts(saida);

    liberarPilha(pilhaOperandos);

    return 0;
}
