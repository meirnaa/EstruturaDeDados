#include "hanoi.h"

//FUNÇÕES PARA PILHA

Stack* criar(int max){
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->max_size = max;
    p->actual_size = 0;
    p->top = NULL;

    return p;
}

void push(Stack* p, char v){
    Node* no = (Node*)malloc(sizeof(Node));
    no->value = v;
    no->next = p->top;
    p->top = no;
    p->actual_size++;
}

char pop(Stack* p){
    char v = p->top->value;
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

void show(Stack* r, Stack* g, Stack* b, int movimentos){
    printf("\n\n             Movimentos efetuados: %d\n", movimentos);
    printf("\n\n\n          Torre        Torre       Torre");
    printf("\n            R            G           B  \n\n");

    char valoresR[MAX] = { ' ' }, valoresG[MAX] = { ' ' }, valoresB[MAX] = { ' ' }; 
    Node* no1 = r->top;
    Node* no2 = g->top;
    Node* no3 = b->top;

    //PREENCHENDO
    int i, countR = 0, countG = 0, countB = 0;
    for (i = 0; i < MAX && no1 != NULL; i++) {
        valoresR[i] = no1->value;
        countR++;
        no1 = no1->next;
    }

    for (i = 0; i < MAX && no2 != NULL; i++) {
        valoresG[i] = no2->value;
        countG++;
        no2 = no2->next;
    }

    for (i = 0; i < MAX && no3 != NULL; i++) {
        valoresB[i] = no3->value;
        countB++;
        no3 = no3->next;
    }

    //MOSTRANDO
    for (int i = 0; i < MAX; i++) {
        char valor1 = (i < MAX - countR) ? ' ' : valoresR[i - (MAX - countR)];
        char valor2 = (i < MAX - countG) ? ' ' : valoresG[i - (MAX - countG)];
        char valor3 = (i < MAX - countB) ? ' ' : valoresB[i - (MAX - countB)];

        printf("          | %c |        | %c |       | %c |\n", valor1, valor2, valor3);
    }
}

int can_push(Stack* p){
    int res = is_full(p);
    return res == 0;
}

int can_pop(Stack* p){
    int res = is_empty(p);
    return res == 0;
}

//FUNÇÕES PARA HANOI

void menu(){
    char menu[] = "\n \
╔═════════════════════════════════════════════════════════════════════════════╗ \n\n \
    Como jogar: \n\n \
    A Torre R nasce completamente cheia de elementos aleatórios(R, G, B). \n \
    Realize operações de movimentação entre as Torres. \n \
    Exemplo: Operação 'RB' remove elemento de Torre R e leva para Torre B.\n\n \
    Regras: \n\n \
    1) Espere a aplicação carregar.\n \
    2) O jogo encerra quando cada Torre tiver apenas elementos do seu tipo. \n \
    3) Tente fazer o menor número de movimentos possíveis! \n\n \
╚═════════════════════════════════════════════════════════════════════════════╝";
    printf("%s", menu);
}

char* getOpcao(){
    char* op = (char*)malloc(2 * sizeof(char)); 
    printf("\n\n \
    Digite o movimento (RG, RB, GR, GB, BR, BG): ");
    scanf("%s", op);

    while(!opcaoValida(op)){
        printf("\n\n \
    Opção inválida! \n\
     Digite o movimento (RG, RB, GR, GB, BR, BG): ");
        scanf("%s", op);
    }
    
    return op;
}

int opcaoValida(const char* op){
    size_t tam = strlen(op);

    if(tam != 2){
        return 0;
    }

    if(op[0] == 'R'){
        if(op[1] == 'G' || op[1] == 'B'){
            return 1;
        }
    }

    if(op[0] == 'G'){
        if(op[1] == 'R' || op[1] == 'B'){
            return 1;
        }
    }

    if(op[0] == 'B'){
        if(op[1] == 'R' || op[1] == 'G'){
            return 1;
        }
    }

    return 0;
}

char decifrarNum(int num){
    switch (num){
        case 0: return 'R';
        case 1: return 'G';
        case 2: return 'B';
        default:  return 'N';
    }
}

Stack* criar_R(){
    Stack* R = criar(MAX);
    int max = 2; 
    int min = 0;
    int r = 0, g = 0, b = 0;
  
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) { 
        int value = rand() % (max - min + 1) + min; 
        if(value == 0) r++;
        else if(value == 1) g++;
        else if(value == 2) b++;
        char tipo = decifrarNum(value);
        push(R, tipo); 
    }

    if(contemTodos(r,g,b) == 0){
        R = criar_R();
    } 

    return R;
}

int contemTodos(int r, int g, int b){
    if(r >= 1 && g >= 1 && b >= 1){
        return 1;
    }

    return 0;
}

void atualizarTorres(Stack* r, Stack* g, Stack* b, const char* op, int* movimentos){
    char origem = op[0];
    char destino = op[1];

    if((origem == 'R' && !can_pop(r)) || (origem == 'G' && !can_pop(g)) || (origem == 'B' && !can_pop(b))){
        printf("\n     A Torre %c está vazia!\n", origem);
        return;
    }

    if((destino == 'R' && !can_push(r)) || (destino == 'G' && !can_push(g)) || (destino == 'B' && !can_push(b))){
        printf("\n     A Torre %c está cheia!\n", destino);
        return;
    }

    char valor;
    switch(origem){
        case 'R':
            valor = pop(r);
            break;
        case 'G':
            valor = pop(g);
            break;
        default:
            valor = pop(b);
    }

    switch(destino){
        case 'R':
            push(r, valor);
            break;
        case 'G':
            push(g, valor);
            break;
        default:
            push(b, valor);
    }

    (*movimentos)++;
}

int win_game(Stack* r, Stack* g, Stack* b, int movimentos){
    char valoresR[MAX] = { ' ' }, valoresG[MAX] = { ' ' }, valoresB[MAX] = { ' ' }; 
    Node* no1 = r->top;
    Node* no2 = g->top;
    Node* no3 = b->top;

    //PREENCHENDO
    int i, countR = 0, countG = 0, countB = 0;
    for (i = 0; i < MAX && no1 != NULL; i++) {
        valoresR[i] = no1->value;
        countR++;
        no1 = no1->next;
    }

    for (i = 0; i < MAX && no2 != NULL; i++) {
        valoresG[i] = no2->value;
        countG++;
        no2 = no2->next;
    }

    for (i = 0; i < MAX && no3 != NULL; i++) {
        valoresB[i] = no3->value;
        countB++;
        no3 = no3->next;
    }

    //MOSTRANDO
    for (int i = 0; i < MAX; i++) {
        char valor1 = (i < MAX - countR) ? ' ' : valoresR[i - (MAX - countR)];
        char valor2 = (i < MAX - countG) ? ' ' : valoresG[i - (MAX - countG)];
        char valor3 = (i < MAX - countB) ? ' ' : valoresB[i - (MAX - countB)];

        if (!(valor1 == 'R' || valor1 == ' ') || !(valor2 == 'G' || valor2 == ' ') || !(valor3 == 'B' || valor3 == ' ')) {
            show(r, g, b, movimentos);
            printf("\n\n");
            return 0;
        }
    }

    show(r,g,b, movimentos);
    printf("\n\n      🥇 PARABÉNS! Você venceu efetuando %d movimentos!\n", movimentos); 
    return 1;
}

Stack* copiarTorre(Stack* p){
    Stack* copia = criar(MAX);
    Node* no = p->top;
    while(no != NULL){
        Node* prox = no->next;
        push(copia, no->value);
        no = prox;
    }

    return copia;
}

int opValida(int op, int men){
    if(!isdigit(op)){
        return 0;
    }

    if(men == 1){
        return (op == 1) || (op == 2) || (op == 3) || (op == 0);
    }

    return (op == 1) || (op == 2) || (op == 0);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}