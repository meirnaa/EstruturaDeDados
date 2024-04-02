/*🩷 Questão 🩷
Utilizando Estruturas, Vetores, Alocação Dinâmica e demais recursos de C 

Faças as funcionalidades abaixo.
Inclua as funcionalidades:
1 - Add aluno
2 - Listar alunos
3 - Atualizar Aluno
4 - Remover Aluno
5 - Buscar aluno por matricula
6 - Buscar aluno por parte do nome

0 - Sair */

//🩷 Bibliotecas 🩷
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//🩷 Estruturas 🩷
struct aluno {
    int matricula;
    char nome[120];
    int idade;
    float renda;
};

//🩷 Parâmetros p/ funções 🩷
void pedirDados(struct aluno *novoAluno);
void listarAlunos(struct aluno *alunos, int qtdAlunos);
void enter_to_continue();
void atualizarAluno(struct aluno *alunos, int id_n);
void removerAluno(struct aluno *alunos, int *qtd_alunos, int id_n);
void buscaMatricula(struct aluno *alunos, int qtdAlunos, int elem);
void buscaParteNome(struct aluno *alunos, int qtdAlunos, char parte_nome[120]);

//🩷 Função Principal 🩷
int main() {
    SetConsoleOutputCP(CP_UTF8);

    struct aluno *alunos;
    alunos = (struct aluno *)malloc(10 * sizeof(struct aluno));
    int qtd_alunos = 0;

    char menu[] = "\n----------------- Sistema Alunos ----------------\n\n1 - Add Aluno\n2 - Listar Alunos\n3 - Atualizar Aluno\n4 - Remover Aluno\n5 - Buscar aluno por matricula\n6 - Buscar aluno por parte do nome\n\n0 - Sair\n\n>>> ";
    int opcao;

    printf("%s", menu);
    scanf("%d", &opcao);

    while (opcao != 0) {
        if (opcao == 1) {
            struct aluno novoAluno;
            printf("\n");
            pedirDados(&novoAluno);
            alunos[qtd_alunos] = novoAluno;
            qtd_alunos++;
        } 
        else if (opcao == 2) {
            printf("\n");
            listarAlunos(alunos, qtd_alunos);
        } 
        else if (opcao == 3) {
            printf("\n");
            listarAlunos(alunos, qtd_alunos);
            int id_n;
            printf("\nQual aluno N da lista acima deseja atualizar? ");
            scanf("%d", &id_n);
            enter_to_continue();
            atualizarAluno(alunos, id_n);
        } 
        else if (opcao == 4) {
            enter_to_continue();
            listarAlunos(alunos, qtd_alunos);
            int id_n;
            printf("\nQual aluno N da lista acima deseja remover? ");
            scanf("%d", &id_n);
            removerAluno(alunos, &qtd_alunos, id_n);
        } 
        else if (opcao == 5) {
            int matricula;
            enter_to_continue();
            printf("Digite a matrícula procurada: ");
            scanf("%d", &matricula);
            buscaMatricula(alunos, qtd_alunos, matricula);
            printf("\n\n\n");
        } 
        else if (opcao == 6) {
            char parte_nome[120];
            enter_to_continue();
            printf("Digite a parte do nome procurada: ");
            scanf("%s", parte_nome);
            buscaParteNome(alunos, qtd_alunos, parte_nome);
            printf("\n\n\n");
        }
        
        enter_to_continue();
        printf("%s", menu);
        scanf("%d", &opcao);
    }
    
    free(alunos);
    return 0;
}

//🩷 Outras Funções 🩷
void pedirDados(struct aluno *novoAluno){
    printf("Matrícula: ");
    scanf("%d", &novoAluno->matricula);

    printf("Nome: ");
    scanf(" %120[^\n]", &novoAluno->nome);

    printf("Idade: ");
    scanf("%d", &novoAluno->idade);

    printf("Renda: ");
    scanf("%f", &novoAluno->renda);
}

void listarAlunos(struct aluno *alunos, int qtdAlunos){
    printf("-------------------------------------------------\n");
    printf("Alunos Cadastrados\n");
    printf("\nAluno N - Matrícula, Nome, Idade, Renda\n\n");

    for (int i = 0; i < qtdAlunos; i++) {
        printf("Aluno %d - %d, %s, %d, %.2f\n", i+1, alunos[i].matricula, alunos[i].nome, alunos[i].idade, alunos[i].renda);
    }

}

void enter_to_continue(){
    printf("\n<enter> to continue...");
    getchar(); 
    while (getchar() != '\n'); // Limpa o buffer de entrada
    system("cls");
}

void atualizarAluno(struct aluno *alunos, int id_n){
    printf("-------------------------------------------------\n");
    printf("Aluno Selecionado: \n");
    printf("\nAluno %d - %d, %s, %d, %.2f\n", id_n, alunos[id_n - 1].matricula, alunos[id_n - 1].nome, alunos[id_n - 1].idade, alunos[id_n -1].renda); 
    int opcao;
    printf("\nQual das opções abaixo deseja editar?");
    printf("\n\n1 - Matrícula\n2 - Nome\n3 - Idade\n4 - Renda\n\n>>> ");
    scanf("%d", &opcao);

    if(opcao == 1){
        printf("\nNova matrícula: ");
        scanf("%d", &alunos[id_n - 1].matricula); 
        printf("\nMatrícula atualizada com sucesso!\n");
    }
    else if(opcao == 2){
        printf("\nNovo nome: ");
        scanf(" %120[^\n]", &alunos[id_n - 1].nome); 
        printf("\nNome atualizado com sucesso!\n");
    }
    else if(opcao == 3){
        printf("\nNova idade: ");
        scanf("%d", &alunos[id_n - 1].idade); 
        printf("\nIdade atualizada com sucesso!\n");
    }
    else if(opcao == 4){
        printf("\nNova renda: ");
        scanf("%f", &alunos[id_n - 1].renda); 
        printf("\nRenda atualizada com sucesso!\n");
    }
}

void removerAluno(struct aluno *alunos, int *qtd_alunos, int id_n) {
    if (id_n < 1 || id_n > *qtd_alunos) {
        printf("ID inválido.\n");
        return;
    }

    for (int i = id_n - 1; i < *qtd_alunos - 1; i++) {
        alunos[i] = alunos[i + 1];
    }

    (*qtd_alunos)--;

    printf("\nAluno removido com sucesso!\n");
}

void buscaMatricula(struct aluno *alunos, int qtdAlunos, int elem){
    int encontrados = 0;
    
    printf("\n\n-------------------------------------------------\n");
    printf("Aluno(s) com a matrícula %d encontrado(s): \n\n", elem);
    
    for(int i = 0; i < qtdAlunos; i++){
    if (elem == alunos[i].matricula){
        printf("\nAluno %d - %d, %s, %d, %.2f", i + 1, alunos[i].matricula, alunos[i].nome, alunos[i].idade, alunos[i].renda); 
        encontrados++;
    }
    }

    if(encontrados == 0){
        printf("Nenhum aluno(s) com a matrícula %d foi encontrado!", elem);
    }
}

void buscaParteNome(struct aluno *alunos, int qtdAlunos, char parte_nome[120]){
    int encontrados = 0;
    
    printf("\n\n-------------------------------------------------\n");
    printf("Aluno(s) com a '%s' encontrado(s): \n\n", parte_nome);
    
    for(int i = 0; i < qtdAlunos; i++){
    if (strstr(alunos[i].nome, parte_nome) != NULL){
        printf("\nAluno %d - %d, %s, %d, %.2f", i + 1, alunos[i].matricula, alunos[i].nome, alunos[i].idade, alunos[i].renda); 
        encontrados++;
    }
    }

    if(encontrados == 0){
        printf("Nenhum aluno(s) com '%s' foi encontrado!", parte_nome);
    }
}
