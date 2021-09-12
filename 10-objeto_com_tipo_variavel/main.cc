#include "var.h"

using namespace std;

Var print( const Var& o ) {
    cout << "{ nome: " << o["nome"]
        << ", idade: " << o["idade"]( o )
        << ", nascimento: " << o["nascimento"]
        << ", print: " << o["print"] 
        << ", atr: " << o["atr"] 
        << " }" << endl;
        
    return Var();     
}

void imprime( Var v ) {
    v["print"]( v );
}

int main(int argc, char const *argv[]) {
    /* cout << "Teste -1" << endl;
    {
        try {
            Var obj = newObject();
            obj["x"] = 0;

            cout << obj["y"] << endl;
        } catch (Var::Erro e) {
            cout << "Erro fatal: " << e() << endl;
        }
    } */
    
    /* cout << "Teste 0" << endl;
    {
        Var l[6] = {2, 3.14, "palavra", false, true, 'X'};

        for (auto& x : l) {
            cout << x << " || ... :" << endl;
            for (auto& y: l) {
                cout << " " << x << " || " << y << " = " << (x || y) << endl;
            }
            cout << endl;
        }
    } */

    /* cout << endl << "Teste 1" << endl;
    {
        Var a, b = 10;
        cout << a << " " << b << endl;
        a = 3.14;
        b = "uma string";
        cout << a << " " << b << endl;

        //undefined 10
        //3.14 uma string
    } */

    /* cout << endl << "Teste 2" << endl;
    {
        try {
            Var a;
            a = 3;
            cout << a["mes"] << endl;
        } catch(Var::Erro e) {
            cout << "Erro fatal: " << e();
        }
        //Erro fatal: Essa variável não é um objeto
    } */

    /* cout << endl << endl << "Teste 3" << endl;
    {
        try {
            Var a;
            a = newObject();
            cout << a(5) << endl;
        } catch (Var::Erro e) {
            cout << "Erro fatal: " << e();
        }
        //Erro fatal: Essa variável não pode ser usada como função
    } */

    /* cout << endl << endl << "Teste 4" << endl;
    {
        Var a[5] = { true, 'X', 2, 2.1, "abracadabra" };
        Var b = 200, c = 300.1, d = "palavra ";
        for( auto& x: a ) {
            cout << x+b << "," << x+c << "," << x+d << "," << 3 / x << "," << 1.1 * x << ","
            << Var(x && true) << "," << Var(x && false) <<  "," << Var(b >= x) << "," << Var(x < d) << endl;
        }
        //undefined,undefined,undefined,         undefined, undefined,true,     false,    undefined,undefined
        //288,      undefined,Xpalavra ,         undefined, undefined,undefined,undefined,true,     true
        //202,      302.1,    undefined,         1,         2.2,      undefined,undefined,true,     undefined
        //202.1,    302.2,    undefined,         1.42857,   2.31,     undefined,undefined,true,     undefined
        //undefined,undefined,abracadabrapalavra ,undefined,undefined,undefined,undefined,undefined,true
    } */

    /* cout << endl << "Teste 5" << endl;
    {
        Var a, b;
        a = newObject();
        b = "José Maria";
        a["nome"] = b;
        a["nascimento"] = 1998;
        b = "Maria José";
        try {
            print( a );
        } catch( Var::Erro e ) {
            cout << "Erro fatal: " << e() << endl;
        }
        cout << a << " " << a["nome"] << " " << a["nascimento"] << endl;
        //{ nome: José Maria, idade: Erro fatal: Essa variável não pode ser usada como função
        //object José Maria 1998
    } */

    /* cout << endl << endl << "Teste 6" << endl;
    {
        try {
            Var a, b;
            a = 10.1;
            b = []( auto x ){ return x + x; };
            cout << b( a ) << " ";
            cout << b( "oba" ) << " ";
            cout << b( 'X' ) << " ";
            cout << b( true );
        } catch(Var::Erro e) {
            cout << "Erro fatal: " << e() << endl;
        }
        //'"20.2 obaoba XX undefined"
    } */

    cout << endl << endl << "Teste 7" << endl;
    {
        Var a = newObject();
        Var b = "José", c = "Maria";
        a["nome"] = b + ' ' + c;
        a["idade"] = []( auto v ) { return 2019 - v["nascimento"]; };
        a["nascimento"] = 1990;
        a["print"] = &print;
        b = a;
        imprime( a );
        a["nascimento"] = 2001;
        imprime( a );
        imprime( b );
        //{ nome: José Maria, idade: 29, nascimento: 1990, print: function, atr: undefined }
        //{ nome: José Maria, idade: 18, nascimento: 2001, print: function, atr: undefined }
        //{ nome: José Maria, idade: 18, nascimento: 2001, print: function, atr: undefined }
    }

    /* cout << endl << endl << "Teste 8" << endl;
    {
        Var a, b;
        a = newObject();
        a["init"] = []( auto x ) { x["nome"] = "Manoel";
                                x["idade"] = []( auto v ) { return 2019 - v["nascimento"]; };
                                x["nascimento"] = 1987;
                                x["print"] = &print;
                                return x; };
        b = [a]( auto x ){ return x( a ); };
        a["funcao"] = b;
        b = &print;
        a["funcao"]( a["init"] );
        a["atr"] = a["init"]( newObject() );
        a["funcao"]( b );
        imprime( a["atr"] );
        //{ nome: Manoel, idade: 32, nascimento: 1987, print: function, atr: object }
        //{ nome: Manoel, idade: 32, nascimento: 1987, print: function, atr: undefined }
    } */

    cout << endl;

    return 0;
}
