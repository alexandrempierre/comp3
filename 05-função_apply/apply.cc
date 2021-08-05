#include "apply.h"

using namespace std;

template <typename Iterable, typename Func>
auto apply (Iterable input, Func f) -> vector<decltype(f(*input.begin()))> {
    vector<decltype(f(*input.begin()))> output;

    for (auto x : input) {
        output.push_back( f(x) );
    }

    return output;
}

template <typename Func>
auto apply (const initializer_list<int> input, Func f) -> vector<decltype(f(*input.begin()))> {
    vector<decltype(f(*input.begin()))> output;

    for (auto x : input) {
        output.push_back( f(x) );
    }

    return output;
}

template <typename Array, int Size, typename Func>
auto apply (Array (& input)[Size], Func f) -> vector<decltype(f(input[0]))> {
    vector<decltype(f(input[0]))> output;

    for (int i = 0; i < Size; ++i) {
        output.push_back( f(input[i]) );
    }

    return output;
}