#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    Ponto *ponto1, *ponto2;
    float x, y;

    char menu[] = "----------------- Ponto&Ponto ----------------\n\n \
1 - Criar Ponto 1 \n \
2 - Criar Ponto 2 \n \
3 - Mostrar Ponto 1 \n \
4 - Mostrar Ponto 2 \n \
5 - Calcular distância \n \
6 - Atribuir valores \n \
7 - Liberar pontos \n\n \
0 - Sair \n\n \
>>> ";
    int opcao;
    printf("%s", menu);
    scanf("%d", &opcao);

    while (opcao != 0) {
        if (opcao == 1) {
            printf("\nValor de x1 e y1: ");
            scanf("%f %f", &x, &y);

            ponto1 = criar(x, y);
            printf("\nPonto criado!");
        } 
        else if (opcao == 2) {
            printf("\nValor de x2 e y2: ");
            scanf("%f %f", &x, &y);

            ponto2 = criar(x, y);
            printf("\nPonto criado!");
        } 
        else if (opcao == 3) {
            acessar(ponto1, &x, &y);
            printf("\nPonto P1(%.1f, %.1f)", x, y);
        } 
        else if (opcao == 4) {
            acessar(ponto2, &x, &y);
            printf("\nPonto P2(%.1f, %.1f)", x, y);
        } 
        else if (opcao == 5) {
            float distancia = calcularDistancia(ponto1, ponto2);
            printf("\nDistância entre pontos é %.2f", distancia);
        } 
        else if (opcao == 6) {
            int op;
            printf("\nQual ponto deseja modificar (1/2)? ");
            scanf("%d", &op);
            if(op == 1){
                printf("Valor de x1 e y1: ");
                scanf("%f %f", &x, &y);

                atribuir(ponto1, x, y);
                printf("\nPonto modificado com sucesso!");
            }
            else if(op == 2){
                printf("\nValor de x2 e y2: ");
                scanf("%f %f", &x, &y);

                atribuir(ponto2, x, y);
                printf("\nPonto modificado com sucesso!");
            }
            else{
                printf("Opção inválida!");
            }
        }
        else if (opcao == 7) {
            liberar(ponto1);
            liberar(ponto2);
            printf("\nPontos liberados!");
        }
        
        printf("\n");
        enter_to_continue();
        printf("%s", menu);
        scanf("%d", &opcao);
    }

    return 0;
}
