#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

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
} // Syntax Error: Missing semicolon after class definition

int main() {
    Calculator calc;
    std::cout << "Sum of 1 and 2 (int): " << calc.add(1, 2) << std::endl;
    std::cout << "Sum of 1, 2, and 3 (int): " << calc.add(1, 2, 3) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "Sum of 1.5 and 2.5 (double): " << calc.add(1.5, 2.5) << std::endl;
    return 0;
}