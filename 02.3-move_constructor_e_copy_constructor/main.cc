#include <iostream>

using namespace std;

template<int L, int C>
class Matriz {
    public:
        typedef double Linha[C];

        Matriz(): v(new Linha[L]) {
            cout << "Criou   : " << this << "/" << v << endl;
        }

        Matriz(Matriz&& m): v(m.v) {
            cout << "Move constructor!" << endl;
            m.v = nullptr;
        }

        Matriz(const Matriz& m): v(new Linha[L]) {
            cout << "Copy constructor! " << this << "/" << v << endl;
            for (int i = 0; i < L; i++) {
                for (int j = 0; j < C; j++) {
                    v[i][j] = m.v[i][j];
                }
            }
        }

        ~Matriz() {
            cout << "Destruiu: " << this << "/" << v << endl;
            delete [] v;
        }

        const Matriz& operator = (const Matriz& m) {
            cout << "Copiou elementos" << endl;
            for (int i = 0; i < L; i++) {
                for (int j = 0; j < C; j++) {
                    v[i][j] = m.v[i][j];
                }
            }
            
            return *this;
        }

        const Matriz& operator = (Matriz&& m) {
            cout << "Move assignment! " << endl;
            cout << " deletou " << v << endl;
            delete [] v;
            v = m.v;
            m.v = nullptr;
            
            return *this;
        }

        void soma (const Matriz& a, const Matriz& b) {
            for (int i = 0; i < L; i++) {
                for (int j = 0; j < C; j++) {
                    v[i][j] = a.v[i][j] + b.v[i][j];
                }
            }
        }
    private:
        Linha *v;
};

template<int L, int C>
Matriz<L,C> operator + (const Matriz<L,C>& a, const Matriz<L,C>& b) {
    Matriz<L,C> resultado;

    resultado.soma(a,b);

    return resultado;
}

/* Matriz<300,500> foo (const Matriz<300,500>& m) {
    return m;
} */

int main(int argc, char const *argv[]) {
    Matriz<300,500> a, b;
    Matriz<300,500> c;

    /* c = foo(a); */
    c = a + b;

    return 0;
}
