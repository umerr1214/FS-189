#include <iostream>

// C++ function template to find the maximum of two values
template <typename T>
T findMax(T val1, T val2) {
    return (val1 > val2) ? val1 : val2;
}

int main() {
    // Test with int
    int int_val1 = 5;
    int int_val2 = 10;
    int int_result = findMax(int_val1, int_val2) // Missing semicolon here
    std::cout << "Max of " << int_val1 << " and " << int_val2 << " is: " << int_result << std::endl;

    // Test with double
    double double_val1 = 3.5;
    double double_val2 = 7.2;
    double double_result = findMax(double_val1, double_val2);
    std::cout << "Max of " << double_val1 << " and " << double_val2 << " is: " << double_result << std::endl;

    return 0;
}