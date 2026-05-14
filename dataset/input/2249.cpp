#include <iostream>
#include <iomanip>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        // Logical Error: Performs subtraction instead of addition for doubles
        return a - b;
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