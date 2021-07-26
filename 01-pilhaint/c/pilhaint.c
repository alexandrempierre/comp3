#include "pilhaint.h"

void erro(char* msg) {
    puts(msg);
    exit(-1);
}

void inicializa_pilha(PilhaInt_t *pilha) {
    for (int i = 0; i < MAX_PILHA; i++) {
        pilha->tab[i] = 0;
    }
    pilha->atual = 0;    
}

void empilha (PilhaInt_t* pilha, int valor) {
    if (pilha->atual < MAX_PILHA) {
        pilha->tab[pilha->atual++] = valor;
    } else {
        erro("Estouro de pilha! Impossível empilhar!");
    }
}

int desempilha (PilhaInt_t* pilha) {
    if (pilha->atual > 0) {
        return pilha->tab[--pilha->atual];
    } else {
        erro("Pilha vazia! Impossível desempilhar!");
    }
}

void print(PilhaInt_t* pilha) {
    if (pilha->atual) {
        for (int i = 0; i < pilha->atual; i++) {
            printf("%d ", pilha->tab[i]);
        }
        puts("");
    } else {
        puts("Pilha vazia!");
    }
}