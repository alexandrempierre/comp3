#include "pilhaint.cc"

using namespace std;

PilhaInt embaralha( PilhaInt q ) {
    int aux = q.desempilha();
    q << 32 << 9 << aux;
    
    return q;
}

int main(int argc, char const *argv[]) {
    PilhaInt a{3};
    for( int i = 0; i < 20; i++ ) {
        a << i;
        cout << a.capacidade() << " ";
    }
    cout << endl;
    a.print( cout ); cout << endl;

    return 0;
}
