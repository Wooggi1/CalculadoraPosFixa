#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    Pilha *minhaPilha = criarPilha();

    empilhar(minhaPilha, 10);
    empilhar(minhaPilha, 20);
    empilhar(minhaPilha, 30);

    printf("Topo da pilha: %d\n", topo(minhaPilha));

    printf("Desempilhando: %d\n", desempilhar(minhaPilha));
    printf("Desempilhando: %d\n", desempilhar(minhaPilha));

    printf("Topo da pilha após desempilhar: %d\n", topo(minhaPilha));

    liberarPilha(minhaPilha);

    return 0;
}
