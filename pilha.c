
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


Pessoa ler_pessoa() {
    Pessoa p;

    printf("\n Digite o nome, data de nascimento dd mm aaaa: \n");
    scanf("%49[^\n] %d %d %d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
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


int main() {
    setlocale(LC_ALL,"Portuguese");
    No *topo = NULL;
    int opcao;

    do {
        printf("\n0 - sair \n1 - empilhar\n2 - desempilhar \n3 - imprimir\n");
        scanf("%d", &opcao);
        getchar();
        printf("\n opcao = %d", opcao);

        switch (opcao)
        {
        case 0:
            printf("\nObrigado por utilizar nosso Sistema, At� logo.\n");
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
