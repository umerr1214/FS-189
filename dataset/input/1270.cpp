#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    float add(float a, float b) {
        return a + b;
    }
} // ERROR: Missing semicolon after class definition

int main() {
    Calculator calc;
    std::cout << "Sum (int): " << calc.add(5, 3) << std::endl;
    std::cout << "Sum (double): " << calc.add(5.5, 3.2) << std::endl;
    std::cout << "Sum (float): " << calc.add(5.5f, 3.2f) << std::endl;
    return 0;
}