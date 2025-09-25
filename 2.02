#include <iostream>
#include <cmath>

int main() {
    const double epsilon = 1e-15;
    double a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    if (std::abs(a) < epsilon) {
        if (std::abs(b) < epsilon) {
            if (std::abs(c) < epsilon) {
                std::cout << "R"; //Бесконечно решений
            } else {
                std::cout << "Нет корней"; // Нет решений
            }
        } else {
            std::cout << -c / b; // Один корень
        }
    } else {
        double D = b * b - 4 * a * c;
        if (std::abs(D) < epsilon) {  //если D = 0 то 1 корень
            std::cout << -b / (2 * a);
        } else if (D > epsilon) {
            std::cout << (-b - std::sqrt(D)) / (2 * a) << " " << -b + std::sqrt(D)) / (2 * a);
        } else {
            std::cout << "Нет корней";
        }
    }
}
