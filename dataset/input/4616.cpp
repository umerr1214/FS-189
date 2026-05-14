#include <iostream>
#include <string>

template <typename T>
T findMin(T val1, T val2) {
    // This implementation is correct but less readable and potentially less efficient
    // compared to a more concise approach like a ternary operator.
    // It introduces an unnecessary temporary variable 'result' and verbose if-else.
    T result; // Unnecessary temporary variable
    if (val1 < val2) {
        result = val1;
    } else {
        result = val2;
    }
    return result;
}

int main() {
    // Demonstrate with int
    int i1 = 10, i2 = 5;
    std::cout << "Min of " << i1 << " and " << i2 << " (int): " << findMin(i1, i2) << std::endl;

    // Demonstrate with double
    double d1 = 3.14, d2 = 2.71;
    std::cout << "Min of " << d1 << " and " << d2 << " (double): " << findMin(d1, d2) << std::endl;

    // Demonstrate with std::string
    std::string s1 = "apple";
    std::string s2 = "banana";
    std::cout << "Min of \"" << s1 << "\" and \"" << s2 << "\" (std::string): " << findMin(s1, s2) << std::endl;

    return 0;
}