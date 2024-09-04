#include "pilha.h"

Pilha* criar(void){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}

void push(Pilha* p, float v){
    if(!can_push(p)){
        printf("\nCapacidade da pilha estourou.");
        return;
    }

    p->vet[p->n] = v;
    p->n++;
}

float pop(Pilha* p){
    if(!can_pop(p)){
        printf("\nA pilha está vazia.");
        return -1;
    }

    float v = p->vet[p->n-1];
    p->n--;
    return v;
}

int is_empty(Pilha* p){
    return p->n == 0;
}

int is_full(Pilha* p){
    return p->n == MAX;
}

void liberar(Pilha* p){
    free(p);
}

void show(Pilha* p){
    if(is_empty(p)){
        printf("\nPilha vazia!\n");
        return;
    }

    for(int i = p->n-1; i >= 0; i--){
        printf("\n____\n\n");
        printf(" %d", (int)p->vet[i]);
    }
    printf("\n____\n");
}

int can_push(Pilha* p){
    int res = is_full(p);
    return res == 0;
}

int can_pop(Pilha* p){
    int res = is_empty(p);
    return res == 0;
}