#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <sstream>
#include "pair.cc"
#include "leak.cc"

using namespace std;

/* Já definido no Moodle */
ostream& operator <<(ostream& out, const Leak& l) {
    l.print(out);

    return out;
}

ostream& operator <<(ostream& out, const Pair& p) {
    return p.imprime(out);
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[ ";
    for (auto x : v) {
        out << x << " ";
    }
    out << "]";

    return out;
}

int main(int argc, char const *argv[]) {
    /* cout << "Teste 0" << endl;
    ImplPair<int, string>p_test_0{-1, string("-1")};
    p_test_0.imprime(cout);

    cout << endl << "Teste 1" << endl;
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
    cout << "Inicio\n" << buf.str() << "Fim" << endl; */

    /* ===================== Teste dos destrutores ===================== */
    
    {
    cout << "Teste 0" << endl;
    print(cout, { {"jan", Leak()} });
    }

    {
        cout << endl << "Teste 1" << endl;
        print( cout, { { "jan", Leak() }, { string( "pi" ), Leak() } } );
    }

    {
        cout << endl << "Teste 2" << endl;
        Leak *l = new Leak[2];
        print( cout, { { "jan", l[0] }, { string( "pi" ), l[1] } } );
        delete [] l;
    }

    {
        cout << endl << "Teste 3" << endl;
        shared_ptr<Leak> l ( new Leak() );
        print( cout, { { "jan", *l }, { string( "pi" ), *l } } );
    }

    {
        cout << endl << "Teste 4" << endl;
        Leak a, b, c;
        vector<Leak> v = { a, b };
        print( cout, { { "v", v }, { "c", c } } );
    }

    return 0;
}
