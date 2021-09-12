#include "derivador.h"

// Teste 1

class Cte {
  public:
    Cte(double y): y(y) {}

    double e(double x) {
      return y;
    }

    double dx(double x) {
      return 0;
    }
  private:
    double y;
};

class X {
  public:
    double e(double x) {
      return x;
    }

    double dx(double x) {
      return 1;
    }
};

template <typename F1, typename F2>
class Product {
  public:
    Product(F1 f1, F2 f2): f1(f1), f2(f2) {}

    double e(double x) {
      return f1.e(x) * f2.e(x);
    }

    double dx(double x) {
      return f1.dx(x)*f2.e(x) + f1.e(x)*f2.dx(x);
    }
  
  private:
    F1 f1;
    F2 f2;
};


template <typename F1, typename F2>
Product<F1, F2> operator *(F1 f1, F2 f2) {
  return Product<F1, F2>(f1, f2);
}

template <typename F2>
Product<Cte, F2> operator *(double n, F2 f2) {
  return Product<Cte, F2>(n, f2);
}

template <typename F1>
Product<F1, Cte> operator *(F1 f1, double n) {
  return Product<F1, Cte>(f1, n);
}

// Teste 2

template <typename F1, typename F2>
class Sum {
  public:
    Sum(F1 f1, F2 f2): f1(f1), f2(f2) {}

    double e(double x) {
      return f1.e(x) + f2.e(x);
    }

    double dx(double x) {
      return f1.dx(x) + f2.dx(x);
    }
  
  private:
    F1 f1;
    F2 f2;
};

template <typename F1, typename F2>
Sum<F1, F2> operator +(F1 f1, F2 f2) {
  return Sum<F1, F2>(f1, f2);
}

template <typename F2>
Sum<Cte, F2> operator +(double n, F2 f2) {
  return Sum<Cte, F2>(n, f2);
}

template <typename F1>
Sum<F1, Cte> operator +(F1 f1, double n) {
  return Sum<F1, Cte>(f1, n);
}

// Teste 3

template <typename F>
class Sin {
  public:
    Sin(F f): f(f) {}

    double e(double x) {
      return std::sin( f.e(x) );
    }

    double dx(double x) {
      return std::cos( f.e(x) ) * f.dx(x);
    }
  private:
    F f;
};

template <typename F, typename In>
Sin<F> sin(In x) {
  return Sin<F>(x);
}

template<typename F>
Sin<F> sin(F f) {
  return Sin<F>(f);
}

template<>
Sin<Cte> sin(double x) {
  return Sin<Cte>(x);
}

template <typename F>
class Cos {
  public:
    Cos(F f): f(f) {}

    double e(double x) {
      return std::cos( f.e(x) );
    }

    double dx(double x) {
      return -std::sin( f.e(x) ) * f.dx(x);
    }
  private:
    F f;
};

template <typename F, typename In>
Cos<F> cos(In x) {
  return Cos<F>(x);
}

template<typename F>
Cos<F> cos(F f) {
  return Cos<F>(f);
}

template<>
Cos<Cte> cos(double x) {
  return Cos<Cte>(x);
}

// Teste 4

template <typename F1, typename F2>
class Subs {
  public:
    Subs(F1 f1, F2 f2): f1(f1), f2(f2) {}

    double e(double x) {
      return f1.e(x) - f2.e(x);
    }

    double dx(double x) {
      return f1.dx(x) - f2.dx(x);
    }
  
  private:
    F1 f1;
    F2 f2;
};

template <typename F1, typename F2>
Subs<F1, F2> operator -(F1 f1, F2 f2) {
  return Subs<F1, F2>(f1, f2);
}

template <typename F2>
Subs<Cte, F2> operator -(double n, F2 f2) {
  return Subs<Cte, F2>(n, f2);
}

template <typename F1>
Subs<F1, Cte> operator -(F1 f1, double n) {
  return Subs<F1, Cte>(f1, n);
}

// Teste 5

template <typename F1, typename F2>
class Div {
  public:
    Div(F1 f1, F2 f2): f1(f1), f2(f2) {}

    double e(double x) {
      return f1.e(x) / f2.e(x);
    }

    double dx(double x) {
      return (f1.dx(x)*f2.e(x) - f1.e(x)*f2.dx(x)) / (f2.e(x)*f2.e(x));
    }
  
  private:
    F1 f1;
    F2 f2;
};

template <typename F1, typename F2>
Div<F1, F2> operator /(F1 f1, F2 f2) {
  return Div<F1, F2>(f1, f2);
}

template <typename F2>
Div<Cte, F2> operator /(double n, F2 f2) {
  return Div<Cte, F2>(n, f2);
}

template <typename F1>
Div<F1, Cte> operator /(F1 f1, double n) {
  return Div<F1, Cte>(f1, n);
}

// Teste 6

template <typename F>
class Pow {
  public:
    Pow(F f, int n): f(f), n(n) {}

    double e(double x) {
      return p(x, 1, n);
    }

    double dx(double x) {
      return p(x, n, n-1) * f.dx(x);
    }
  
  private:
    F f;
    int n;

    double p(double x, double r, int m) {
      while (m-- > 0) r *= f.e(x);

      return r;
    }
};

/* template <typename F>
Pow<F> operator ->*(F f, int n) {
  return Pow<F>(f, n);
} */

// Teste 7

// Teste 8

template <typename F>
class Exp {
  public:
    Exp(F f): f(f) {}

    double e(double x) {
      return std::exp(f.e(x));
    }

    double dx(double x) {
      return std::exp(f.e(x))*f.dx(x);
    }
  private:
    F f;
};

template <typename F>
Exp<F> exp(F f) {
  return Exp<F>(f);
}

template <typename F2>
Div<Cte, F2> operator /(int n, F2 f2) {
  return Div<Cte, F2>(n, f2);
}

template <typename F2>
Sum<Cte, F2> operator +(int n, F2 f2) {
  return Sum<Cte, F2>(n, f2);
}

template <typename F2>
Product<Cte, F2> operator *(int n, F2 f2) {
  return Product<Cte, F2>(n, f2);
}

template <typename F1>
Subs<F1, Cte> operator -(F1 f1, int n) {
  return Subs<F1, Cte>(f1, n);
}

// Teste 9

template <typename F>
class Log {
  public:
    Log(F f): f(f) {}

    double e(double x) {
      return std::log(f.e(x));
    }

    double dx(double x) {
      return 1.0/f.e(x) * f.dx(x);
    }
  private:
    F f;
};

template <typename F>
Log<F> log(F f) {
  return Log<F>(f);
}

// Teste 10 

template <typename F, typename N>
Pow<F> operator ->*(F f, N n) {
  static_assert(std::is_same<int,N>::value, "Operador de potenciação definido apenas para inteiros");
  return Pow<F>(f, n);
}

// Declaração de x

X x;