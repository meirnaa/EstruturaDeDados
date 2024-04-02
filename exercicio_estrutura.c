#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct ponto {
 int x;
 int y;
} Ponto; 

typedef struct circulo {
 Ponto p;
 int raio;
} Circulo; 

void mostraCirculo(Circulo *c, char elemento[3]);
void atribuiAleatorio(Circulo *c);
void atribuiAleatorioVetor(Circulo *c, int n);
void mostraCirculoVetor(Circulo *c, int n);

int main(){
SetConsoleOutputCP(CP_UTF8);

//Questão1
    Ponto p1;
    p1.x = 0;
    p1.y = 0;

    printf("\nAtribuindo valores para um ponto p1\n");
    printf("\nDigite o valor de x: ");
    scanf("%d", &p1.x);

    printf("Digite o valor de y: ");
    scanf("%d", &p1.y);
    printf("\n------------------------------------------------------------\n");
//Questão2
    Circulo c1;
    c1.p.x = 0;
    c1.p.y = 0;
    c1.raio = 0;

    printf("\nAtribuindo valores para um círculo c1\n");
    printf("\nDigite as coordenadas do ponto (x, y): ");
    scanf("%d" "%d", &c1.p.x, &c1.p.y);

    printf("Digite o valor do raio: ");
    scanf("%d", &c1.raio);
    printf("\n------------------------------------------------------------\n");

//Questão3
    Circulo *c2;
    c2 = (Circulo *)malloc(sizeof(Circulo));
    c2->p.x = 0;
    c2->p.y = 0;
    c2->raio = 0;

    printf("\nAtribuindo valores para um círculo c2\n");
    printf("\nDigite as coordenadas do ponto (x, y): ");
    scanf("%d" "%d", &c2->p.x, &c2->p.y);

    printf("Digite o valor do raio: ");
    scanf("%d", &c2->raio);

    mostraCirculo(&c1, "c1");
    mostraCirculo(c2, "c2");
    printf("\n------------------------------------------------------------\n");

    printf("\nAtribuindo valores aleatórios para os círculos c1 e c2\n");
    atribuiAleatorio(&c1);
    mostraCirculo(&c1, "c1");
    
    atribuiAleatorio(c2);
    mostraCirculo(c2, "c2");
    printf("\n------------------------------------------------------------\n");

//Questão6
    Circulo *c3;
    c3 = &c1;

    printf("\nAtribuindo valores aleatórios para um círculo c3 que aponta para c1\n");
    atribuiAleatorio(c3);
    mostraCirculo(c3, "c3");

    mostraCirculo(&c1, "c1");
    printf("\n------------------------------------------------------------\n");

//Questão7
    Circulo vet[10];
    atribuiAleatorioVetor(vet, 10);
    printf("\nVetor aleatório de 10 elementos do tipo Círculo criado!\n");

//Questão 8
    mostraCirculoVetor(vet, 10);
    
    free(c2);
    return 0;
}

//Questão4
void mostraCirculo(Circulo *c, char elemento[3]){
    printf("\n------------------------------------------------------------\n");
    printf("Elementos do Círculo %s:", elemento);
    printf("\n\nPontos (x,y): (%d,%d)", c->p.x, c->p.y);
    printf("\nRaio: %d", c->raio);
}

//Questão5
void atribuiAleatorio(Circulo *c){
    // Define a semente com base no tempo atual
    srand(time(NULL));
    Sleep(1000);

    c->p.x = rand() % 100;
    c->p.y = rand() % 100;
    c->raio = rand() % 100;
}

//Questão7
void atribuiAleatorioVetor(Circulo *c, int n){
    // Define a semente com base no tempo atual
    srand(time(NULL));
    Sleep(1000);

    for(int i = 0; i < n; i++){
        c[i].p.x = rand() % 100;
        c[i].p.y = rand() % 100;
        c[i].raio = rand() % 100;
    }
}

//Questão 8
void mostraCirculoVetor(Circulo *c, int n){
    printf("\n------------------------------------------------------------\n");
    printf("\nMostrando vetor de Círculos:\n");

    for(int i = 0; i < n; i++){
        char string_numero[3];
        sprintf(string_numero, "%d", i+1);
        mostraCirculo(&c[i], string_numero);
    }
}