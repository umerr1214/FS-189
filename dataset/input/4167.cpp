#include <iostream>
#include <string> // Included to demonstrate string comparison (optional, but good for completeness)

// Function template to get the larger of two comparable values.
// Arguments are passed by const reference (`const T&`) to avoid unnecessary copying,
// improving efficiency for potentially large user-defined types.
// The return value is also by const reference to avoid copying the result if possible,
// and ensures we return a reference to one of the original arguments.
template <typename T>
const T& getLarger(const T& val1, const T& val2) {
    return val1 > val2 ? val1 : val2;
}

int main() {
    std::cout << "--- Demonstrating getLarger function ---" << std::endl;

    // Demonstrate with int
    int int_a = 42;
    int int_b = 100;
    std::cout << "Larger of " << int_a << " and " << int_b << ": " << getLarger(int_a, int_b) << std::endl; // Expected: 100

    // Demonstrate with double
    double double_x = 99.9;
    double double_y = 99.89;
    std::cout << "Larger of " << double_x << " and " << double_y << ": " << getLarger(double_x, double_y) << std::endl; // Expected: 99.9

    // Demonstrate with another int example
    int int_c = -5;
    int int_d = 0;
    std::cout << "Larger of " << int_c << " and " << int_d << ": " << getLarger(int_c, int_d) << std::endl; // Expected: 0

    // Demonstrate with another double example
    double double_p = 1.234567;
    double double_q = 1.2345678;
    std::cout << "Larger of " << double_p << " and " << double_q << ": " << getLarger(double_p, double_q) << std::endl; // Expected: 1.2345678

    // Demonstrate with std::string (for completeness, `std::string` overloads `operator>`)
    std::string str_s1 = "hello";
    std::string str_s2 = "world";
    std::cout << "Larger of \"" << str_s1 << "\" and \"" << str_s2 << "\": \"" << getLarger(str_s1, str_s2) << "\"" << std::endl; // Expected: "world"

    std::cout << "--- End of demonstration ---" << std::endl;

    return 0;
}