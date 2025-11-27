#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    const double sqrt5 = std::sqrt(5);
    const double phi = (1 + sqrt5) / 2;    // золотое сечение
    const double psi = (1 - sqrt5) / 2;    // сопряженное значение
    double fib_double = (std::pow(phi, n) - std::pow(psi, n)) / sqrt5;
    int fib_int = static_cast<int>(std::round(fib_double));
    std::cout << fib_int;
}
