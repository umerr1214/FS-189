#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Calculator {
public:
    // Overloaded add method for two integers
    int add(int num1, int num2) {
        return num1 + num2;
    }

    // Overloaded add method for two doubles
    double add(double num1, double num2) {
        return num1 + num2;
    }

    // Overloaded add method for three integers
    int add(int num1, int num2, int num3) {
        return num1 + num2 + num3;
    }
};

int main() {
    Calculator calculator;

    std::cout << "Testing Correct Calculator implementation:\n";
    std::cout << std::fixed << std::setprecision(2); // Set precision for double output

    std::cout << "Sum of 10 and 20 (int): " << calculator.add(10, 20) << std::endl;
    std::cout << "Sum of 10.5 and 20.3 (double): " << calculator.add(10.5, 20.3) << std::endl;
    std::cout << "Sum of 1, 2, and 3 (int): " << calculator.add(1, 2, 3) << std::endl;
    std::cout << "Sum of -5 and 15 (int): " << calculator.add(-5, 15) << std::endl;
    std::cout << "Sum of 0.1 and 0.2 (double): " << calculator.add(0.1, 0.2) << std::endl;
    std::cout << "Sum of 100, 200, and -50 (int): " << calculator.add(100, 200, -50) << std::endl;

    return 0;
}