#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <ctype.h>
#include <math.h>

int main() {
    char entrada[100] = "10 log 3 ^ 2 +"; 

    Pilha *pilhaOperandos = criarPilha();

    for (int i = 0; entrada[i] != '\0'; i++) {
        if (isdigit(entrada[i])) {
            int operando = 0;
            while (isdigit(entrada[i])) {
                operando = operando * 10 + (entrada[i] - '0');
                i++;
            }
            empilhar(pilhaOperandos, operando);
            //printf("numero no topo da pilha: %d\n", operando);
        } else if (isalpha(entrada[i])) {
            int operando = desempilhar(pilhaOperandos);
            char funcao[4] = {0}; 
            int j = 0;
            while (isalpha(entrada[i]) && j < 3) {
                funcao[j++] = entrada[i++];
            }
            empilhar(pilhaOperandos, aplicarFuncao(funcao, operando));
            //printf("numero no topo da pilha: %d\n", operando);
            i--;  
        } else if (entrada[i] == '+' || entrada[i] == '-' || entrada[i] == '*' || entrada[i] == '/' || entrada[i] == '^') {
            
            int operando2 = desempilhar(pilhaOperandos);
            int operando1 = desempilhar(pilhaOperandos);

            switch (entrada[i]) {
                case '+':
                    empilhar(pilhaOperandos, operando1 + operando2);
                    printf("numero no topo da pilha: %d\n", topo(pilhaOperandos));
                    break;
                case '-':
                    empilhar(pilhaOperandos, operando1 - operando2);
                    printf("numero no topo da pilha: %d\n", topo(pilhaOperandos));
                    break;
                case '*':
                    empilhar(pilhaOperandos, operando1 * operando2);
                    printf("numero no topo da pilha: %d\n", topo(pilhaOperandos));
                    break;
                case '/':
                    empilhar(pilhaOperandos, operando1 / operando2);
                    printf("numero no topo da pilha: %d\n", topo(pilhaOperandos));
                    break;
                case '^':
                    double result = pow(operando2, operando1);
                    int resultadoInteiro = (int)result;
                    empilhar(pilhaOperandos, resultadoInteiro);
                    printf("operando 1: %d\n", operando1);
                    printf("operando 2: %d\n", operando2);
                    printf("resultado potencia: %d\n", resultadoInteiro);
                    break;
            }
        }
    }

    
    int resultado = topo(pilhaOperandos);
    printf("Resultado: %d\n", resultado);

    liberarPilha(pilhaOperandos);

    return 0;
}