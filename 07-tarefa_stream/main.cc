#include "stream.h"

using namespace std;

void print (int x) {
    cout << x << " ";
}

class PrintCube {
    public:
        PrintCube(ostream& out): out(out) { }
        void operator () (int n) {
            out << n*n*n << " ";
        }
    private:
        ostream& out;
};

int main( int argc, char* argv[]) {
    int tab[10] =  { 1, 2, 3, 2, 3, 4, 6, 0, 1, 8 };
    vector<int> v{ 2 , 6, 8 };
    tab | []( int x ) { cout << x*x << endl; };
    tab | [ &v ]( int x ) { v.push_back( x ); };
    v | []( int x ) { cout << x*x << endl; };
    v | &print;
    v | PrintCube(cout);

    return 0;
}