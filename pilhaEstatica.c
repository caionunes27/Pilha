#include <stdio.h>
#include <stdlib.h>

// USANDO VETOR - PILHA ESTÁTICA

#define MAX 10  // Definindo o tamanho máximo da pilha

// Definindo a estrutura da pilha
typedef struct {
    int chave[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha* p) { p->topo = -1; } // A pilha começa vazia

// Função para verificar se a pilha está cheia - BOOL
int pilhaCheia(Pilha* p) { return p->topo == MAX - 1; }

// Função para verificar se a pilha está vazia - BOOL
int pilhaVazia(Pilha* p) { return p->topo == -1; }

// Função para empilhar um valor
void empilhar(Pilha* p, int valor) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia! Não é possível empilhar.\n");
    } else {
        p->chave[++(p->topo)] = valor; //incrementa o topo e depois coloca o valor na posição do vetor5
        printf("Valor %d empilhado.\n", valor);
    }
}

// Função para desempilhar um valor - BOOL
int desempilhar(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia! Não é possível desempilhar.\n");
        return -1; // Retorna um valor negativo para indicar erro
    } else {
        return p->chave[(p->topo)--];
    }
}

// Função para visualizar o topo da pilha - BOOL
int topo(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return p->chave[p->topo];
    }
}

void imprime(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("A pilha está vazia.\n");
        return;
    }

    printf("Elementos da pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->chave[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    Pilha p;
    inicializarPilha(&p);

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    printf("Topo da pilha: %d\n", topo(&p));

    printf("\nPilha:\n");
    imprime(&p);

    printf("\nDesempilhando: %d\n", desempilhar(&p));
    printf("Desempilhando: %d\n", desempilhar(&p));

    printf("Topo da pilha após desempilhar: %d\n", topo(&p));

    return 0;
}