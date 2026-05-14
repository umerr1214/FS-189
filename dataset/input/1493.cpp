#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a - b; // LOGICAL ERROR: Performs subtraction instead of addition
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    std::cout << "2 + 3 = " << calc.add(2, 3) << std::endl;
    std::cout << "2.5 + 3.5 = " << calc.add(2.5, 3.5) << std::endl; // Will output 2.5 - 3.5 = -1
    std::cout << "1 + 2 + 3 = " << calc.add(1, 2, 3) << std::endl;
    return 0;
}