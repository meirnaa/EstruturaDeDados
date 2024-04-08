//🩷 Bibliotecas 🩷
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include "banco.h"

int main(){
SetConsoleOutputCP(CP_UTF8);
    Banco *novoBanco;
    novoBanco = (Banco *)malloc(sizeof(Banco));
    int qt_contas = 0;

    Conta *contas;
    contas = (Conta *)malloc(50 * sizeof(Conta));
    novoBanco->contas = contas;

    int linhas = 50; //extrato da conta n
    int colunas = 40; //operacoes por extrato

    Transacao **extratos = (Transacao **)malloc(linhas * sizeof(Transacao *));

    // Alocação de memória para cada linha da matriz
    for (int i = 0; i < linhas; i++) {
        extratos[i] = (Transacao *)malloc(colunas * sizeof(Transacao));
    }
    contas->extratos = extratos;

    abrirBanco(novoBanco);
    enter_to_continue();
    
    int opcao;
    menu(novoBanco);
    scanf("%d", &opcao);
        
        while(opcao != 0){
            if(opcao == 1){ //ABRIR CONTA
                enter_to_continue();
                abrirConta(contas, &qt_contas, extratos);
            }
            else if(opcao == 2){ //LISTAR
                enter_to_continue();
                listarContas(contas, &qt_contas);
                printf("\n");
            }
            else if(opcao == 3){ //SACAR
                //CPF
                char cpf[12];
                printf("\nCPF da conta: ");
                scanf(" %12[^\n]", cpf);
                bool cpfValido = validarCPF(cpf);
                
                while(!cpfValido){
                    printf("\nCPF inválido, digite novamente: ");
                    scanf(" %12[^\n]", cpf);
                    cpfValido = validarCPF(cpf);
                    while (getchar() != '\n'); // Limpa o buffer de entrada
                }

                float valor;
                printf("Valor (R$) que deseja sacar: ");
                scanf("%f", &valor);
                sacar(contas, valor, cpf, &qt_contas, extratos);
                printf("\n");
            }
            else if(opcao == 4){ //DEPOSITAR
                //CPF
                char cpf[12];
                printf("\nCPF da conta: ");
                scanf(" %12[^\n]", cpf);
                bool cpfValido = validarCPF(cpf);

                while(!cpfValido){
                    printf("\nCPF inválido, digite novamente: ");
                    scanf(" %12[^\n]", cpf);
                    cpfValido = validarCPF(cpf);
                    while (getchar() != '\n'); // Limpa o buffer de entrada
                }

                float valor;
                printf("Valor (R$) que deseja depositar: ");
                scanf("%f", &valor);
                depositar(contas, valor, cpf, &qt_contas, extratos);
                printf("\n");
            }
            else if(opcao == 5){
                enter_to_continue();
                //cpf conta origem
                char cpf_origem[12];
                printf("CPF da conta origem: ");
                scanf(" %12[^\n]", cpf_origem);
                bool cpf_origemValido = validarCPF(cpf_origem);

                while(!cpf_origemValido){
                    printf("\nCPF inválido, digite novamente: ");
                    scanf(" %12[^\n]", cpf_origem);
                    cpf_origemValido = validarCPF(cpf_origem);
                    while (getchar() != '\n'); // Limpa o buffer de entrada
                }

                //cpf conta destino
                char cpf_destino[12];
                printf("CPF da conta destino: ");
                scanf(" %12[^\n]", cpf_destino);
                bool cpf_destinoValido = validarCPF(cpf_destino);

                while(!cpf_destinoValido){
                    printf("\nCPF inválido, digite novamente: ");
                    scanf(" %12[^\n]", cpf_destino);
                    cpf_destinoValido = validarCPF(cpf_destino);
                    while (getchar() != '\n'); // Limpa o buffer de entrada
                }

                transferirPIX(contas, cpf_origem, cpf_destino, &qt_contas, extratos);
                printf("\n");
            }
            else if(opcao == 6){ //VER EXTRATO
                //cpf
                char cpf[12];
                printf("\nCPF da conta: ");
                scanf(" %12[^\n]", cpf);
                bool cpfValido = validarCPF(cpf);

                while(!cpfValido){
                    printf("\nCPF inválido, digite novamente: ");
                    scanf(" %12[^\n]", cpf);
                    cpfValido = validarCPF(cpf);
                    while (getchar() != '\n'); // Limpa o buffer de entrada
                }

                mostrarExtrato(cpf, contas, &qt_contas, extratos);
            }
            else if(opcao == 7){ 
                char cpf[12];
                printf("\nCPF da conta: ");
                scanf(" %12[^\n]", cpf);
                bool cpfValido = validarCPF(cpf);

                while(!cpfValido){
                    printf("\nCPF inválido, digite novamente: ");
                    scanf(" %12[^\n]", cpf);
                    cpfValido = validarCPF(cpf);
                    while (getchar() != '\n'); // Limpa o buffer de entrada
                }
                consultarSaldo(contas, cpf, &qt_contas);
            }

            enter_to_continue();
            menu(novoBanco);
            scanf("%d", &opcao);
        }

    for (int i = 0; i < linhas; i++) {
        free(extratos[i]);
    }
    free(extratos);
    free(contas);
    free(novoBanco);

    return 0;
}

//🩷 Outras Funções 🩷
void abrirBanco(Banco *novoBanco){
    char nome[120];
    char logradouro[250];
    char bairro[120];
    char cidade[120];
    char uf[3];
    char cep[11];

    //Nome
    printf("\nNome do Banco: ");
    scanf(" %120[^\n]", nome);

    //Endereço
    printf("\n- - - - - - - - - Endereço do Banco - - - - - - - - - -");
    printf("\n\nLogradouro: ");
    scanf(" %250[^\n]", logradouro);
    printf("Bairro: ");
    scanf(" %120[^\n]", bairro);
    printf("Cidade: ");
    scanf(" %120[^\n]", cidade);

    //UF
    printf("UF: ");
    scanf(" %3[^\n]", uf);
    bool ufValida = false;

    while(!ufValida){
        if(!validarUF(uf)){
        printf("\nUF inválida, digite novamente: ");
        scanf(" %3[^\n]", &uf);
        while (getchar() != '\n'); // Limpa o buffer de entrada
        }else{
            ufValida = true;
        }
    }

    //CEP
    printf("CEP: ");
    scanf(" %9[^\n]", cep);
    bool cepValido = validarCEP(cep);
    
    while(!cepValido){
        printf("\nCEP inválido, digite novamente: ");
        scanf(" %9[^\n]", &cep);
        cepValido = validarCEP(cep);
        while (getchar() != '\n'); // Limpa o buffer de entrada
    }

    strcpy(novoBanco->nome, nome);
    strcpy(novoBanco->endereco.logradouro, logradouro);
    strcpy(novoBanco->endereco.bairro, bairro);
    strcpy(novoBanco->endereco.cidade, cidade);
    strcpy(novoBanco->endereco.uf, uf);
    strcpy(novoBanco->endereco.cep, cep);
    
    printf("\nBanco criado!\n");
}

void menu(Banco *novoBanco){
    printf("\n- - - - - - - - - - - - Banco %s - - - - - - - - - - - -", novoBanco->nome);
    printf("\n\n1 - Abrir Conta");
    printf("\n2 - Listar Contas");
    printf("\n3 - Sacar");
    printf("\n4 - Depositar");
    printf("\n5 - Realizar PIX");
    printf("\n6 - Mostrar extrato");
    printf("\n7 - Consultar saldo");
    printf("\n");
    printf("\n0 - Sair");
    printf("\n\n>>> ");
}

void enter_to_continue(){
    printf("\n<enter> to continue...");
    getchar(); 
    while (getchar() != '\n'); // Limpa o buffer de entrada
    system("cls");
}

int gerarNumeroConta(){
    // Define a semente com base no tempo atual
    srand(time(NULL));

    // Gera um número randomico de 8 dígitos
    int numero = rand() % 100000000 + 10000000;
    return numero;
}

bool validarCPF(char *cpf){
    if (strlen(cpf) != 11) {
        return false;
    }

    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return false;
        }
    }

    return true;
}

bool validarUF(char *uf) {
    if (strlen(uf) != 2) {
        return false;
    }

    for (int i = 0; i < 2; i++) {
        if (!isalpha(uf[i])) { 
            return false;
        }
    }

    return true;
}

bool validarValor(float valor) {
    if (isnan(valor)) {
        return false; 
    }

    if (valor == 0.0 || valor < 0) {
        return false; 
    }

    return true; 
}

bool validarCEP(char *cep){
    if (strlen(cep) != 8) {
        return false;
    }

    for (int i = 0; i < 8; i++) {
        if (!isdigit(cep[i])) {
            return false;
        }
    }

    return true;
}

bool ehAnoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool validarData(int dia, int mes, int ano, char *dataValida) {
    if (ano < 1 || ano > 2024) {
        return false; // Ano deve estar entre 1 e 2024
    }

    if (mes < 1 || mes > 12) {
        return false; // Mês deve estar entre 1 e 12
    }

    int diasNoMes;

    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diasNoMes = 31;
            break;
        case 4: case 6: case 9: case 11:
            diasNoMes = 30;
            break;
        case 2:
            diasNoMes = ehAnoBissexto(ano) ? 29 : 28;
            break;
        default:
            return false;
    }

    if (dia < 1 || dia > diasNoMes) {
        return false; // Dia deve estar dentro do intervalo correto para o mês
    }

    // Se chegou aqui, a data é válida
    sprintf(dataValida, "%02d/%02d/%04d", dia, mes, ano); // Formata a data como string
    return true; // Data válida
}

void abrirConta(Conta *contas, int *qt_contas, Transacao **extratos){
    int numero = gerarNumeroConta();
    float saldo = 0.0;
    int qt_operacoes = 0;
    char nome[120];
    int idade;
    float renda;
    char cpf[12];
    char logradouro[250];
    char bairro[120];
    char cidade[120];
    char uf[3];
    char cep[11];

    //Nome
    printf("\nNome do titular: ");
    scanf(" %120[^\n]", nome);

    //Idade
    bool entradaValida = false; // Inicialmente definido como falso

    while (!entradaValida) {
        printf("Idade do titular: ");
        if(scanf("%d", &idade) == 1) {
            entradaValida = true;
        }else{
            printf("\nIdade inválida, digite novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        }
    }


    if(idade < 18){
        printf("\nNão é possível abrir a conta pois o titular é menor de idade!\n"); //Validando idade
    }
    else{
        //Renda
        printf("Renda do titular: ");
        scanf("%f", &renda);

        //CPF
        printf("CPF do titular: ");
        scanf(" %12[^\n]", cpf);
        bool cpfValido = validarCPF(cpf);

        while(!cpfValido){
            printf("\nCPF inválido, digite novamente: ");
            scanf(" %12[^\n]", cpf);
            cpfValido = validarCPF(cpf);
            while (getchar() != '\n'); // Limpa o buffer de entrada
        }

        //Endereço
        printf("\n\n- - - - - - - - - - - - Endereço - - - - - - - - - - - -");
        printf("\n\nLogradouro: ");
        scanf(" %250[^\n]", logradouro);
        printf("Bairro: ");
        scanf(" %120[^\n]", bairro);
        printf("Cidade: ");
        scanf(" %120[^\n]", cidade);

        //UF
        printf("UF: ");
        scanf(" %3[^\n]", uf);
        bool ufValida = false;

        while(!ufValida){
            if(!validarUF(uf)){
            printf("\nUF inválida, digite novamente: ");
            scanf(" %3[^\n]", &uf);
            while (getchar() != '\n'); // Limpa o buffer de entrada
            }else{
                ufValida = true;
            }
        }

        //CEP
        printf("CEP: ");
        scanf(" %9[^\n]", cep);
        bool cepValido = validarCEP(cep);
        
        while(!cepValido){
            printf("\nCEP inválido, digite novamente: ");
            scanf(" %9[^\n]", &cep);
            cepValido = validarCEP(cep);
            while (getchar() != '\n'); // Limpa o buffer de entrada
        }

        Conta novaConta;

        novaConta.numero = numero;
        novaConta.titular.renda = renda;
        novaConta.operacoes_realizadas = qt_operacoes;
        strncpy(novaConta.titular.nome, nome, sizeof(novaConta.titular.nome));
        novaConta.saldo = saldo;
        novaConta.titular.idade = idade;
        strncpy(novaConta.titular.cpf, cpf, sizeof(novaConta.titular.cpf));
        strncpy(novaConta.titular.endereco.logradouro, logradouro, sizeof(novaConta.titular.endereco.logradouro));
        strncpy(novaConta.titular.endereco.bairro, bairro, sizeof(novaConta.titular.endereco.bairro));
        strncpy(novaConta.titular.endereco.cidade, cidade, sizeof(novaConta.titular.endereco.cidade));
        strncpy(novaConta.titular.endereco.uf, uf, sizeof(novaConta.titular.endereco.uf));
        strncpy(novaConta.titular.endereco.cep, cep, sizeof(novaConta.titular.endereco.cep));
        
        contas[*qt_contas] = novaConta;

        Transacao novoExtrato;
        extratos[*qt_contas][*qt_contas] = novoExtrato;
        printf("\nSua conta foi criada.\n");
        (*qt_contas)++;
    }
}

void listarContas(Conta *contas, int *qt_contas){
    printf("- - - - - - - - - - - - Contas Cadastradas - - - - - - - - - - - -\n");
    printf("\nID Conta - Número da conta, Nome, Idade e CPF do titular\n");

    for(int i = 0; i < (*qt_contas); i++){
        printf("Conta %d - %d, %s, %d, %s\n",
               i+1, 
               contas[i].numero,
               contas[i].titular.nome, 
               contas[i].titular.idade, 
               contas[i].titular.cpf);
    }
}

void sacar(Conta *contas, float valor, char *cpf, int *qt_contas, Transacao **extratos){ 
    bool cpfEncontrado = false;
    for(int i = 0; i < (*qt_contas); i++){
        if (strcmp(contas[i].titular.cpf, cpf) == 0){
            cpfEncontrado = true;
            if(!validarValor(valor)){
                printf("\nValor inválido.");
                break;
            }else{
                if(contas[i].saldo < valor){
                    printf("\nSaldo insuficiente. Não foi possível realizar o saque.");
                    return;
                }else{
                char operacao[9] = "Saque";
    
                int dia, mes, ano;
                char data[11];
                
                printf("Data (DD/MM/AAAA): ");
                scanf("%d/%d/%d", &dia, &mes, &ano);

                bool dataValida = validarData(dia, mes, ano, data);
                
                while(!dataValida){
                    printf("Data inválida!\n");
                    printf("Data (DD/MM/AAAA): ");
                    scanf("%d/%d/%d", &dia, &mes, &ano);
                    dataValida = validarData(dia, mes, ano, data);
                    while (getchar() != '\n'); // Limpa o buffer de entrada
                }

                char descricao[250] = "Transação em: ";
                strcat(descricao, data);
                contas[i].saldo -= valor; 

                printf("\nSaque realizado com sucesso!");

                int counter = contas[i].operacoes_realizadas;

                Transacao novaOperacao;
                strncpy(novaOperacao.operacao, operacao, sizeof(novaOperacao.operacao)); 
                strncpy(novaOperacao.descricao, descricao, sizeof(novaOperacao.descricao));
                novaOperacao.valor = valor; 

                extratos[i][counter] = novaOperacao;
                (contas[i].operacoes_realizadas)++;
                return;
                }
            }
        }
    }
    
    if(!cpfEncontrado){
            printf("\nCPF não encontrado.");
    }
}

void depositar(Conta *contas, float valor, char *cpf, int *qt_contas, Transacao **extratos){ 
    bool cpfEncontrado = false;
    for(int i = 0; i < (*qt_contas); i++){
        if (strcmp(contas[i].titular.cpf, cpf) == 0){
            cpfEncontrado = true;
            if(!validarValor(valor)){
                printf("\nValor inválido.");
                return;
            }else{
                char operacao[9] = "Depósito";
    
                int dia, mes, ano;
                char data[11];
                
                printf("Data (DD/MM/AAAA): ");
                scanf("%d/%d/%d", &dia, &mes, &ano);

                bool dataValida = validarData(dia, mes, ano, data);
                
                while(!dataValida){
                    printf("Data inválida!\n");
                    printf("Data (DD/MM/AAAA): ");
                    scanf("%d/%d/%d", &dia, &mes, &ano);
                    dataValida = validarData(dia, mes, ano, data);
                    while (getchar() != '\n'); // Limpa o buffer de entrada
                }

                    char str1[] = "Transação em: ";
                    char str_concatenada[50]; 

                    strcpy(str_concatenada, str1);
                    strcat(str_concatenada, data);

                //REALIZANDO DEPÓSITO
                contas[i].saldo += valor; 
                printf("\nDepósito realizado com sucesso!");

                int counter = contas[i].operacoes_realizadas;

                Transacao novaOperacao;
                strncpy(novaOperacao.operacao, operacao, sizeof(novaOperacao.operacao)); 
                strncpy(novaOperacao.descricao, str_concatenada, sizeof(novaOperacao.descricao));
                novaOperacao.valor = valor; 

                extratos[i][counter] = novaOperacao;
                (contas[i].operacoes_realizadas)++;
                return;
            }
        }
    }

    if (!cpfEncontrado) {
        printf("\nCPF não encontrado.");
    }
}

void consultarSaldo(Conta *contas, char *cpf, int *qt_contas){
    int cpfEncontrado = 0; 
    for(int i = 0; i < (*qt_contas); i++){
        if (strcmp(contas[i].titular.cpf, cpf) == 0){
            printf("\nSaldo atual: R$ %.2f\n", contas[i].saldo);
            cpfEncontrado = 1; 
        }
    }
    if (!cpfEncontrado) { 
        printf("\nCPF não encontrado.\n");
    }
}

void transferirPIX(Conta *contas, char *cpf_origem, char *cpf_destino, int *qt_contas, Transacao **extratos){
    int id_conta_origem;
    int id_conta_destino;
    int nao_encontrados_o = 0;
    int nao_encontrados_d = 0;

    for(int i = 0; i < (*qt_contas); i++){
        if (strcmp(contas[i].titular.cpf, cpf_origem) != 0){
           nao_encontrados_o++;
        }else{
            id_conta_origem = i;
        }
    } 

    for(int i = 0; i < (*qt_contas); i++){
        if (strcmp(contas[i].titular.cpf, cpf_destino) != 0){
            nao_encontrados_d++;
        }else{
            id_conta_destino = i;
        }
    }
    
    for(int i = 0; i < (*qt_contas); i++){
        if(nao_encontrados_o != (*qt_contas) && nao_encontrados_d != (*qt_contas)){
                float valor;
                printf("\nValor (R$) que deseja transferir via PIX: ");
                scanf("%f", &valor);
                if(!validarValor(valor)){
                    printf("\nValor inválido.");
                    break;
                }else{
                    if(contas[id_conta_origem].saldo < valor){
                    printf("\nSaldo insuficiente.");
                    break;
                    }else{
                        char operacao[9] = "PIX";
                        char origem[120];
                        char destino[120];

                        strcpy(origem, contas[id_conta_origem].titular.nome);
                        strcpy(destino, contas[id_conta_destino].titular.nome);
    
                        int dia, mes, ano;
                        char data[11];
                        
                        printf("Data (DD/MM/AAAA): ");
                        scanf("%d/%d/%d", &dia, &mes, &ano);

                        bool dataValida = validarData(dia, mes, ano, data);
                        
                        while(!dataValida){
                            printf("Data inválida!\n");
                            printf("Data (DD/MM/AAAA): ");
                            scanf("%d/%d/%d", &dia, &mes, &ano);
                            dataValida = validarData(dia, mes, ano, data);
                            while (getchar() != '\n'); // Limpa o buffer de entrada
                        }

                        char descricao[250] = "Transação em: ";
                        strcat(descricao, data);
                        strcat(descricao, "\nDe: ");
                        strcat(descricao, origem);
                        strcat(descricao, "\nPara: ");
                        strcat(descricao, destino);    

                        char descricao_origem[250] = "Transação em: ";
                        strcat(descricao_origem, data);
                        strcat(descricao_origem, "\nDe: ");
                        strcat(descricao_origem, origem);
                        strcat(descricao_origem, "\nPara: ");
                        strcat(descricao_origem, destino);                        

                        //REALIZANDO PIX
                        contas[id_conta_origem].saldo -= valor; 
                        contas[id_conta_destino].saldo += valor; 
                        printf("\nTransferência PIX realizada com sucesso!");

                        int counter_destino = contas[id_conta_destino].operacoes_realizadas;
                        int counter_origem = contas[id_conta_origem].operacoes_realizadas;

                        Transacao novaOperacao_destino;
                        Transacao novaOperacao_origem;

                        strncpy(novaOperacao_destino.operacao, operacao, sizeof(novaOperacao_destino.operacao)); 
                        strncpy(novaOperacao_destino.descricao, descricao, sizeof(novaOperacao_destino.descricao));
                        novaOperacao_destino.valor = valor; 

                        strncpy(novaOperacao_origem.operacao, operacao, sizeof(novaOperacao_origem.operacao)); 
                        strncpy(novaOperacao_origem.descricao, descricao_origem, sizeof(novaOperacao_origem.descricao));
                        novaOperacao_origem.valor = valor; 

                        extratos[id_conta_destino][counter_destino] = novaOperacao_destino;
                        extratos[id_conta_origem][counter_origem] = novaOperacao_origem;
                        (contas[id_conta_destino].operacoes_realizadas)++;
                        (contas[id_conta_origem].operacoes_realizadas)++;

                        break;
                    }
                }
        }else if((nao_encontrados_o == (*qt_contas) && nao_encontrados_d == (*qt_contas))){
            printf("\nCPF de origem e CPF de destino não foram encontrados.\n");
            break;
        }
        else if(nao_encontrados_o == (*qt_contas) && nao_encontrados_d != (*qt_contas)){
            printf("\nCPF de origem não encontrado.");
            break;
        }
        else if(nao_encontrados_o != (*qt_contas) && nao_encontrados_d == (*qt_contas)){
            printf("\nCPF de destino não encontrado.");
            break;
        }
    }
}

void mostrarExtrato(char *cpf, Conta *contas, int *qt_contas, Transacao **extratos){
    int cpfEncontrado = 0; 
    for(int i = 0; i < (*qt_contas); i++){
        if (strcmp(contas[i].titular.cpf, cpf) == 0){
            enter_to_continue();
            printf("- - - - - - - - - - - - Extrato da Conta - - - - - - - - - - - - -");
            printf("\n\nSaldo atual: R$ %.2f\n\n", contas[i].saldo);
            printf("- - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - -\n");
            for(int j = (contas[i].operacoes_realizadas - 1); j >= 0; j--){
                printf("\nTipo de operação: %s", extratos[i][j].operacao);
                printf("\n%s", extratos[i][j].descricao);
                printf("\nValor: R$%.2f", extratos[i][j].valor);
            printf("\n\n- - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - -\n");
            }
            cpfEncontrado = 1;
        }
    }
    if (!cpfEncontrado) { 
        printf("\nCPF não encontrado.\n");
    }
    
}
