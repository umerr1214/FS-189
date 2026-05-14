#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c // Syntax Error: Missing semicolon
    }
};

int main() {
    Calculator calc;
    std::cout << calc.add(2, 3) << std::endl;
    std::cout << calc.add(2.5, 3.5) << std::endl;
    std::cout << calc.add(1, 2, 3) << std::endl;
    return 0;
}