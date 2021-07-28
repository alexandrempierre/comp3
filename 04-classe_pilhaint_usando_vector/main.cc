#include "pilhaint.h"

using namespace std;

PilhaInt embaralha( PilhaInt q ) {
    int aux = q.desempilha();
    q << 32 << 9 << aux;
    
    return q;
}

int main(int argc, char const *argv[]) {
    PilhaInt a{81};
    a << 5 << 6 << 3 << 2 << 9 << 13;
    a.redimensiona( 81 ); cout << a.capacidade() << endl;
    a.redimensiona( 11 ); cout << a.capacidade() << endl;
    a.redimensiona( 6 ); cout << a.capacidade() << endl;
    a.print( cout ); cout << endl;
    a.redimensiona( 3 ); cout << a.capacidade() << endl;
    a.print( cout ); cout << endl;

    return 0;
}
