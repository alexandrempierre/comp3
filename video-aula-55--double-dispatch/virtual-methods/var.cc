#include "var.h"

class Var {
    public:
        class Undefined {
            public:
                virtual Var sel_soma(const Undefined& arg1) const { return Var(); }
                virtual Var soma( int arg2 ) const { return Var(); }
                virtual Var soma( double arg2 ) const { return Var(); }
                virtual Var soma( char arg2 ) const { return Var(); }
                virtual Var soma( bool arg2 ) const { return Var(); }
                virtual Var soma( std::string arg2 ) const { return Var(); }

                virtual std::ostream& imprime(std::ostream& out) const { return out << "undefined"; }
        };

        class Int: public Undefined {
            public:
                Int(int n): n(n) {}

                virtual Var sel_soma(const Undefined& arg1) const { return arg1.soma(n); }
                virtual Var soma( int arg2 ) const { return n + arg2; }
                virtual Var soma( double arg2 ) const { return n + arg2; }

                std::ostream& imprime(std::ostream& out) const { return out << n; }

                int value() const { return n; }
            private:
                int n;
        };

        class String: public Undefined {
            public:
                String(std::string s): s(s) {}
                String(const char* s): s(s) {}

                virtual Var sel_soma(const Undefined& arg1) const { return arg1.soma(s); }
                virtual Var soma( char arg2 ) const { return s + arg2; }
                virtual Var soma( std::string arg2 ) const { return s + arg2; }

                std::ostream& imprime(std::ostream& out) const { return out << s; }

                std::string value() const { return s; }
            private:
                std::string s;
        };

        Var(): valor( new Undefined() ) {}
        Var(int n): valor( std::shared_ptr<Undefined>( new Int(n) ) ) {}
        Var(std::string s): valor( std::shared_ptr<Undefined>( new String(s) ) ) {}
        Var(const char* s): valor( std::shared_ptr<Undefined>( new String(s) ) ) {}

        Var operator +(const Var& v) const {
            return v.valor->sel_soma(*valor);
        }

        std::ostream& imprime(std::ostream& out) const {
            return valor->imprime(out);
        }
    private:
        std::shared_ptr<Undefined> valor;
};

/* Var operator +(const Var::Undefined& u, const Var::Undefined& v) {
    return v.sel_soma(u);
} */

template <typename Primitive>
Var operator +(const Primitive& p, const Var& v) {
    return Var(p) + v;
}

std::ostream& operator <<(std::ostream& out, const Var& v) {
    return v.imprime(out);
}