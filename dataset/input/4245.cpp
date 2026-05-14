#include <iostream>
#include <string> // Not strictly needed for int/double, but good for generic types

// Correct Version:
// Implements a robust, efficient, and readable function template.
// - Arguments are passed by `const T&` to avoid unnecessary copies for large types
//   and allow usage with non-copyable types, while ensuring the original values are not modified.
// - The return type is `T` (by value) to prevent potential dangling references if the
//   arguments were temporaries. This is generally the safest approach for generic
//   functions like `find_maximum`.
// - The logic is concise and clear using the ternary operator.
template <typename T>
T find_maximum(const T& a, const T& b) {
    return (a > b) ? a : b;
}

int main() {
    // Test with int
    int int_val1 = 100;
    int int_val2 = 50;
    int max_int = find_maximum(int_val1, int_val2);
    std::cout << "Maximum of " << int_val1 << " and " << int_val2 << " (int): " << max_int << std::endl;

    // Test with double
    double double_val1 = 99.9;
    double double_val2 = 100.1;
    double max_double = find_maximum(double_val1, double_val2);
    std::cout << "Maximum of " << double_val1 << " and " << double_val2 << " (double): " << max_double << std::endl;

    // Test with different literal types (implicit conversion)
    int max_mixed = find_maximum(7, 3);
    std::cout << "Maximum of " << 7 << " and " << 3 << " (literals): " << max_mixed << std::endl;

    double max_mixed_double = find_maximum(12.3f, 12.34); // float and double
    std::cout << "Maximum of " << 12.3f << " and " << 12.34 << " (float, double): " << max_mixed_double << std::endl;

    // Test with std::string (demonstrates genericity)
    std::string s1 = "apple";
    std::string s2 = "banana";
    std::string max_string = find_maximum(s1, s2);
    std::cout << "Maximum of \"" << s1 << "\" and \"" << s2 << "\" (string): \"" << max_string << "\"" << std::endl;

    return 0;
}