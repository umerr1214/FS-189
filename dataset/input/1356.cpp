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
};

int main() {
    Calculator calc;
    std::cout << "Adding two integers (5, 10): " << calc.add(5, 10) << std::endl;
    // Semantic Error: No matching function for call to 'add(float, int)'
    std::cout << "Adding two doubles (5.5, 10.5): " << calc.add(5.5f, 10) << std::endl;
    std::cout << "Adding three integers (1, 2, 3): " << calc.add(1, 2, 3) << std::endl;
    return 0;
}