#include <iostream>

// C++ function template that incorrectly finds the minimum instead of the maximum
template <typename T>
T findMax(T val1, T val2) {
    // Logical error: returns the smaller value
    return (val1 < val2) ? val1 : val2;
}

int main() {
    // Test with int
    int int_val1 = 5;
    int int_val2 = 10;
    int int_result = findMax(int_val1, int_val2);
    std::cout << "Max of " << int_val1 << " and " << int_val2 << " is: " << int_result << std::endl; // Expected: 10, Actual: 5

    // Test with double
    double double_val1 = 3.5;
    double double_val2 = 7.2;
    double double_result = findMax(double_val1, double_val2);
    std::cout << "Max of " << double_val1 << " and " << double_val2 << " is: " << double_result << std::endl; // Expected: 7.2, Actual: 3.5

    return 0;
}