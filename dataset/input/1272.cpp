#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    float add(float a, float b) {
        // Semantic error: implicit type conversion (truncation) before addition,
        // leading to loss of precision for float inputs.
        return (int)a + (int)b;
    }
};

int main() {
    Calculator calc;
    std::cout << "Sum (int): " << calc.add(5, 3) << std::endl;
    std::cout << std::fixed << std::setprecision(6) << "Sum (double): " << calc.add(5.5, 3.2) << std::endl;
    std::cout << std::fixed << std::setprecision(6) << "Sum (float): " << calc.add(5.5f, 3.2f) << std::endl;
    return 0;
}