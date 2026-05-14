#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        return a + b // Missing semicolon here
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
    std::cout << "Sum of 5 and 7: " << calc.add(5, 7) << std::endl;
    std::cout << "Sum of 5.5 and 7.7: " << calc.add(5.5, 7.7) << std::endl;
    std::cout << "Sum of 1, 2, and 3: " << calc.add(1, 2, 3) << std::endl;
    return 0;
}