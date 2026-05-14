#include <iostream>
#include <string>
#include <type_traits> // For std::common_type (though decltype is often preferred for max)

// Correct Version:
// 1. Uses `const T&` for parameters to ensure efficiency and avoid unnecessary copies.
// 2. Uses a concise ternary operator for readability.
// 3. Employs `decltype(a > b ? a : b)` for the return type, which correctly deduces
//    the common type for mixed-type comparisons (e.g., `int` and `double` will return `double`),
//    preserving precision and ensuring robustness.
template <typename T1, typename T2>
auto findMax(const T1& a, const T2& b) -> decltype(a > b ? a : b) {
    return (a > b) ? a : b;
}

int main() {
    // Demonstrate with int
    int maxInt = findMax(10, 20);
    std::cout << "Max of 10 and 20 (int): " << maxInt << std::endl; // Expected: 20

    // Demonstrate with double
    double maxDouble = findMax(3.14, 2.71);
    std::cout << "Max of 3.14 and 2.71 (double): " << maxDouble << std::endl; // Expected: 3.14

    // Demonstrate with char
    char maxChar = findMax('a', 'z');
    std::cout << "Max of 'a' and 'z' (char): " << maxChar << std::endl; // Expected: z

    // Demonstrate with mixed types (int and double) - handles correctly, returns double
    double maxMixed1 = findMax(5, 5.5);
    std::cout << "Max of 5 and 5.5 (int, double): " << maxMixed1 << std::endl; // Expected: 5.5

    double maxMixed2 = findMax(5.5, 5);
    std::cout << "Max of 5.5 and 5 (double, int): " << maxMixed2 << std::endl; // Expected: 5.5

    // Demonstrate with mixed char and int - handles correctly, returns int
    int maxMixedCharInt = findMax('c', 100); // 100 is ASCII for 'd'
    std::cout << "Max of 'c' and 100 (char, int): " << maxMixedCharInt << std::endl; // Expected: 100

    // Demonstrate with string (to show const T& efficiency for complex types)
    std::string s1 = "apple";
    std::string s2 = "banana";
    std::string maxString = findMax(s1, s2);
    std::cout << "Max of \"" << s1 << "\" and \"" << s2 << "\" (string): " << maxString << std::endl; // Expected: banana

    return 0;
}