#ifndef PILHAINT_H

#define MAX_PILHA    3
#define PILHAINT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tab[MAX_PILHA];
    int atual;
} PilhaInt_t;

void inicializa_pilha(PilhaInt_t*);

void empilha(PilhaInt_t*, int);

int desempilha(PilhaInt_t*);

void print(PilhaInt_t*);

#endif