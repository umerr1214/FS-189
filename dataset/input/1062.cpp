#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        // Semantic Error: The method for adding doubles incorrectly converts them to integers
        // before summing, losing any fractional parts.
        return static_cast<double>(static_cast<int>(a) + static_cast<int>(b));
    }
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    std::cout << calc.add(5, 7) << std::endl;
    std::cout << calc.add(5.5, 7.7) << std::endl; // Will output 12.0 instead of 13.2 (5+7)
    std::cout << calc.add(1, 2, 3) << std::endl;
    std::cout << calc.add(2.1, 3.9) << std::endl; // Will output 5.0 instead of 6.0 (2+3)
    return 0;
}