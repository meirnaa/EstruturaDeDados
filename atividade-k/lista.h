#ifndef LISTA_H
#define LISTA_H

struct lista {
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* criar_lista(); 
Lista* inserir_inicio(Lista* lista, int i); 
void listar(Lista* lista); 
int vazia(Lista* lista); 
Lista* remover_inicio(Lista* lista); 
Lista* inserir_final(Lista* lista, int i); 
Lista* remover_final(Lista* lista); 
Lista* buscar(Lista *lista, int i);
Lista* retirar(Lista *lista, int i); 
Lista* liberar(Lista *lista); 

#endif 
