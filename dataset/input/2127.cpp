#include <iostream>
#include <iomanip> // For setting precision for double output

class MathOperations {
public:
    // Overloaded add method for two integers
    int add(int a, int b) {
        return a + b;
    }

    // Overloaded add method for two doubles
    double add(double a, double b) {
        return a + b;
    }

    // Overloaded add method for three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    MathOperations ops;

    // Demonstrate calling the add method for two integers
    int int_sum = ops.add(10, 20);
    std::cout << "Adding two integers (10 + 20): " << int_sum << '\n';

    // Demonstrate calling the add method for two doubles
    double double_sum = ops.add(3.5, 2.5);
    // Use std::fixed and std::setprecision for robust double output
    std::cout << std::fixed << std::setprecision(1) << "Adding two doubles (3.5 + 2.5): " << double_sum << '\n';

    // Demonstrate calling the add method for three integers
    int three_int_sum = ops.add(1, 2, 3);
    std::cout << "Adding three integers (1 + 2 + 3): " << three_int_sum << '\n';

    return 0;
}