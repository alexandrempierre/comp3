#include "vetor.h"

using namespace std;

template <int N, typename T>
class Vetor {
    public:
        Vetor() {
            tab.resize(N,0);
        }

        Vetor(const vector<T>& u) {
            tab = vector<T>(u);
        }

        class MiddleAttr {
            private:
                MiddleAttr(Vetor<N,T> *v): vetor(v) {}
                friend class Vetor<N,T>;
            public:
                MiddleAttr operator ,(T n) {
                    vetor->appendValue(n);
                    return *this;
                }
            private:
                Vetor<N,T> *vetor;
        };

        class MiddleCrossProduct {
            private:
                MiddleCrossProduct(Vetor<3,T> v): vetor(v.values()) {}
                friend class Vetor<3,T>;
            public:
                /**/
            private:
                vector<T> vetor;
        };

        MiddleAttr appendValue(T n) {
            tab[values_count++] = n;
            return MiddleAttr(this);
        }

        MiddleAttr operator =(T n) {
            values_count = 0;
            return appendValue(n);
        }

        Vetor<N,T> operator *(T n) {
            vector<T> u(tab);
            for(int i = 0; i < N; i++) {
                u[i] *= n;
            }

            return Vetor<N,T>(u);
        }

        Vetor<N,T> operator /(T n) {
            vector<T> u(tab);
            for(int i = 0; i < N; i++) {
                u[i] /= n;
            }

            return Vetor<N,T>(u);
        }

        Vetor<N,T> operator +(Vetor<N,T> v) {
            vector<T>u(v.values());
            for (int i = 0; i < N; i++) {
                u[i] += tab[i];
            }
            
            return Vetor<N,T>(u);
        }

        Vetor<N,T> operator -(Vetor<N,T> v) {
            vector<T>u(v.values());
            for (int i = 0; i < N; i++) {
                u[i] = tab[i] - u[i];
            }
            
            return Vetor<N,T>(u);
        }

        T operator *(Vetor<N,T> v) {
            vector<T>u(v.values());
            T s = 0;

            for (int i = 0; i < N; i++) {
                s += tab[i]*u[i];
            }
            
            return s;
        }

        MiddleCrossProduct operator *() {
            return MiddleCrossProduct(*this);
        }

        Vetor<3,T> operator *(MiddleCrossProduct m) {
            vector<T> u(m.vetor);
            vector<T> r(3,0);

            r[0] = tab[1]*u[2] - tab[2]*u[1];
            r[1] = tab[2]*u[0] - tab[0]*u[2];
            r[2] = tab[0]*u[1] - tab[1]*u[0];

            return Vetor<3,T>(r);
        }

        vector<T> values () {
            return tab;
        }
    private:
        vector<T> tab;
        int values_count;
};

template <int N, typename T>
Vetor<N,T> operator *(T x, Vetor<N,T>& v) {
    vector<T> u(v.values());

    for (int i = 0; i < N; i++) {
        u[i] *= x;
    }

    return Vetor<N,T>(u);
}

template <int N, typename T>
ostream& operator <<(ostream& out, Vetor<N,T> v) {
    for (auto x : v.values()) {
        out << x << " ";
    }

    return out;
}
