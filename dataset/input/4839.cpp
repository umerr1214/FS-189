#include <iostream>
#include <string>
#include <iomanip> // Required for std::fixed and std::setprecision

// Correct Version:
// Implements a C++ function template `findMin` that accepts two arguments
// of any type `T` by value, as specified in the question, and returns the
// smaller of the two. The implementation is concise, correct, and follows
// common practices for simple comparison functions (e.g., similar to std::min's
// stability, returning the first argument if values are equal).
template <typename T>
T findMin(T val1, T val2) {
    // Uses the ternary operator for concise and correct comparison.
    // This expression ensures that if val2 is strictly less than val1, val2 is returned.
    // Otherwise (if val1 <= val2), val1 is returned, which provides stable behavior
    // consistent with std::min for equal elements.
    return (val2 < val1) ? val2 : val1;
}

int main() {
    std::cout << "Demonstrating findMin (Correct Version):" << std::endl;

    // Integer tests
    int i_a = 5, i_b = 10;
    std::cout << "Min of " << i_a << " and " << i_b << " is: " << findMin(i_a, i_b) << std::endl; // Expected: 5

    int i_c = 10, i_d = 5;
    std::cout << "Min of " << i_c << " and " << i_d << " is: " << findMin(i_c, i_d) << std::endl; // Expected: 5

    int i_e = 7, i_f = 7;
    std::cout << "Min of " << i_e << " and " << i_f << " is: " << findMin(i_e, i_f) << std::endl; // Expected: 7 (returns i_e due to stability)

    std::cout << std::endl;

    // Double tests
    double d_x = 3.14, d_y = 2.71;
    std::cout << std::fixed << std::setprecision(2); // Set precision for double output
    std::cout << "Min of " << d_x << " and " << d_y << " is: " << findMin(d_x, d_y) << std::endl; // Expected: 2.71

    double d_p = 1.0, d_q = 1.0;
    std::cout << "Min of " << d_p << " and " << d_q << " is: " << findMin(d_p, d_q) << std::endl; // Expected: 1.00 (returns d_p due to stability)

    return 0;
}