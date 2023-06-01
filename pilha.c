#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int dia, mes,ano;
}Data;

typedef struct
{
    char nome[50];
    Data data;
}Pessoa;

typedef struct no
{
    Pessoa p;
    struct no *proximo;

}No;


void menu(){
	setlocale(LC_ALL,"Portuguese");
    printf("==================== MENU ====================\n");
    printf("\n");
    printf("  0 - SAIR\n");
    printf("  1 - EMPILHAR\n");
    printf("  2 - DESEMPILHAR\n");
    printf("  3 - IMPRIMIR\n");
    printf("\n");
    printf("==============================================\n");
}

Pessoa ler_pessoa() {
    Pessoa p;
    printf("\n Digite o nome, data de nascimento dia, mês, ano: \n\n");
    scanf("%49[^\n]%d%d%d" , p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    printf("\n");
    return p;
}

void imprimir_pessoa(Pessoa p) {
    printf("\n Nome : %s\n Data: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);

}

// Operação push = empilhar
No* empilhar(No *topo) {
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    }
    else {
        printf("\n Erro na alocação \n");
    }
    return NULL;
}

//Operação desempilhar
No* desempilhar(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }else
    printf("\nPilha vazia.\n");
    return NULL;
}


//Operação imprimir
void imprimir_pilha(No *topo){
    printf("\n---------- PILHA ----------\n");
    while(topo){
        imprimir_pessoa(topo->p);
        topo = topo->proximo;
    }

    printf("\n-------- FIM PILHA --------\n");

}

int main() {
    setlocale(LC_ALL,"Portuguese");
    No *remover, *topo = NULL;
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 0:
            printf("\n Obrigado por utilizar nosso Sistema, Até logo.\n");
            break;
        case 1:
            topo = empilhar(topo);
            break;
        case 2:
            remover = desempilhar(&topo);
            if(remover!= NULL){
                    printf("\nNome Removido com Sucesso!\n");
                imprimir_pessoa(remover->p);
            }else
                printf("\nSem nó a remover\n");
            break;
        case 3:
                imprimir_pilha(topo);
            break;
        default:
            if(opcao != 0){
                printf("\n opção inválida\n");
            }

        }
    } while (opcao != 0);

    return 0;

}
