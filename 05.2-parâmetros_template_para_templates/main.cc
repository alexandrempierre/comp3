#include <vector>
#include <list>
#include <iostream>

using namespace std;

template <typename T, typename A, template<typename, typename> class Estrutura>
ostream& operator <<(ostream& out, Estrutura<T,A>& col) {
    for(auto x : col) {
        out << x << " ";
    }

    return out;
}

int main(int argc, char const *argv[]) {
    vector<int> v{1,2,4};
    list<int> l{5,8,9};

    cout << v << endl;
    cout << l << endl;
    
    return 0;
}
