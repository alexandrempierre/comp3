#include "pilhaint.h"

#define MAX_PILHA   10

using namespace std;

class PilhaInt {
    public:
        PilhaInt();

        const PilhaInt& operator =(const PilhaInt& p) {
            atual = p.atual;

            for (int i = 0; i < MAX_PILHA; i++) {
                tab[i] = p.tab[i];
            }

            return *this;
        }

        PilhaInt& operator <<(int valor) {
            empilha(valor);

            return *this;
        }

        void empilha(int valor);
        int desempilha();
        void print(ostream& o);
    private:
        int tab[MAX_PILHA];
        int atual;
};

PilhaInt::PilhaInt() {
    for (int i = 0; i < MAX_PILHA; i++) {
        tab[i] = 0;
    }
    atual = 0;
}

void PilhaInt::empilha(int valor) {
    tab[atual++] = valor;
}

int PilhaInt::desempilha() {
    return tab[--atual];
}

void PilhaInt::print(ostream& o) {
    o << "[ ";
    for (int i = 0; i < atual; i++) {
        o << tab[i];
        if (i < atual-1) {
            o << ",";
        }
        o << " ";
    }
    o << "]";
}