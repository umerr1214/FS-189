#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }

    double add(double a, double b) {
        return a + b;
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    Calculator calc;

    // Test 1: Add two integers
    int sum1 = calc.add(5, 10);
    std::cout << "Sum of 5 and 10 (int): " << sum1 << std::endl;

    // Test 2: Add three integers
    int sum2 = calc.add(1, 2, 3);
    std::cout << "Sum of 1, 2, and 3 (int): " << sum2 << std::endl;

    // Test 3: Add two doubles
    double sum3 = calc.add(5.5, 4.5);
    std::cout << "Sum of 5.5 and 4.5 (double): " << sum3 << std::endl;

    return 0;
}