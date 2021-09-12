#include "iterator.h"

bool is_even (int x) {
    return x % 2 == 0;
}

int main(int argc, char const *argv[]) {
    std::vector<int>v = {1,2,3,4,5};
    
    Filter f(v, is_even);

    for ( auto x : f ) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
