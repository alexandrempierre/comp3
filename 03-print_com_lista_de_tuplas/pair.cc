#include "pair.h"

class AbstractPair {
    public:  
        virtual void imprime(std::ostream& o) = 0;

        virtual ~AbstractPair() {}
};

template<typename A, typename B>
class PairImpl: public AbstractPair {
    public:
        PairImpl(A a, B b) {
            this->a = a;
            this->b = b;
        }

        void imprime(std::ostream& out) {
            out << a << " = " << b << std::endl;
        }
    private:
        A a;
        B b;
};

class Pair {
    public:
        template<typename A, typename B>
        Pair(A a, B b) {
            p(new PairImpl<A,B>(a,b));
        }

        void imprime (std::ostream& out) {
            p().imprime(out);
        }

        void p(AbstractPair *p) {
            _p = p;
        }

        AbstractPair& p() {
            return *_p;
        }
    private:
        AbstractPair* _p;
};

/* Já definido no Moodle */
std::ostream& operator <<(std::ostream& out, std::vector<int> v) {
    out << "[ ";
    for (auto x : v) {
        out << x << " ";
    }
    out << "]";

    return out;
}

void print(std::ostream& out, std::initializer_list<Pair> lista) {
    for (Pair item : lista) {
        item.imprime(out);
    }
};