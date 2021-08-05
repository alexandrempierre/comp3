#include <iostream>

using namespace std;

class Media {
    public:
        double operator () (double a, double b) {
            return (a + b) / 2;
        }
};

int main(int argc, char const *argv[])
{
    Media m;

    /* operator() é o nome do método da classe Media que redefine o uso do operador parênteses */
    auto x = &Media::operator();

    cout << m(4, 6.7) << endl;

    return 0;
}
