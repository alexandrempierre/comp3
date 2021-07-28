using namespace std;

class PilhaInt {
    public:
        PilhaInt(int max_elementos);
        PilhaInt(const PilhaInt& p);
        /* ~PilhaInt(); */

        const PilhaInt& operator =(const PilhaInt& p) {
            if (this == &p) return *this;

            max_elementos = p.max_elementos;
            conteudo = vector<int>(p.conteudo);
            quantidade = p.quantidade;

            return *this;
        }

        PilhaInt& operator <<(int valor) {
            empilha(valor);

            return *this;
        }

        void empilha(int valor);
        int desempilha();
        void print(ostream& o);

        int capacidade();
        void redimensiona(int n);
    private:
        vector<int> conteudo;
        int max_elementos;
        int quantidade;
};

PilhaInt::PilhaInt(int max_elementos=10) {
    this->max_elementos = max_elementos;
    conteudo = vector<int>(max_elementos, 0);

    for (int i = 0; i < max_elementos; i++) {
        conteudo[i] = 0;
    }
    quantidade = 0;
}

PilhaInt::PilhaInt(const PilhaInt& p) {
    max_elementos = p.max_elementos;
    conteudo = p.conteudo;
    quantidade = p.quantidade;
}

/* PilhaInt::~PilhaInt() {
    conteudo.~vector();
} */

void PilhaInt::empilha(int valor) {
    if (quantidade == max_elementos) {
        redimensiona(2*max_elementos);
    }

    conteudo[quantidade++] = valor;
}

int PilhaInt::desempilha() {
    return conteudo[--quantidade];
}

void PilhaInt::print(ostream& o) {
    o << "[ ";
    for (int i = 0; i < quantidade; i++) {
        o << conteudo[i];
        if (i < quantidade-1) {
            o << ",";
        }
        o << " ";
    }
    o << "]";
}

int PilhaInt::capacidade() {
    return max_elementos;
}

void PilhaInt::redimensiona(int n) {
    conteudo.resize(n,0);
    max_elementos = n;

    if (quantidade > max_elementos) {
        quantidade = max_elementos;
    }
}