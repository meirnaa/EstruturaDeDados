#include "matsim.h"
#include <stdio.h>
#include <stdlib.h>

MatSim* criar_matsim(int n){ 
    int s = n*(n+1)/2;

    MatSim* mat = (MatSim*)malloc(sizeof(MatSim)); 
    mat->dim = n; 
    mat->v = (float*)malloc(s * sizeof(float)); 

    return mat; 
} 

float acessar_matsim(MatSim* mat, int i, int j){ 
    int k; 
    if (i<0 || i>=mat->dim || j<0 || j>=mat->dim){ 
        printf("Acesso inválido!\n"); 
        exit(1); 
    } 

    if (i>=j) 
    k = i*(i+1)/2 + j; 
    else 
    k = j*(j+1)/2 + i; 

    return mat->v[k]; 
}

void atribuir_matsim(MatSim* mat, int i, int j, float v){
    int k; 
    if (i<0 || i>=mat->dim || j<0 || j>=mat->dim) {
        printf("Atribuição inválida!\n");
        exit(1);
    }
 
    if (i>=j) 
    k = i*(i+1)/2 + j; 
    else 
    k = j*(j+1)/2 + i; 

    mat->v[k] = v; 
}

void listar_matsim(MatSim* mat){
    printf("\nSua matriz: \n\n");
    for(int i = 0; i < mat->dim; i++){
        for(int j = 0; j < mat->dim; j++){
            printf(" %d", (int)acessar_matsim(mat, i, j));
        }
        printf("\n");
    }
}

void liberar_matsim(MatSim* mat){
    free(mat->v);
    free(mat);
}

int dimensao_matsim(MatSim* mat){
    return mat->dim;
}
