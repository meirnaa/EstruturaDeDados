#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct node{
    float value;
    struct node* next;
}Node;

typedef struct stack{
    Node* top;
    int actual_size;
    int max_size;
}Stack;

Stack* criar(int max);
void push(Stack* p, float v);
float pop(Stack* p);
int is_empty(Stack* p);
int is_full(Stack* p);
void liberar(Stack* p);
void show(Stack* p);
int can_push(Stack* p);
int can_pop(Stack* p);