#include <iostream>
#include <string> // Included for potential string usage, though not strictly needed for const char*

template <typename T>
T findMin(T val1, T val2) {
    return (val1 < val2) ? val1 : val2;
}

int main() {
    // Demonstrate with int
    int a = 10, b = 20;
    std::cout << "Min of " << a << " and " << b << " is: " << findMin(a, b) << std::endl;

    // Demonstrate with double
    double x = 5.5, y = 3.14;
    std::cout << "Min of " << x << " and " << y << " is: " << findMin(x, y) << std::endl;

    // Demonstrate with string literals (const char*).
    // Semantic error: operator< for const char* compares memory addresses, not lexicographical content.
    const char* s1 = "apple";
    const char* s2 = "banana";
    std::cout << "Min of \"" << s1 << "\" and \"" << s2 << "\" is: " << findMin(s1, s2) << std::endl;

    const char* s3 = "zebra";
    const char* s4 = "apple";
    std::cout << "Min of \"" << s3 << "\" and \"" << s4 << "\" is: " << findMin(s3, s4) << std::endl;

    return 0;
}