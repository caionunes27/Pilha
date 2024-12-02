#include <stdio.h>
#include <stdlib.h>

//USANDO LISTA ENCADEADA - PILHA DINAMICA

// Definindo a estrutura do nó da lista encadeada
typedef struct No {
    int chave;
    struct No* prox;
} No;

// Definindo a estrutura da pilha
typedef struct {
    No* topo;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha* p) {
    p->topo = NULL;  // A pilha começa vazia
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha* p) {
    return p->topo == NULL;
}

// Função para empilhar um valor
void empilhar(Pilha* p, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    novoNo->chave = valor;
    novoNo->prox = p->topo;
    p->topo = novoNo;
    printf("Valor %d empilhado.\n", valor);
}

// Função para desempilhar um valor
int desempilhar(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia! Não é possível desempilhar.\n");
        return -1; // Retorna um valor negativo para indicar erro
    }
    No* temp = p->topo;
    int valor = temp->chave;
    p->topo = temp->prox;
    free(temp); // Libera a memória do nó desempilhado
    return valor;
}

// Função para visualizar o topo da pilha
int topo(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return p->topo->chave;
    }
}

void imprime(Pilha* p) {
    No* temp = p->topo;  // Ponteiro auxiliar para percorrer a pilha

    while (temp != NULL) {  // Enquanto houver elementos na pilha
        printf("%d ", temp->chave);  // Imprime a chave do nó
        temp = temp->prox;  // Avança para o próximo nó
    }

    printf("\n");  // Adiciona uma nova linha após a impressão
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

