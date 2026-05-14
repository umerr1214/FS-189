#include <iostream>
#include <string>
#include <iomanip> // Required for std::fixed and std::setprecision

// Readability / Efficiency Issue:
// 1. Efficiency: Unnecessary copies of arguments are made inside the function body
//    (temp_a, temp_b), even though arguments are already passed by value. For larger
//    user-defined types, this leads to additional, avoidable copying costs.
// 2. Readability: The conditional logic for determining the minimum is overly verbose
//    and includes a redundant equality check. A simpler ternary operator or direct
//    if-else block would be more concise and easier to read.
template <typename T>
T findMin(T val1, T val2) {
    T temp_a = val1; // Unnecessary copy 1
    T temp_b = val2; // Unnecessary copy 2

    // Overly verbose and redundant logic for finding the minimum
    if (temp_a < temp_b) {
        return temp_a;
    } else {
        // This 'if (temp_a == temp_b)' check is redundant.
        // If temp_a is not < temp_b, then it must be >= temp_b.
        // In either case (temp_a == temp_b or temp_a > temp_b), temp_b is the correct value to return if we want the minimum.
        if (temp_a == temp_b) {
            return temp_a; // Returns temp_a on equality.
        } else {
            return temp_b; // Returns temp_b if temp_a > temp_b.
        }
    }
}

int main() {
    std::cout << "Demonstrating findMin with readability/efficiency issue:" << std::endl;

    // Integer tests
    int i_a = 5, i_b = 10;
    std::cout << "Min of " << i_a << " and " << i_b << " is: " << findMin(i_a, i_b) << std::endl; // Expected: 5

    int i_c = 10, i_d = 5;
    std::cout << "Min of " << i_c << " and " << i_d << " is: " << findMin(i_c, i_d) << std::endl; // Expected: 5

    int i_e = 7, i_f = 7;
    std::cout << "Min of " << i_e << " and " << i_f << " is: " << findMin(i_e, i_f) << std::endl; // Expected: 7

    std::cout << std::endl;

    // Double tests
    double d_x = 3.14, d_y = 2.71;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Min of " << d_x << " and " << d_y << " is: " << findMin(d_x, d_y) << std::endl; // Expected: 2.71

    double d_p = 1.0, d_q = 1.0;
    std::cout << "Min of " << d_p << " and " << d_q << " is: " << findMin(d_p, d_q) << std::endl; // Expected: 1.00

    return 0;
}