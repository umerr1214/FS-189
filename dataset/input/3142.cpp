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
        return a + b + c;
    }
} // Missing semicolon here

int main() {
    Calculator calc;
    std::cout << "Adding two integers: " << calc.add(5, 7) << std::endl;
    std::cout << "Adding two doubles: " << calc.add(5.5, 7.2) << std::endl;
    std::cout << "Adding three integers: " << calc.add(1, 2, 3) << std::endl;
    return 0;
}