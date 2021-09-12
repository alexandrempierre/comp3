#include "var.h"

using namespace std;

int main(int argc, char const *argv[]) {
    cout << "Var(1) + int(1) = " << Var(1) + 1 << endl;
    cout << "Var(1) + int(1) = " << 1 + Var(1) << endl;
    cout << "Var(1) + double(3.14) = " << Var(1) + 3.14 << endl;
    cout << "double(3.14) + Var(1) = " << 3.14 + Var(1) << endl;
    cout << "Var(1) + Var(-5) = " << Var(1) + Var(-5) << endl;

    return 0;
}
