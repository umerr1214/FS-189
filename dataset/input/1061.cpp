#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        // Logical Error: This method performs multiplication instead of addition.
        return a * b; 
    }
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    std::cout << calc.add(5, 7) << std::endl;
    std::cout << calc.add(5.0, 7.0) << std::endl; // Will output 35.0 instead of 12.0
    std::cout << calc.add(1, 2, 3) << std::endl;
    std::cout << calc.add(2.0, 3.0) << std::endl; // Will output 6.0 instead of 5.0
    return 0;
}