#include "hanoi.h"
static char *opcao = NULL;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    Stack* R = criar_R();
    Stack* RCop = copiarTorre(R);
    Stack* G = criar(MAX);
    Stack* B = criar(MAX);
    int continuar = 0;
    int movimentos = 0;
    int op1 = 5, op2 = 5;

    while(continuar == 0){
        if(!(op1 == 1)){
            printf("\n\n                        ▂▃▄▅▆▇█▓▒░  Hanói RGB  ░▒▓█▇▆▅▄▃▂\n");
            menu();
        }
        show(R, G, B, movimentos);
        opcao = getOpcao();
        atualizarTorres(R, G, B, opcao, &movimentos);
        continuar = win_game(R, G, B, movimentos);

        if(continuar == 0){
            printf("\n \
    1 - Continuar jogando \n \
    2 - Reiniciar \n \
    3 - Novo jogo \n \
    0 - Sair \n\n \
    >>> ");
            while (scanf("%d", &op1) != 1) {
                printf("\n        Opção inválida! Digite novamente: ");
                clear_input_buffer(); 
            }

            while(!opValida(op1, 1)){
                if(op1 == 1){
                    break;
                }
                else if(op1 == 2){
                    liberar(R);
                    R = copiarTorre(RCop);
                    liberar(G);
                    liberar(B);
                    G = criar(MAX);
                    B = criar(MAX);
                    movimentos = 0;
                    break;
                }
                else if(op1 == 3){
                    liberar(R);
                    R = criar_R();
                    liberar(RCop);
                    RCop = copiarTorre(R);
                    liberar(G);
                    liberar(B);
                    G = criar(MAX);
                    B = criar(MAX);
                    movimentos = 0;
                    break;
                }else if(op1 == 0){
                    exit(1);
                }
            }

        } else {
            printf("\n \
    1 - Novo jogo \n \
    2 - Reiniciar \n \
    0 - Sair \n\n \
    >>> ");
            while (scanf("%d", &op2) != 1) {
                printf("\n        Opção inválida! Digite novamente: ");
                clear_input_buffer(); 
            }

            while(!opValida(op2, 2)){
                if(op2 == 1){
                    liberar(R);
                    R = criar_R();
                    liberar(RCop);
                    RCop = copiarTorre(R);
                    liberar(G);
                    liberar(B);
                    G = criar(MAX);
                    B = criar(MAX);
                    movimentos = 0;
                    continuar = 0;
                    op1 = 5;
                    break;
                } else if(op2 == 2){
                    liberar(R);
                    R = copiarTorre(RCop);
                    liberar(G);
                    liberar(B);
                    G = criar(MAX);
                    B = criar(MAX);
                    movimentos = 0;
                    continuar = 0;
                    op1 = 5;
                    break;
                } else if(op2 == 0){
                    exit(1);
                }
            }
        }
    }

    liberar(RCop);
    liberar(R);
    liberar(G);
    liberar(B);
    return 0;
}
