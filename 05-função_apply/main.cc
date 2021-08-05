#include "apply.h"

using namespace std;

double seno( double n ) { return sin(n); }

int id( int n ) { return n; }

string roman( int n ) {
    map<int,string> rom = { { 1, "I" }, { 2, "II" }, { 3, "III" }, { 4, "IV" }, { 5, "V" }, { 6, "VI" }, { 7, "VII" }, { 8, "VIII" } } ; 

    return rom[n]; 
}

struct FunctorSimples { 
    string operator()( int n ) { return roman( n ) + "!"; }
};

struct FunctorTemplate { 
    template <typename T>
    T operator()( T n ) { return n+n; }
};

template <typename T>
ostream& operator << ( ostream& o, const vector<T>& v ) {
    o << "[ ";
    for( auto x : v )
        o << x << " ";
        
    return o << "]";
}

int main( int argc, char* argv[]) {     
    cout << "Teste 1" << endl;
    vector<int> v1{ 1, 2, 3, 4, 5 };
    vector<int> r1 = ::apply( v1, id );
    cout << r1; cout << endl;

    cout << endl << "Teste 2" << endl;
    vector<int> v2{ 1, 2, 3, 4, 5 };
    vector<double> r2 = ::apply( v2, seno );
    cout << r2; cout << endl;

    cout << endl << "Teste 3" << endl;
    auto v3 = { 1, 2, 3, 4, 5 };
    cout << ::apply( v3, []( auto n ) -> double { return n*n + 0.1; } );
    cout << endl;

    cout << endl << "Teste 4" << endl;
    auto v4 = vector{ vector{ 1, 3 }, { 4, 15 }, { 3, 10 } };
    cout << ::apply( v4, []( auto lin ) { return lin[0]*lin[0] - lin[1]; } );
    cout << endl;

    cout << endl << "Teste 5" << endl;
    auto v5 = { 1, 2 }, u5 = { 3, 4 };
    cout << ::apply( v5, [u5]( auto x ) { return ::apply( u5, [x]( auto y ){ return vector{ x, y }; } ); } );
    cout << endl;

    cout << endl << "Teste 6" << endl;
    cout << ::apply( vector{ 1, 2, 3 }, FunctorSimples() );
    cout << endl;

    cout << endl << "Teste 7" << endl;
    cout << ::apply( vector{ 1, 2, 3 }, FunctorTemplate() ) << ::apply( vector<string>{ "a", "b", "c" }, FunctorTemplate() );
    cout << endl;

    cout << endl << "Teste 8" << endl;
    cout << ::apply( { 1, 2, 3, 4, 5 }, roman );
    cout << endl;

    cout << endl << "Teste 9" << endl;
    int v9[] = { 1, 2, 3, 4, 5 };
    vector<int> u9 = ::apply( v9, id );
    cout << u9;
    cout << endl;

    cout << endl << "Teste 10" << endl;
    int v10[] = { 1, 2, 3, 4, 5 };
    vector<string> u10 = ::apply( v10, roman );
    cout << u10;
    cout << endl;

  return 0;
}