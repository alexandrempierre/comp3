#include "iterator.h"

class Filter: public std::vector<int> {
    public:
        template <typename Function>
        Filter(std::vector<int> v, Function f) {
            for ( auto x : v ) {
                if ( f(x) ) this->push_back(x);
            }
        }
};

