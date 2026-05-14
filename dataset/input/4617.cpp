#include <iostream>
#include <string> // Required for std::string

// Function template to find the minimum of two values of any data type
template <typename T>
T findMin(T val1, T val2) {
    // Using a ternary operator for conciseness, readability, and efficiency
    return (val1 < val2) ? val1 : val2;
}

int main() {
    // Demonstrate usage with int
    int i1 = 10, i2 = 5;
    std::cout << "Min of " << i1 << " and " << i2 << " (int): " << findMin(i1, i2) << std::endl; // Expected: 5

    // Demonstrate usage with double
    double d1 = 3.14, d2 = 2.71;
    std::cout << "Min of " << d1 << " and " << d2 << " (double): " << findMin(d1, d2) << std::endl; // Expected: 2.71

    // Demonstrate usage with std::string
    std::string s1 = "apple";
    std::string s2 = "banana";
    std::cout << "Min of \"" << s1 << "\" and \"" << s2 << "\" (std::string): " << findMin(s1, s2) << std::endl; // Expected: apple

    // Demonstrate with different order for std::string
    std::string s3 = "zebra";
    std::string s4 = "yak";
    std::cout << "Min of \"" << s3 << "\" and \"" << s4 << "\" (std::string): " << findMin(s3, s4) << std::endl; // Expected: yak

    return 0;
}