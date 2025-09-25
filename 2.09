#include <iostream>
#include <numeric>
#include <cassert>
int rec_gcd(int a, int b) { // рекурсивная функция
    if (b == 0) {
        return a;
    }
    return rec_gcd(b, a % b);
}
//НОК через НОД
int rec_lcm(int a, int b) {
    return (a / rec_gcd(a, b)) * b;
}

int main() {
    assert(rec_gcd(10, 15) == std::gcd(10,15));
    assert(rec_gcd(1230, 2313) == std::gcd(1230, 2313));
    assert(rec_gcd(1, 10000) == std::gcd(1,10000));
    assert(rec_lcm(123, 2000) == std::lcm(123,2000));
    assert(rec_lcm(1111, 111) == std::lcm(1111, 111));
    assert(rec_lcm(424, 15) == std::lcm(424,15));
    std::cout << "Correct" << '\n';
}
