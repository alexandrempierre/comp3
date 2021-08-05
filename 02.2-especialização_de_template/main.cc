#include <iostream>
#include <string.h>

template<typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

template<>
const char* Max(const char* a, const char* b) {
    return strcmp(a,b) > 0 ? a : b;
}

int main(int argc, char const *argv[])
{
    using namespace std;

    cout << Max(1.4, 1.6) << endl;
    cout << Max<double>(1.4, 1) << endl;
    cout << Max("Alfa", "Beta") << endl;

    return 0;
}
