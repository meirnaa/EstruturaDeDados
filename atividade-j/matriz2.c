#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include "matriz.h"

struct matriz {
    int lin;
    int col;
    float** v;
};

Matriz* criar(int m, int n){
    int i;
    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
    
    if (mat == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }

    mat->lin = m;
    mat->col = n;
    mat->v = (float**) malloc(m*sizeof(float*));

    for (i=0; i<m; i++){
        mat->v[i] = (float*) malloc(n*sizeof(float));
    }

    return mat;
}

void listar(Matriz* mat){
    printf("\nSua matriz: \n\n");
    for(int i = 0; i < mat->lin; i++){
        for(int j = 0; j < mat->col; j++){
            printf(" %d", (int)mat->v[i][j]);
        }
        printf("\n");
    }
}

void liberar(Matriz* mat){
    int i;
    for (i=0; i<mat->lin; i++)
    free(mat->v[i]);
    free(mat->v);
    free(mat);
}

float acessar(Matriz* mat, int i, int j){
    if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {
        printf("Acesso inválido!\n");
        exit(1);
    }

    return mat->v[i][j];
}

void atribuir(Matriz* mat, int i, int j, float v){
    if (i<0 || i>=mat->lin || j<0 || j>=mat->col) {
        printf("Atribuição inválida!\n");
        exit(1);
    }
    
    mat->v[i][j] = v;
}

int linhas(Matriz* mat){
    return mat->lin;
}

int colunas(Matriz* mat){
    return mat->col;
}

int verificar_simetria(Matriz* mat) {
    if (mat->lin != mat->col) {
        return 0;
    }

    int n = mat->lin;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (mat->v[i][j] != mat->v[j][i]) {
                return 0; 
            }
        }
    }

    return 1; 
}

Matriz* transposta(Matriz* mat){
    Matriz* copia = criar(mat->col, mat->lin);
    
    for (int i = 0; i < mat->lin; i++) {
        for (int j = 0; j < mat->col; j++) {
            copia->v[j][i] = mat->v[i][j];
        }
    }
    
    return copia;
}

void enter_to_continue(){
    printf("\n<enter> to continue...");
    getchar(); 
    while (getchar() != '\n'); // Limpa o buffer de entrada
    system("cls");
}
