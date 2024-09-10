#include "hanoi.h"
static char* opcao = NULL;
static char op;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));
    int nivel;
    int continuar = 0;
    int movimentos;
    int new_game = 1;
    Stack* R;
    Stack* G;
    Stack* B;
    Stack* RCop;
    Stack* BCop;
    Stack* GCop;

    while(continuar == 0){
        //Iniciando novo jogo e criando Torres de acordo com o nível
        if(new_game == 1){
            printf("\n\n                        ▂▃▄▅▆▇█▓▒░  Hanói RGB  ░▒▓█▇▆▅▄▃▂\n\n\n");
            nivel = getNivel();
            switch(nivel)
            {
            case 1:
                menuFacil();
                R = criar_R_NivelF();
                RCop = copiarTorre(R);
                G = criar(MAX);
                B = criar(MAX);
                new_game = 0;
                movimentos = 0;
                break;
            
            case 2:
                menuMedioDificil();
                R = criar_R_NivelM();
                RCop = copiarTorre(R);
                G = criar_GB_NivelM();
                GCop = copiarTorre(G);
                B = criar_GB_NivelM();
                BCop = copiarTorre(B);
                new_game = 0;
                movimentos = 0;
                break;
            
            case 3:
                menuMedioDificil();
                R = criar_RB_NivelD();
                RCop = copiarTorre(R);
                G = criar_G_NivelD();
                GCop = copiarTorre(G);
                B = criar_RB_NivelD();
                BCop = copiarTorre(B);
                new_game = 0;
                movimentos = 0;
                break;
            }
        }

        //Mostrando Torres e pedindo primeira decisão
        show(R, G, B, movimentos);
        opcao = getOpcao();
        
        if(continuar == 0){
            //0 aborta o programa
            if(opcao[0] == '0'){
                exit(1);
            }
            //1 reinicia
            else if(opcao[0] == '1'){
                if(nivel == 1){
                    liberar(R);
                    R = copiarTorre(RCop);
                    liberar(G);
                    liberar(B);
                    G = criar(MAX);
                    B = criar(MAX);
                    movimentos = 0;
                    new_game = 0;
                }
                else if(nivel == 2){
                    liberar(R);
                    R = copiarTorre(RCop);
                    liberar(G);
                    G = copiarTorre(GCop);
                    liberar(B);
                    B = copiarTorre(BCop);
                    movimentos = 0;   
                    new_game = 0;                 
                }
                else if(nivel == 3){
                    liberar(R);
                    R = copiarTorre(RCop);
                    liberar(G);
                    G = copiarTorre(GCop);
                    liberar(B);
                    B = copiarTorre(BCop);
                    movimentos = 0;  
                    new_game = 0;                  
                }
            }
            //2 inicia novo jogo
            else if(opcao[0] == '2'){
                new_game = 1;
            }
            //atualiza torres com o movimento escolhido e verifica se ganhou
            else{
                new_game = 0;
                atualizarTorres(R, G, B, opcao, &movimentos);
                continuar = win_game(R, G, B, movimentos);
            }
        }

        //se ganhou pede op para reiniciar, iniciar novo jogo ou sair
        if(continuar == 1){

            op = getOpcao2();
            //Reiniciar
            if(op == '1'){
                if(nivel == 1){
                    liberar(R);
                    R = copiarTorre(RCop);
                    liberar(G);
                    liberar(B);
                    G = criar(MAX);
                    B = criar(MAX);
                    movimentos = 0;
                    continuar = 0;
                    new_game = 0;
                }
                else if(nivel == 2){
                    liberar(R);
                    R = copiarTorre(RCop);
                    liberar(G);
                    G = copiarTorre(GCop);
                    liberar(B);
                    B = copiarTorre(BCop);
                    movimentos = 0;
                    continuar = 0;     
                    new_game = 0;               
                }
                else if(nivel == 3){
                    liberar(R);
                    R = copiarTorre(RCop);
                    liberar(G);
                    G = copiarTorre(GCop);
                    liberar(B);
                    B = copiarTorre(BCop);
                    movimentos = 0;
                    continuar = 0;     
                    new_game = 0;               
                }
            } 
            //Novo jogo
            else if(op == '2'){
                new_game = 1;
                continuar = 0;
            }
            //Sair
            else if(op == '0'){
                exit(1);
            }
        }
    }

    liberar(RCop);
    liberar(R);
    liberar(G);
    liberar(B);
    return 0;
}