#include <initializer_list>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    initializer_list<int> v = {1,2,3,4,5};
    auto vv = {"1", "2", "3", "4", "8", "0"};

    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;

    for (auto x : vv) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
