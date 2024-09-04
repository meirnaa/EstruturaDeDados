#include "pilha.h"

int main(){
    SetConsoleOutputCP(CP_UTF8);

    printf("\n\n+ CRIANDO PILHA\n\n");
    Pilha* pilha = criar();

    printf("\n\n+ POP EM PILHA VAZIA (-1)\n\n");
    float num = pop(pilha);
    printf("\nNúmero removido: %d\n", (int)num);

    printf("\n\n+ PUSH 10 E 9\n\n");
    push(pilha, 10);
    push(pilha, 9);
    show(pilha);

    printf("\n\n+ PUSH 8, 7 E 6\n\n");
    push(pilha, 8);
    push(pilha, 7);
    push(pilha, 6);
    show(pilha);

    printf("\n\n+ PUSH 5 (ESTOURO)\n\n");
    push(pilha, 5);

    printf("\n\n\n+ POP (6)\n\n");
    num = pop(pilha);
    printf("\nNúmero removido: %d\n", (int)num);

    printf("\n\n+ APÓS NUMERO RETIRADO\n\n");
    show(pilha);

    printf("\n\n+ LIBERANDO E SAINDO\n\n");
    liberar(pilha);
    return 0;
}