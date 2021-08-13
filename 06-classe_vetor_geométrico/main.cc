#include "vetor.h"

using namespace std;

int main( int argc, char* argv[]) {
    Vetor<3,int> v, u;

    /* v = 2, 4, 7, 34, 56;
    v = 87, 59; */

    v = 1, 0, 0;
    u = 0, 1, 0;

    cout << 2*u << endl;

    return 0;
}