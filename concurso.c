#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void preencher_vetor(int n, int *vetor){
    for(int i = 0; i < n; i++){
        printf("\nInscrição %d: ", i+1);
        scanf("%d", &vetor[i]);
    }
}

void preencher_vetor2(int n, float *vetor, int *inscr){
    for(int i = 0; i < n; i++){
        printf("\nNota do participante de inscrição %d: ", inscr[i]);
        scanf("%f", &vetor[i]);
    }
}

int *premiados(int n, int *inscr, float *t1, int p1,float *t2, int p2, int *tam){

    float *media = (float *)malloc(n * sizeof(float)); //Médias ponderadas dos participantes

    for (int i = 0; i < n; i++) {
        media[i] = ((t1[i] * p1) + (t2[i] * p2)) / (p1 + p2);
    }

    float maior_media = media[0]; //Encontrando maior média

    for (int i = 1; i < n; i++) {
        if (media[i] > maior_media) {
            maior_media = media[i];
        }
    }

    *tam = 0; //Contar quantos participantes têm a maior média
    for (int i = 0; i < n; i++) {
        if (media[i] == maior_media) {
            (*tam)++;
        }
    }

    int *premiados = (int *)malloc((*tam) * sizeof(int)); //Alocar dinamicamente o vetor de inscrições dos participantes premiados

    // Preencher o vetor de inscrições dos participantes premiados
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (media[i] == maior_media) {
            premiados[j] = inscr[i];
            j++;
        }
    }

    free(media);
    return premiados;

}

int main(){
    SetConsoleOutputCP(CP_UTF8);

    int n;

    printf("\nQuantidade de participantes do concurso: ");
    scanf("%d", &n);

    int inscr[n], p1, p2;
    float t1[n], t2[n];
    int tam; 

    preencher_vetor(n, inscr);

    printf("\n\n\n==================== Notas do 1° Teste ===================\n");
    printf("\nPeso da nota: ");
    scanf("%d", &p1);
    printf("\n==========================================================\n");

    preencher_vetor2(n, t1, inscr);
    
    printf("\n\n\n\n==================== Notas do 2° Teste ===================\n");
    printf("\nPeso da nota: ");
    scanf("%d", &p2);
    printf("\n==========================================================\n");

    preencher_vetor2(n, t2, inscr);

    int *premiados_lista = premiados(n, inscr, t1, p1, t2, p2, &tam);

    printf("\n==========================================================\n");
    printf("\n\nParticipantes premiados:\n");
    for (int i = 0; i < tam; i++) {
        printf("\n%d\n", premiados_lista[i]);
    }
    printf("\n");
    free(premiados_lista);

    return 0;
}