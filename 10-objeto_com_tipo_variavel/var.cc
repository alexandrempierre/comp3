#include "var.h"

#include <memory>

class Var {
    public:
        class Erro {
            public:
                Erro( std::string msg ): msg(msg) {}
                
                std::string operator()() const {
                    return msg;
                }
            
            private:
                std::string msg;
        };

        class Undefined {
            public:
                virtual const Var find(const char* s) const {
                    throw Erro("Essa variável não é um objeto");
                } 

                virtual Var& at(const char* s) {
                    throw Erro("Essa variável não é um objeto");   
                }

                virtual const Var operator[](const char* s) const {
                    return find(s);
                }

                virtual Var& operator [](const char* s) {
                    return at(s);
                }
                
                virtual const Var operator()(const Var& n) const {
                    throw Var::Erro("Essa variável não pode ser usada como função");
                }

                // Soma
                virtual Var select_sum(const Undefined& arg1) const { return Var(); }
                virtual Var sum(int arg2) const { return Var(); }
                virtual Var sum(double arg2) const { return Var(); }
                virtual Var sum(char arg2) const { return Var(); }
                virtual Var sum(bool arg2) const { return Var(); }
                virtual Var sum(std::string arg2) const { return Var(); }

                // Multiplicação
                virtual Var select_mul(const Undefined& arg1) const { return Var(); }
                virtual Var mul(int arg2) const { return Var(); }
                virtual Var mul(double arg2) const { return Var(); }
                virtual Var mul(char arg2) const { return Var(); }
                virtual Var mul(bool arg2) const { return Var(); }
                virtual Var mul(std::string arg2) const { return Var(); }

                // Divisão
                virtual Var select_div(const Undefined& arg1) const { return Var(); }
                virtual Var div(int arg2) const { return Var(); }
                virtual Var div(double arg2) const { return Var(); }
                virtual Var div(char arg2) const { return Var(); }
                virtual Var div(bool arg2) const { return Var(); }
                virtual Var div(std::string arg2) const { return Var(); }

                // AND
                virtual Var select_and(const Undefined& arg1) const { return Var(); }
                virtual Var logic_and(int arg2) const { return Var(); }
                virtual Var logic_and(double arg2) const { return Var(); }
                virtual Var logic_and(char arg2) const { return Var(); }
                virtual Var logic_and(bool arg2) const { return Var(); }
                virtual Var logic_and(std::string arg2) const { return Var(); }

                // OR
                virtual Var select_or(const Undefined& arg1) const { return Var(); }
                virtual Var logic_or(int arg2) const { return Var(); }
                virtual Var logic_or(double arg2) const { return Var(); }
                virtual Var logic_or(char arg2) const { return Var(); }
                virtual Var logic_or(bool arg2) const { return Var(); }
                virtual Var logic_or(std::string arg2) const { return Var(); }

                // NOT
                virtual Var operator !() const { return Var(); }

                // Menor que
                virtual Var select_lt(const Undefined& arg1) const { return Var(); }
                virtual Var lt(int arg2) const { return Var(); }
                virtual Var lt(double arg2) const { return Var(); }
                virtual Var lt(char arg2) const { return Var(); }
                virtual Var lt(bool arg2) const { return Var(); }
                virtual Var lt(std::string arg2) const { return Var(); }
                
                virtual std::ostream& imprime(std::ostream& out) const {
                    return out << "undefined";
                }
        };

        class Boolean: public Undefined {
            public:
                Boolean( bool t ): t(t) {}

                // AND
                virtual Var select_and(const Undefined& arg1) const { return arg1.logic_and(t); }
                virtual Var logic_and(bool arg2) const { return t && arg2; }

                // OR
                virtual Var select_or(const Undefined& arg1) const { return arg1.logic_or(t); }
                virtual Var logic_or(bool arg2) const { return t || arg2; }

                // NOT
                virtual Var operator !() const { return !t; }

                std::ostream& imprime(std::ostream& out) const {
                    return t ? out << "true" : out << "false";
                }
            private:
                bool t;
        };

        class Int: public Undefined {
            public:
                Int( int n ): n(n) {}

                // Soma
                virtual Var select_sum(const Undefined& arg1) const { return arg1.sum(n); }
                virtual Var sum(int arg2) const { return n + arg2; }
                virtual Var sum(double arg2) const { return n + arg2; }
                virtual Var sum(char arg2) const { return n + arg2; }

                // Multiplicação
                virtual Var select_mul(const Undefined& arg1) const { return arg1.mul(n); }
                virtual Var mul(int arg2) const { return n*arg2; }
                virtual Var mul(double arg2) const { return n*arg2; }

                // Divisão
                virtual Var select_div(const Undefined& arg1) const { return arg1.div(n); }
                virtual Var div(int arg2) const { return n / arg2; }
                virtual Var div(double arg2) const { return n / arg2; }

                // Menor que
                virtual Var select_lt(const Undefined& arg1) const { return arg1.lt(n); }
                virtual Var lt(int arg2) const { return n < arg2; }
                virtual Var lt(double arg2) const { return n < arg2; }
                virtual Var lt(char arg2) const { return n < arg2; }

                std::ostream& imprime(std::ostream& out) const {
                    return out << n;
                }
            private:
                int n;
        };

        class Double: public Undefined {
            public:
                Double(double n): n(n) {}

                // Soma
                virtual Var select_sum(const Undefined& arg1) const { return arg1.sum(n); }
                virtual Var sum(int arg2) const { return n + arg2; }
                virtual Var sum(double arg2) const { return n + arg2; }

                // Multiplicação
                virtual Var select_mul(const Undefined& arg1) const { return arg1.mul(n); }
                virtual Var mul(int arg2) const { return n*arg2; }
                virtual Var mul(double arg2) const { return n*arg2; }

                // Divisão
                virtual Var select_div(const Undefined& arg1) const { return arg1.div(n); }
                virtual Var div(int arg2) const { return n / arg2; }
                virtual Var div(double arg2) const { return n / arg2; }

                // Menor que
                virtual Var select_lt(const Undefined& arg1) const { return arg1.lt(n); }
                virtual Var lt(int arg2) const { return n < arg2; }
                virtual Var lt(double arg2) const { return n < arg2; }

                std::ostream& imprime(std::ostream& out) const {
                    return out << n;
                }
            private:
                double n;
        };

        class Char: public Undefined {
            public:
                Char(char c): c(c) {}

                // Soma
                virtual Var select_sum(const Undefined& arg1) const { return arg1.sum(c); }
                virtual Var sum(int arg2) const { return c + arg2; }
                virtual Var sum(char arg2) const { return std::string{c} + std::string{arg2}; }
                virtual Var sum(std::string arg2) const { return c + arg2; }

                // Menor que
                virtual Var select_lt(const Undefined& arg1) const { return arg1.lt(c); }
                virtual Var lt(int arg2) const { return c < arg2; }
                virtual Var lt(char arg2) const { return c < arg2; }
                virtual Var lt(std::string arg2) const { return std::string{c} < arg2; }

                std::ostream& imprime(std::ostream& out) const {
                    return out << c;
                }
            private:
                char c;
        };

        class String: public Undefined {
            public:
                String (std::string s): s(s) {}
                String (const char* s): s(s) {}

                // Soma
                virtual Var select_sum(const Undefined& arg1) const { return arg1.sum(s); }
                virtual Var sum(char arg2) const { return s + arg2; }
                virtual Var sum(std::string arg2) const { return s + arg2; }

                // Menor que
                virtual Var select_lt(const Undefined& arg1) const { return arg1.lt(s); }
                virtual Var lt(char arg2) const { return s < std::string{arg2}; }
                virtual Var lt(std::string arg2) const { return s < arg2; }

                std::ostream& imprime(std::ostream& out) const {
                    return out << s;
                }
            private:
                std::string s;
        };

        class Object: public Undefined {
            public:
                Object () { }
                Object (const Object& o): obj(o.obj) {}
                Object (Object&& o) {
                    obj = o.obj;
                }

                // Operador []
                const Var find(const char* s) const {
                    map::const_iterator it = obj.find(s);

                    if (it == obj.end()) return Var();

                    return it->second;
                }

                Var& at(const char* s) {
                    return obj[s];
                }

                const Var operator [](const char* s) const {
                    return find(s);
                }

                Var& operator [](const char* s) {
                    return at(s);
                }

                std::ostream& imprime(std::ostream& out) const {
                    return out << "object";
                }
            private:
                using map = std::map<std::string, Var>;
                map obj;
        };

        template <typename Callable>
        class Function: public Undefined {
            public:
                Function (Callable f): f(f) {}

                // Operator ()
                const Var operator ()(const Var& x) const {
                    return f(x);
                }

                std::ostream& imprime(std::ostream& out) const {
                    return out << "function";
                }
            private:
                Callable f;
        };

        // Construtores
        Var(): valor( new Undefined() ) {}

        template <typename Callable>
        Var(Callable f): valor( std::shared_ptr<Undefined>( new Function<Callable>(f) ) ) {}

        Var(const Undefined& u) {
            *valor = u;
        }

        Var(int n): valor( std::shared_ptr<Undefined>( new Int(n) ) ) {}
        Var(double x): valor( std::shared_ptr<Undefined>( new Double(x) ) ) {}
        Var(bool t): valor( std::shared_ptr<Undefined>( new Boolean(t) ) ) {}
        Var(char c): valor( std::shared_ptr<Undefined>( new Char(c) ) ) {}
        Var(std::string s): valor( std::shared_ptr<Undefined>( new String(s) ) ) {}
        Var(const char* s): valor( std::shared_ptr<Undefined>( new String(s) ) ) {}

        Var(Object o): valor( new Object(o) ) {}

        // Soma
        Var operator +(const Var& arg2) const {
            return arg2.valor->select_sum(*valor);
        }

        // Multiplicação
        Var operator *(const Var& arg2) const {
            return arg2.valor->select_mul(*valor);
        }

        // Divisão
        Var operator /(const Var& arg2) const {
            return arg2.valor->select_div(*valor);
        }

        // AND
        Var operator &&(const Var& arg2) const {
            return arg2.valor->select_and(*valor);
        }

        // OR
        Var operator ||(const Var& arg2) const {
            return arg2.valor->select_or(*valor);
        }

        // NOT
        Var operator !() const {
            return !*valor;
        }

        // Menor que
        Var operator <(const Var& arg2) const {
            return arg2.valor->select_lt(*valor);
        }

        // Operadores sobrecarregados
        Var operator =(const Var& u) {
            valor = u.valor;

            return *this;
        }

        const Var operator[] (const char* s) const {
            return valor->find(s);
        }

        Var& operator[] (const char* s) {
            return valor->at(s);
        }

        const Var operator() (const Var& x) const {
            return (*valor)(x);
        }

        std::ostream& imprime(std::ostream& out) const {
            return valor->imprime(out);
        }
    private:
        std::shared_ptr<Undefined> valor;
};

Var operator *(double arg1, const Var& arg2) {
    return Var(arg1) * arg2;
}

Var operator /(int arg1, const Var& arg2) {
    return Var(arg1) / arg2;
}

Var operator &&(const Var& arg1, bool arg2) {
    return arg1 && Var(arg2);
}

Var operator -(int arg1, const Var& arg2) {
    return Var(arg1) + (-1.0)*arg2;
}

Var::Object newObject() {
    return Var::Object();
}

std::ostream& operator <<(std::ostream& out, const Var& v) {
    return v.imprime(out);
}

// Os operadores abaixo podem ser implementados utilizando os operadores !, || e <
Var operator > ( const Var& a, const Var& b ) { return b<a; }
Var operator != ( const Var& a, const Var& b ) { return (a<b) || (b<a); }
Var operator == ( const Var& a, const Var& b ) { return !(a!=b); }
Var operator <= ( const Var& a, const Var& b ) { return !(b<a); }
Var operator >= ( const Var& a, const Var& b ) { return !(a<b); }