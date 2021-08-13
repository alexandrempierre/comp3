#include <iostream>
#include <vector>

using namespace std;

template <typename InputIterator, typename Function>
Function for_each(InputIterator first, InputIterator last, Function fn) {
    while (first != last) {
        fn(*first);
        ++first;
    }

    return move(fn);
}

class PrintSqr {
    public:
        PrintSqr(ostream& out): out(out) {}

        void operator() (int n) {
            out << n*n << endl;
        }
    private:
        ostream& out;
};

int main(int argc, char const *argv[]) {
    int arr[5] = {5,4,3,2,1};
    
    for_each(arr, arr+5, PrintSqr(cout));

    return 0;
}
