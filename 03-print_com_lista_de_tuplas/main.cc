#include "pair.h"

using namespace std;

int main(int argc, char const *argv[]) {
    cout << "Teste 1" << endl;
    print( cout, { { "jan", 1 }, { string( "pi" ), 3.14 } } );

    cout << endl << "Teste 2" << endl;
    print( cout, { { "jan", 1 }, { 2, "fev" }, { string( "pi" ), 3.14 } } );

    cout << endl << "Teste 3" << endl;
    print( cout, { { "jan", 1 }, { 2, "fev" }, { "lista", vector<int>{ 1, 2, 3 } }, { 1, 2 }, { 1.1, 2.2} } );

    cout << endl << "Teste 4" << endl;
    Pair p{ "1", "2" };
    print( cout, { { "jan", 1 }, { string( "pi" ), 3.14 }, p } );

    cout << endl << "Teste 5" << endl;
    stringstream buf;
    print( buf, { { "jan", 1 }, { 2, "fev" }, { "lista", vector<int>{ 1, 2, 3 } }, { 1, 2 }, { 1.1, 2.2} } );
    cout << "Inicio\n" << buf.str() << "Fim" << endl;

    return 0;
}
