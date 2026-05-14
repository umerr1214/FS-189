#include <iostream>
#include <iomanip>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    // Semantic Error: The function is intended for double addition but returns an int,
    // causing truncation of the fractional part of the result.
    int add(double a, double b) {
        return static_cast<int>(a + b); // Should return double, but returns int
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    std::cout << calc.add(2, 3) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << calc.add(2.5, 3.5) << std::endl;
    std::cout << std::setprecision(6) << calc.add(1, 2, 3) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << calc.add(2.1, 3.8) << std::endl;
    return 0;
}