#include <iostream>

using namespace std;

class Base {
    public:
        virtual int size() = 0;
        
        virtual void metodo() {
            cout << "Metodo da classe base!" << endl;
        }

        void metodo2() {
            cout << "Metodo da classe base!" << endl;
        }

        virtual ~Base() {}
    
    private:
        int x;
};

class Derivada: public Base {
    public:
        int size() {
            return sizeof(*this);
        }

        void metodo() {
            cout << "Metodo da classe derivada!" << endl;
        }
};

void foo(Base& x) {
    x.metodo();
}

int main(int argc, char const *argv[]) {
    /* Base* b; */
    Derivada d;
    Base *pb = &d;

    foo(d);

    /* foo(*b);
    foo(d);
    pb->metodo();

    cout << "Base:     " << sizeof(b)
         << " &b: " << &b << endl;
    cout << "Derivada:     " << sizeof(d)
         << " &d: " << &d << endl; */

    return 0;
}
