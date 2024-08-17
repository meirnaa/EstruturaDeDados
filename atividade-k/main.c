#include "lista.h"
#include <stdio.h>
#include <windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    Lista* lista = criar_lista();
    listar(lista);
    lista = inserir_inicio(lista, 6);
    lista = inserir_inicio(lista, 25);
    lista = inserir_inicio(lista, 90);
    listar(lista);
    lista = remover_inicio(lista);
    listar(lista);
    lista = remover_final(lista);
    listar(lista);
    lista = inserir_final(lista, 99);
    lista = inserir_final(lista, 32);
    listar(lista);
    lista = retirar(lista, 99);
    listar(lista);
    Lista* p = criar_lista();
    p = buscar(lista, 32);
    if(p == NULL){
        printf("O valor não foi encontrado.");
    }else{
        printf("O valor %d foi encontrado na lista.", p->info);
    }
    printf("\n\n");
    liberar(p);
    liberar(lista);
    return 0;
}
