#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <ctype.h>

int main() {
    char entrada[100] = "1 2 +"; 

    Pilha *pilhaOperandos = criarPilha();

    for (int i = 0; entrada[i] != '\0'; i++) {
        if (isdigit(entrada[i])) {
            int operando = 0;
            while (isdigit(entrada[i])) {
                operando = operando * 10 + (entrada[i] - '0');
                i++;
            }
            empilhar(pilhaOperandos, operando);
        } else if (isalpha(entrada[i])) {
            int operando = desempilhar(pilhaOperandos);
            char funcao[4] = {0}; 
            int j = 0;
            while (isalpha(entrada[i]) && j < 3) {
                funcao[j++] = entrada[i++];
            }
            empilhar(pilhaOperandos, aplicarFuncao(funcao, operando));
            i--;  
        } else if (entrada[i] == '+' || entrada[i] == '-' || entrada[i] == '*' || entrada[i] == '/') {
            
            int operando2 = desempilhar(pilhaOperandos);
            int operando1 = desempilhar(pilhaOperandos);

            switch (entrada[i]) {
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
            }
        }
    }

    
    int resultado = topo(pilhaOperandos);
    printf("Resultado: %d\n", resultado);

    liberarPilha(pilhaOperandos);

    return 0;
}