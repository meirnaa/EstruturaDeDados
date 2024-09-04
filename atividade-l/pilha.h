#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define MAX 5

typedef struct pilha{
    int n;
    float vet[MAX];
}Pilha;

Pilha* criar(void);
void push(Pilha* p, float v);
float pop(Pilha* p);
int is_empty(Pilha* p);
int is_full(Pilha* p);
void liberar(Pilha* p);
void show(Pilha* p);
int can_push(Pilha* p);
int can_pop(Pilha* p);
