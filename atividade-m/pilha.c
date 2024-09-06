#include "pilha.h"

Stack* criar(int max){
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->max_size = max;
    p->actual_size = 0;
    p->top = NULL;

    return p;
}

void push(Stack* p, float v){
    if(!can_push(p)){
        printf("\nCapacidade da pilha estourou.");
        return;
    }

    Node* no = (Node*)malloc(sizeof(Node));
    no->value = v;
    no->next = p->top;
    p->top = no;
    p->actual_size++;
}

float pop(Stack* p){
    if(!can_pop(p)){
        printf("\nA pilha está vazia.");
        return -1;
    }

    float v = p->top->value;
    Node* no = p->top;
    
    p->top = p->top->next;
    p->actual_size--;

    free(no);
    return v;
}

int is_empty(Stack* p){
    return p->actual_size == 0;
}

int is_full(Stack* p){
    return p->actual_size == p->max_size;
}

void liberar(Stack* p){
    Node* no = p->top;
    while(no != NULL){
        Node* prox = no->next;
        free(no);
        no = prox;
    }

    free(p);
}

void show(Stack* p){
    if(is_empty(p)){
        printf("\nPilha vazia!\n");
        return;
    }

    Node* no;
    
    for(no = p->top; no != NULL; no = no->next){
        printf("\n____\n\n");
        printf(" %d", (int)no->value);
    }
    printf("\n____\n");
}

int can_push(Stack* p){
    int res = is_full(p);
    return res == 0;
}

int can_pop(Stack* p){
    int res = is_empty(p);
    return res == 0;
}