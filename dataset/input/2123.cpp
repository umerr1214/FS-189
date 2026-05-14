#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class MathOperations {
public:
    int add(int a, int b) {
        return a - b; // Logical error: should be a + b
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    MathOperations mo;

    // Demonstrate calling each version
    int sum_int = mo.add(5, 10);
    std::cout << "Sum of two ints: " << sum_int << std::endl; // Expected: 15, Actual: -5

    double sum_double = mo.add(3.5, 2.7);
    std::cout << std::fixed << std::setprecision(1) << "Sum of two doubles: " << sum_double << std::endl; // Expected: 6.2, Actual: 6.2

    int sum_three_int = mo.add(1, 2, 3);
    std::cout << "Sum of three ints: " << sum_three_int << std::endl; // Expected: 6, Actual: 6

    return 0;
}