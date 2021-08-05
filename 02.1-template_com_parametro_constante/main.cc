#include <iostream>

using namespace std;

template<int N>
int escala(int x) {
    return N*x;
}

int main(int argc, char const *argv[]) {
    cout << escala<10>(8) << endl;
    
    //
    int (*ptrFun)( int ) = &escala<7>;

    cout << ptrFun(9) << endl;

    //
    auto ptrFun2 = &escala<78>;

    cout << ptrFun2(10) << endl;

    return 0;
}
