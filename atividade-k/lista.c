#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista* criar_lista(){
    return NULL;
}

Lista* inserir_inicio(Lista* lista, int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = lista;

    return novo;
}

void listar(Lista* lista){
    printf(". . . . . ITENS DA LISTA . . . . .\n\n");
    if(vazia(lista)){
        printf("\n Lista Vazia\n\n");
    }else{
        for(Lista* p = lista; p != NULL; p = p->prox){
            printf(" %d\n", p->info);
        }
        printf("\n");
    }
}

int vazia(Lista* lista){
    return lista == NULL;
}

Lista* remover_inicio(Lista* lista){
    if(vazia(lista)){
        printf("\n Lista Vazia\n\n");
        return lista;
    }

    Lista* proximo = lista->prox;
    free(lista);

    return proximo;
}

Lista* inserir_final(Lista* lista, int i){
    if(vazia(lista)){
        return inserir_inicio(lista, i);
    }

    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;

    Lista* ultimo = lista;
    while(ultimo->prox != NULL){
        ultimo = ultimo->prox;
    }

    ultimo->prox = novo;
    novo->prox = NULL;

    return lista;
}

Lista* remover_final(Lista* lista){
    if(vazia(lista)){
        printf("\n Lista Vazia\n\n");
        return lista;
    }

    Lista* ultimo = lista;
    
    while(ultimo->prox != NULL){
        ultimo = ultimo->prox;
    }

    if(ultimo == lista){
        return remover_inicio(ultimo);
    }

    Lista* penultimo = lista;
    while(penultimo->prox != ultimo){
        penultimo = penultimo->prox;
    }

    free(ultimo);
    penultimo->prox = NULL;

    return lista;
}

Lista* buscar(Lista *lista, int i){
    Lista *p;
    for(p = lista; p != NULL; p = p->prox){
        if(p->info == i)
            return p;
    }

    return NULL;
}

Lista* retirar(Lista *lista, int i){
    Lista* ant = NULL; 
    Lista* p = lista;

    while (p != NULL && p->info != i) {
        ant = p;
        p = p->prox;
    }
    
    if(p == NULL){
        return lista;
    }
    
    if(ant == NULL){
        lista = p->prox;
    }
    else{
        ant->prox = p->prox;
    }

    free(p);
    return lista;
}

Lista* liberar(Lista *lista){
    Lista *p = lista;
    while(p != NULL){
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}
