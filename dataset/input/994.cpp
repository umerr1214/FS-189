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
    std::cout << "Add two ints (5, 3): " << calc.add(5, 3) << std::endl;
    std::cout << "Add two doubles (5.5, 3.2): " << calc.add(5.5, 3.2) << std::endl;
    std::cout << "Add three ints (1, 2, 3): " << calc.add(1, 2, 3) << std::endl;
    return 0;
}