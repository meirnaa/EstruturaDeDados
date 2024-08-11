#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Ponto* criar(float x, float y) {
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if (p == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }

    p->x = x;
    p->y = y;

    return p;
}

void liberar(Ponto *p){
    free(p);
}

void acessar(Ponto* p, float* x, float* y){
    *x = p->x;
    *y = p->y;
}

float calcularDistancia(Ponto* p1, Ponto* p2){
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx*dx + dy*dy);
}

void atribuir(Ponto* p, float x, float y){
    p->x = x;
    p->y = y;
}

void enter_to_continue(){
    printf("\n<enter> to continue...");
    getchar(); 
    while (getchar() != '\n'); // Limpa o buffer de entrada
    system("cls");
}
