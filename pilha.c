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

    printf("\n Digite o nome, data de nascimento dia, m�s, ano: \n\n");
    scanf("%49[^\n]%d%d%d" , p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    printf("\n");
    return p;
}

void imprimir_pessoa(Pessoa p) {
    printf("\n Nome : %s\n Data: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);

}

// Opera��o push = empilhar
No* empilhar(No *topo) {
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    }
    else {
        printf("\n Erro na aloca��o \n");
    }
    return NULL;
}
//Opera��o desempilhar




//Opera��o imprimir




int main() {
    setlocale(LC_ALL,"Portuguese");
    No *topo = NULL;
    int opcao;

    do {
        //printf("\n0 - SAIR \n1 - EMPILHAR\n2 - DESEMPILHAR \n3 - IMPRIMIR\n");
        menu();
        scanf("%d", &opcao);
        getchar();
        printf("\n opcao = %d", opcao);

        switch (opcao)
        {
        case 0:
            printf("\n Obrigado por utilizar nosso Sistema, At� logo.\n");
            break;
        case 1:
            topo = empilhar(topo);
            break;
        case 2:

            break;
        case 3:

            break;
        default:
            if(opcao != 0){
                printf("\n op��o inv�lida\n");
            }

        }
    } while (opcao != 0);

    return 0;

}
