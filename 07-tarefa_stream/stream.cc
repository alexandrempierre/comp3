#include "stream.h"

template <typename InputIterator, typename Function>
Function for_each(InputIterator first, InputIterator last, Function fn) {
    while (first != last) {
        fn(*first);
        ++first;
    }

    return fn;
}

template <typename Numeric, int Size, typename Function>
auto operator |(Numeric(&arr)[Size], Function fn) {
    return for_each(arr, arr+Size, fn);
}

template <typename Numeric, typename Function>
auto operator |(const std::vector<Numeric> v, Function fn) {
    return for_each(v.begin(), v.end(), fn);
}