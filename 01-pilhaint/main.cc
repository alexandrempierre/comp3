#include "pilhaint.cc"

using namespace std;

int main(int argc, char const *argv[]) {
    PilhaInt p;
    int x;
    
    p << 19 << 18 << 17;
    p.print(cout);

    return 0;
}
