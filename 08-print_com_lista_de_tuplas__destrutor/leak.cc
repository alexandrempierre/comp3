#include <iostream>

using namespace std;

class Leak {
    public:
        Leak(): n( ++contador ) {
            cout << "Criou: " << n << endl;
        }
        
        Leak( const Leak& p ): n( ++contador ) {
            cout << "Criou: " << n << " copiando de " << p.n << endl;
        }
        
        ~Leak() {
            cout << "Destruiu: " << n << endl;
        }
        
        ostream& print( ostream& o ) const {
            return o << "lk(" << n << ")";
        }
        
    private:
        static int contador;
        int n;
};

int Leak::contador = 0;