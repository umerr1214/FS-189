#include <iostream>

class Calculator {
pubic: // Syntax Error: Misspelled 'public'
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

    // Test 1: add two integers
    int res1 = calc.add(5, 3);
    std::cout << "Add two integers (5, 3): " << res1 << std::endl;

    // Test 2: add two doubles
    double res2 = calc.add(5.5, 3.2);
    std::cout << "Add two doubles (5.5, 3.2): " << res2 << std::endl;

    // Test 3: add three integers
    int res3 = calc.add(1, 2, 3);
    std::cout << "Add three integers (1, 2, 3): " << res3 << std::endl;

    return 0;
}