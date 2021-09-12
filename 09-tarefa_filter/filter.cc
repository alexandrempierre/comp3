#include "filter.h"

template <typename In, typename Out=int, typename Function>
auto operator |(const std::vector<In>& in, Function&& f) {
    using value_type_out = typename std::invoke_result< Function, In >::type;
    
    constexpr bool is_filter = std::is_same< bool, value_type_out >::value;

    std::vector<Out> out;

    if constexpr(is_filter) {
        std::vector<In> out;

        for (auto x : in) {
            if ( std::invoke(f, x) ) {
                out.push_back(x);
            }
        }

        return out;
    }
    else  {
        constexpr bool void_return = std::is_void< value_type_out >::value;

        if constexpr(void_return) {
            for (auto x : in) {
                std::invoke(f, x);
            }
        }
        else {
            std::vector<value_type_out> out;

            for (auto x : in) {
                out.push_back( std::invoke(f, x) );
            }

            return out;
        }
    }
}

template <int Size, typename Function>
std::vector<int> operator |(const int (&arr)[Size], Function&& f) {
    std::vector<int> out;
    int x;
    
    constexpr bool is_filter = std::is_same< bool, typename std::invoke_result<Function, int>::type >::value;

    for (int i = 0; i < Size; i++) {
        x = arr[i];

        if constexpr(is_filter) {
            if( std::invoke(f, x) ) out.push_back(x);
        }
        else std::invoke(f, x);
    }

    return out;
}

template <typename ValueIn, typename Function>
auto operator |(const std::map<std::string, ValueIn>& in, Function&& f) {
    using value_type_in = typename std::pair<std::string, ValueIn>;

    std::vector< value_type_in > v;
    
    for ( auto p : in ) v.push_back(p);

    return v | f;
}

