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

    // Semantic error: This method is intended to add three integers, but its return type is double.
    // Furthermore, the implementation performs division by 2.0, which might result in a non-integer value.
    // When the result is assigned to an 'int' variable in main, potential data loss (truncation) occurs.
    double add(int a, int b, int c) {
        return static_cast<double>(a + b + c) / 2.0;
    }
};

int main() {
    MathOperations mo;

    // Demonstrate calling each version
    int sum_int = mo.add(5, 10);
    std::cout << "Sum of two ints: " << sum_int << std::endl; // Expected: 15

    double sum_double = mo.add(3.5, 2.7);
    std::cout << std::fixed << std::setprecision(1) << "Sum of two doubles: " << sum_double << std::endl; // Expected: 6.2

    // This call to add(int, int, int) returns a double (e.g., 3.5 for 2,2,3).
    // When assigned to an int variable, it truncates to 3, losing the .5 precision.
    // This is a semantic issue as the method's return type and calculation lead to unexpected truncation
    // when used with an integer variable, which deviates from the implied integer sum for "add three integers".
    int sum_three_int = mo.add(2, 2, 3); // For (2,2,3), expected sum is 7. Method returns (2+2+3)/2.0 = 3.5. Assigned to int, becomes 3.
    std::cout << "Sum of three ints: " << sum_three_int << std::endl; // Expected: 7, Actual: 3

    return 0;
}