#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class MathOperations {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    // Logical error: This method should add all three integers, but only adds the first two.
    int add(int a, int b, int c) {
        return a + b; // Should be a + b + c
    }
};

int main() {
    MathOperations ops;

    // Test case for int, int
    std::cout << "Sum of 5 and 10 (int): " << ops.add(5, 10) << std::endl; // Expected: 15

    // Test case for double, double
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Sum of 5.5 and 10.5 (double): " << ops.add(5.5, 10.5) << std::endl; // Expected: 16.0

    // Test case for int, int, int (will show logical error)
    std::cout << "Sum of 1, 2, and 3 (int): " << ops.add(1, 2, 3) << std::endl; // Expected: 6, Actual: 3

    return 0;
}