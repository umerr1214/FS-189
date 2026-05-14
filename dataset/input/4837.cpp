#include <iostream>
#include <string>
#include <iomanip> // Required for std::fixed and std::setprecision

// Robustness Issue:
// The function template returns the second argument (val2) when both arguments are equal.
// While technically correct as it returns "a" minimum, this deviates from std::min's
// typical stable behavior of returning the first argument if values are equivalent.
// This can be a subtle robustness issue for custom types where object identity or
// specific ordering for equal elements is expected.
template <typename T>
T findMin(T val1, T val2) {
    // If val1 is strictly less than val2, return val1.
    // Otherwise (if val1 >= val2), return val2.
    // This means if val1 == val2, val2 is returned.
    if (val1 < val2) {
        return val1;
    } else {
        return val2;
    }
}

int main() {
    std::cout << "Demonstrating findMin with robustness issue (returns second on equality):" << std::endl;

    // Integer tests
    int i_a = 5, i_b = 10;
    std::cout << "Min of " << i_a << " and " << i_b << " is: " << findMin(i_a, i_b) << std::endl; // Expected: 5

    int i_c = 10, i_d = 5;
    std::cout << "Min of " << i_c << " and " << i_d << " is: " << findMin(i_c, i_d) << std::endl; // Expected: 5

    int i_e = 7, i_f = 7;
    std::cout << "Min of " << i_e << " and " << i_f << " is: " << findMin(i_e, i_f) << std::endl; // Expected: 7 (returns i_f)

    std::cout << std::endl;

    // Double tests
    double d_x = 3.14, d_y = 2.71;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Min of " << d_x << " and " << d_y << " is: " << findMin(d_x, d_y) << std::endl; // Expected: 2.71

    double d_p = 1.0, d_q = 1.0;
    std::cout << "Min of " << d_p << " and " << d_q << " is: " << findMin(d_p, d_q) << std::endl; // Expected: 1.00 (returns d_q)

    return 0;
}