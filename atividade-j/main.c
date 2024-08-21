#include "matriz.h"
#include "matsim.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    printf("------ MATRIZES ------\n");
    Matriz* minha_matriz;
    minha_matriz = criar(3, 3);
    atribuir(minha_matriz, 0, 0, 1);
    atribuir(minha_matriz, 0, 1, 4);
    atribuir(minha_matriz, 0, 2, 7);
    atribuir(minha_matriz, 1, 0, 4);
    atribuir(minha_matriz, 1, 1, 5);
    atribuir(minha_matriz, 1, 2, 8);
    atribuir(minha_matriz, 2, 0, 7);
    atribuir(minha_matriz, 2, 1, 8);
    atribuir(minha_matriz, 2, 2, 9);
    listar(minha_matriz);
    printf("\nMatriz é simétrica (1 - SIM, 0 - NAO)? %d\n", verificar_simetria(minha_matriz));
    printf("\nNúmero localizado na 1° Linha e 1° Coluna é: %d\n", (int)acessar(minha_matriz, 1, 1));
    atribuir(minha_matriz, 2, 1, 11);
    printf("\nValor alterado!");
    listar(minha_matriz);
    printf("\nNova Matriz é simétrica (1 - SIM, 0 - NAO)? %d\n", verificar_simetria(minha_matriz));
    printf("\nMatriz transposta ->");
    Matriz* nova_matriz = transposta(minha_matriz);
    liberar(minha_matriz);
    listar(nova_matriz);
    liberar(nova_matriz);

    //PARTE DE QUADRADA SIMÉTRICA
    enter_to_continue();
    printf("------ MATRIZ QUADRADA SIMÉTRICA ------\n");
    MatSim* matriz = criar_matsim(3);
    atribuir_matsim(matriz, 0, 0, 1);
    atribuir_matsim(matriz, 0, 1, 4);
    atribuir_matsim(matriz, 0, 2, 7);
    atribuir_matsim(matriz, 1, 0, 4);
    atribuir_matsim(matriz, 1, 1, 5);
    atribuir_matsim(matriz, 1, 2, 8);
    atribuir_matsim(matriz, 2, 0, 7);
    atribuir_matsim(matriz, 2, 1, 8);
    atribuir_matsim(matriz, 2, 2, 9);
    listar_matsim(matriz);
    printf("\n\nDimensão da matriz quadrática: %d\n\n", dimensao_matsim(matriz));
    liberar_matsim(matriz);
    return 0;
}
