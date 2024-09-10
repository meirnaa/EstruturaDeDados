#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX 8

typedef struct node{
    char value;
    struct node* next;
}Node;

typedef struct stack{
    Node* top;
    int actual_size;
    int max_size;
}Stack;

int win_game(Stack* r, Stack* g, Stack* b, int movimentos);
void menuFacil();
void menuMedioDificil();
char* getOpcao();
char getOpcao2();
void clear_input_buffer();
int opcaoValida(const char* op);
void atualizarTorres(Stack* r, Stack* g, Stack* b, const char* op, int* movimentos);
Stack* copiarTorre(Stack* p);
int opValida(char op);
char decifrarNum(int num);
int contemTodos(int r, int g, int b);
Stack* criar_R_NivelF();
Stack* criar_R_NivelM();
Stack* criar_RB_NivelD();
Stack* criar_G_NivelD();
Stack* criar_GB_NivelM();
Stack* criar(int max);
int getNivel();
void push(Stack* p, char v);
char pop(Stack* p);
int is_empty(Stack* p);
int is_full(Stack* p);
void liberar(Stack* p);
void show(Stack* r, Stack* g, Stack* b, int movimentos);
int can_push(Stack* p);
int can_pop(Stack* p);