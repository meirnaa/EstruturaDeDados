#ifndef PONTO_H
#define PONTO_H

#include <stdio.h>

typedef struct ponto {
    float x;
    float y;
}Ponto; 

/* Função cria
** Aloca e retorna um ponto com coordenadas (x,y)
*/
Ponto* criar(float x, float y);

/* Função libera
** Libera a memória de um ponto previamente criado.
*/
void liberar(Ponto* p);

/* Função acessa
** Devolve os valores das coordenadas de um ponto
*/
void acessar(Ponto* p, float* x, float* y);

/* Função atribui
** Atribui novos valores às coordenadas de um ponto
*/
void atribuir(Ponto* p, float x, float y);

/* Função distancia
** Retorna a distância entre dois pontos
*/
float calcularDistancia(Ponto* p1, Ponto* p2);

void enter_to_continue();

#endif
