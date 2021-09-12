#include "filter.h"

using namespace std;

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    for ( auto x : v )
        out << x << " ";
     out << endl;

     return out;
}

void print (int x) {
    cout << x << " ";
}

int main( int argc, char* argv[]) {
    cout << "Teste 1" << endl;
    {
        vector<int> v1 = { 2, 9, 8, 8, 7, 4 };
        auto result = v1 | []( int x ) { return x % 2 == 0; };
        for( auto x : result )
            cout << x << " ";
    }

    cout << endl << endl << "Teste 2" << endl;
    {
        vector<int> v1 = { 2, 9, 8, 8, 7, 4 };
        v1 | []( int x ) { return x % 2 == 0; } | [] ( int x ) { cout << x << " "; };
    }

    cout << endl << endl << "Teste 3" << endl;
    {
        int v1[] = { 2, 9, 8, 8, 7, 4 };
        auto result = v1 | []( int x ) { return x % 2 == 0; };
        for( auto x : result )
            cout << x << " ";
    }

    cout << endl << endl << "Teste 4" << endl;
    {
        int v1[] = { 2, 9, 8, 8, 7, 4 };
        v1 | []( int x ) { return x % 2 == 0; } | [] ( int x ) { cout << x << " "; };
    }

    cout << endl << endl << "Teste 5" << endl;
    {
        map<string,string> v = { { "a", "1" }, { "b", "2" }, { "c", "3" }, { "d", "4" }, { "e", "5" } };
        v | []( auto x ){ return pair{ x.first, stod( x.second ) }; } | []( auto p ) { cout << p.second + 1.1 << " "; };
    }

    cout << endl << endl << "Teste 6" << endl;
    {
        map<string,string> v = { { "a", "1" }, { "b", "2" }, { "c", "3" }, { "d", "4" }, { "e", "5" }, { "f", "6" } };
        auto par = []( auto x ){ return stoi( x.second ) % 2 == 0; };
        auto upper_first = []( auto x ){ string st = x.first; transform(st.begin(), st.end(), st.begin(), ::toupper); return st; };
        v | par | upper_first | []( auto st ) { cout << st + "! "; };
    }

    cout << endl << endl << "Teste 7" << endl;
    {
        map<string,string> v = { { "a", "1" }, { "b", "2" }, { "c", "3" }, { "d", "4" }, { "e", "5" }, { "F", "6" } };
        auto par = []( auto x ){ return stoi( x.second ) % 2 == 0; };
        auto first = []( pair<string,string> p ) { return p.first; };
        auto upper = []( string st ){ transform(st.begin(), st.end(), st.begin(), ::toupper); return st; };
        vector<string> result = v | par | first | upper;
        result | []( auto st ) { cout << st + "! "; };
    }

    cout << endl << endl << "Teste 8" << endl;
    {
        vector<string> v1 = { "janeiro", "fevereiro", "março", "abril", "maio" };
        v1 | &string::length | [] ( int x ) { cout << x << " "; };
    }

    cout << endl;

    return 0;
}