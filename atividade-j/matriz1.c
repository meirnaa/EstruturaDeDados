#include "matriz.h"
#include <stdio.h>
#include <stdlib.h> /* malloc, free, exit */
#include <stdbool.h>

struct matriz {
    int lin;
    int col;
    float* v;
};

Matriz* criar(int m, int n){
    Matriz *mat = (Matriz*)malloc(sizeof(Matriz));

    if (mat == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    
    mat->lin = m;
    mat->col = n;
    mat->v = (float*)malloc(m*n*sizeof(float));
    
    return mat;
}

Matriz* transposta(Matriz* mat){
    Matriz* copia = criar(mat->col, mat->lin);
    
    for (int i = 0; i < mat->lin; i++) {
        for (int j = 0; j < mat->col; j++) {
            copia->v[j * copia->col + i] = mat->v[i * mat->col + j];
        }
    }
    
    return copia;
}

void listar(Matriz* mat){
    printf("\nSua matriz: \n\n");
    for(int i = 0; i < mat->lin; i++){
        for(int j = 0; j < mat->col; j++){
            printf(" %d", (int)mat->v[i * mat->col + j]);
        }
        printf("\n");
    }
}

void liberar(Matriz* mat){
    free(mat->v);
    free(mat);
}

float acessar(Matriz* mat, int i, int j){
    int k; 
    if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {
        printf("Acesso inválido!\n");
        exit(1);
    }

    k = i * mat->col + j;
    return mat->v[k];
}

void atribuir(Matriz* mat, int i, int j, float v){
    int k; 
    if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {
        printf("Atribuição inválida!\n");
        exit(1);
    }
 
    k = i * mat->col + j;
    mat->v[k] = v;
}

int linhas(Matriz* mat){
    return mat->lin;
}

int colunas(Matriz* mat){
    return mat->col;
}

int verificar_simetria(Matriz* mat){
    if (mat->lin != mat->col) {
        return 0;
    }

    int n = mat->lin;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int index1 = i * n + j;
            int index2 = j * n + i;

            if (mat->v[index1] != mat->v[index2]) {
                return 0; 
            }
        }
    }

    return 1; 
}

void enter_to_continue(){
    printf("\n<enter> to continue...");
    getchar(); 
    while (getchar() != '\n'); // Limpa o buffer de entrada
    system("cls");
}
