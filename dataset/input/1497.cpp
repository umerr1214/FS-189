#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Calculator {
public:
    // All add methods are const-correct as they do not modify the object's state
    int add(int a, int b) const {
        return a + b;
    }

    double add(double a, double b) const {
        return a + b;
    }

    int add(int a, int b, int c) const {
        return a + b + c;
    }
};

int main() {
    Calculator calc; // Concise and clear variable name

    std::cout << "--- Correct Version Demonstration ---" << '\n'; // Efficient newline character

    // Demonstrate adding two integers
    int sum_int_2 = calc.add(10, 20);
    std::cout << "Sum of two integers (10 + 20): " << sum_int_2 << '\n';

    // Demonstrate adding two doubles with appropriate precision setting
    double sum_double_2 = calc.add(15.5, 7.25);
    std::cout << std::fixed << std::setprecision(2); // Set precision once for doubles
    std::cout << "Sum of two doubles (15.5 + 7.25): " << sum_double_2 << '\n';

    // Demonstrate adding three integers
    int sum_int_3 = calc.add(100, 200, 300);
    std::cout << "Sum of three integers (100 + 200 + 300): " << sum_int_3 << '\n';

    return 0;
}