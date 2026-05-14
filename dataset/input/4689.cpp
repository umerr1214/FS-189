#include <iostream>
#include <string>

template <typename T>
const T& findMax(const T& a, const T& b) { // Correct: uses const reference and concise ternary operator
    return (a > b) ? a : b;
}

int main() {
    // Test with integers
    std::cout << "Max of 5 and 10: " << findMax(5, 10) << std::endl;
    std::cout << "Max of 15 and 7: " << findMax(15, 7) << std::endl;
    std::cout << "Max of 8 and 8: " << findMax(8, 8) << std::endl;

    // Test with doubles
    std::cout << "Max of 3.14 and 2.71: " << findMax(3.14, 2.71) << std::endl;
    std::cout << "Max of 1.0 and 2.0: " << findMax(1.0, 2.0) << std::endl;

    // Test with characters
    std::cout << "Max of 'a' and 'z': " << findMax('a', 'z') << std::endl;
    std::cout << "Max of 'X' and 'B': " << findMax('X', 'B') << std::endl;

    // Test with std::string
    std::string s1 = "apple";
    std::string s2 = "banana";
    std::cout << "Max of \"" << s1 << "\" and \"" << s2 << "\": " << findMax(s1, s2) << std::endl;

    return 0;
}