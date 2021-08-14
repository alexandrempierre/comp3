#include <iostream>
#include <initializer_list>

class AbstractPair {
    public:  
        virtual std::ostream& imprime(std::ostream& out) const = 0;

        virtual ~AbstractPair() {}
};

template<typename A, typename B>
class ImplPair: public AbstractPair {
    public:
        ImplPair(const A& a, const B& b): a(a), b(b) { }

        ~ImplPair() { }

        std::ostream& imprime(std::ostream& out) const {
            return out << a << " = " << b << std::endl;
        }
    private:
        A a;
        B b;
};

class Pair {
    public:
        template<typename A, typename B>
        Pair(A a, B b) {
            p = std::shared_ptr<AbstractPair>( new ImplPair<A,B>(a,b) );
        }

        Pair(const Pair& item): p(item.p) { }

        ~Pair() { }

        std::ostream& imprime (std::ostream& out) const {
            return p->imprime(out);
        }
    private:
        /* AbstractPair* p; */
        std::shared_ptr<AbstractPair> p;
};

void print(std::ostream& out, std::initializer_list<Pair> lista) {
    for (Pair item : lista) {
        item.imprime(out);
    }
};