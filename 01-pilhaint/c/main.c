#include "pilhaint.h"

int main(int argc, char const *argv[])
{
    PilhaInt_t p;
    int x;

    inicializa_pilha(&p);
    print(&p);

    empilha(&p, 3);
    print(&p);
    // empilha(&p, 2);
    // print(&p);
    // empilha(&p, 1);
    // print(&p);

    x = desempilha(&p);
    printf("Valor desempilhado: %d\n", x);
    print(&p);

    x = desempilha(&p);
    printf("Valor desempilhado: %d\n", x);
    print(&p);

    return 0;
}
