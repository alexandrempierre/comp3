#include "derivador.h"

using namespace std;

int main(int argc, char const *argv[])
{
    /* cout << "Teste 1" << endl;
    {
        auto f = 3.0 + x + x;

        cout << "f(x) = " << f.str() << ", f'(x) = " << f.dx_str();
        // f(x) = ((((3)+(x)))+(x)), f'(x) = ((((0)+(1)))+(1))
    } */

    /* cout << endl << "Teste 2" << endl;
    {
        auto f = x*x*( x + 8.0 ) + x;

        cout << "f(x) = " << f.str() << ", f'(x) = " << f.dx_str();
    } */

    /* cout << endl << "Teste 3" << endl;
    {
        double v = 0.5;
        auto f = sin( x * x * cos( 3.14 * x + 1.0 ) );

        cout << "f(" << v << ")=" << f.e(v) << ", f'(" << v << ")=" << f.dx(v) << endl;
        // f(0.5)=-0.208714, f'(0.5)=-1.23783
    } */

    /* cout << endl << "Teste 4" << endl;
    {
        double v = 3.14;
        auto f = sin( x * x - cos( 3.14 * x + 1.0 ) );

        cout << "f(" << v << ")=" << f.e(v) << ", f'(" << v << ")=" << f.dx(v) << endl;
        // f(3.14)=-0.53995, f'(3.14)=-2.66732
    } */

    /* cout << endl << "Teste 5" << endl;
    {
        auto f =  x->*3;

        cout << "f(x) = " << f.str() << ", f'(x) = " << f.dx_str();
        // f(x) = (x)^3, f'(x) = (3*(1)*(x)^2)
    } */

    /* cout << endl << "Teste 5.5" << endl;
    {
        Cte c(3);
        double v = -7.3;
        auto f = c->*3;

        cout << "f(" << v << ")=" << f.e(v) << ", f'(" << v << ")=" << f.dx(v) << endl;
        // f(-7.3)=-335.727, f'(-7.3)=145.27
    } */

    /* cout << endl << "Teste 6" << endl;
    {
        double v = -7.3;
        auto f = x->*3 + x->*2;

        cout << "f(" << v << ")=" << f.e(v) << ", f'(" << v << ")=" << f.dx(v) << endl;
        // f(-7.3)=-335.727, f'(-7.3)=145.27
    } */

    /* cout << endl << "Teste 7" << endl;
    {
        double v = -0.5;
        auto f = 1.0 / (sin(x)->*2 + cos(x)->*2)->*4;

        cout << "f(" << v << ")=" << f.e(v) << ", f'(" << v << ")=" << f.dx(v) << endl;
        // f(-0.5)=1, f'(-0.5)=0
    } */

    /* cout << endl << "Teste 8" << endl;
    {
        double v = 0.1;
        auto f = 1 / (1 + exp( -2*( x - 1 )->*4 ) );

        cout << "f(" << v << ")=" << f.e(v) << ", f'(" << v << ")=" << f.dx(v) << endl;
        // f(0.1)=0.787881, f'(0.1)=0.97467
    } */

    cout << endl << "Teste 9" << endl;
    {
        auto f = exp( x * log( x - 8.0 ) + 1.0 );

        std::string expected{"f(x) = exp(((((x)*(log(((x)-(8))))))+(1))), f'(x) = (exp(((((x)*(log(((x)-(8))))))+(1)))*((((1)*(log(((x)-(8))))+(x)*((1/(((x)-(8)))*((1)-(0))))))+(0)))"};
        std::string result{"f(x) = " + f.str() + ", f'(x) = " + f.dx_str()};
        
        if (expected != result) {
            cout << "Esperado:" << endl << expected << endl;
            cout << endl << "Obtido:" << endl << result << endl;
        }
        // f(3)=27, f'(3)=56.6625
    }

    /* cout << endl << "Teste 10" << endl;
    {
        double v = 3;
        auto f =  2 * x->*1.1;

        cout << "f(" << v << ")=" << f.e(v) << ", f'(" << v << ")=" << f.dx(v) << endl;
        // Operador de potenciação definido apenas para inteiros
        // Essa nota será dada manualmente - gere um erro estático. Exemplo:
        // In file included from teste.gerado.cc:7:0:
        // derivador.cc: In instantiation of ‘constexpr auto operator->*(F, G) [with F = <lambda(double)>; G = double]’:
        // teste.gerado.cc:14:19:   required from here
        // derivador.cc:68:9: error: static assertion failed: Operador de potenciação definido apenas para inteiros
        //        static_assert( !is_same_v< double, G >, "Operador de potenciação definido apenas para inteiros" );
        //        ^~~~~~~~~~~~~
        // sh: 1: ./executavel: not found
    } */

    cout << endl;

    return 0;
}
