#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    // SEMANTIC ERROR: The return type is int, but it adds doubles.
    // The result of (a + b) will be truncated to an integer, losing precision.
    int add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    std::cout << "2 + 3 = " << calc.add(2, 3) << std::endl;
    std::cout << "2.5 + 3.5 = " << calc.add(2.5, 3.5) << std::endl; // Will output 6 (truncated from 6.0)
    std::cout << "1 + 2 + 3 = " << calc.add(1, 2, 3) << std::endl;
    return 0;
}