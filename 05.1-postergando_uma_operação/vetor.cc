#include "vetor.h"

using namespace std;

class Vetor {
    public:
        class MiddleAttr {
            private:
                MiddleAttr(Vetor *v): vetor(v) {}
                friend class Vetor;
            public:
                MiddleAttr operator ,(int n) {
                    *vetor = n;
                    return *this;
                }
            private:
                Vetor *vetor;
        };

        MiddleAttr operator =(int n) {
            tab.push_back(n);
            return MiddleAttr(this);
        }

        friend ostream& operator <<(ostream& out, Vetor v);
    private:
        vector<int> tab;
};

ostream& operator <<(ostream& out, Vetor v) {
    for (auto x : v.tab) {
        out << x << " ";
    }
    out << endl;

    return out;
}

/* class Vetor;

class MiddleAttr {
    public:
        MiddleAttr(Vetor* v): vetor(v) {}
        MiddleAttr operator ,(int n);
    private:
        Vetor *vetor;
};

class Vetor {
    public:
        MiddleAttr operator =(int n) {
            tab.push_back(n);
            return MiddleAttr(this);
        }

        friend ostream& operator <<(ostream& out, Vetor v);
    private:
        vector<int> tab;
};

inline MiddleAttr MiddleAttr::operator ,(int n) {
    *vetor = n;
    return *this;
}

ostream& operator <<(ostream& out, Vetor v) {
    for (auto x : v.tab) {
        out << x << " ";
    }
    out << endl;

    return out;
} */