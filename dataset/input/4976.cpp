#include <iostream>
#include <string> // Required for std::to_string
#include <cmath>  // Required for std::abs
#include <limits> // For std::numeric_limits

// Readability / Efficiency Issue:
// This implementation converts the integer to a string to count its length.
// While correct, this approach is generally less efficient than a pure mathematical
// solution, especially for very large numbers, due to the overhead of string
// conversion and memory allocation.
int countDigits(int num) {
    // Handle negative numbers by taking absolute value before converting to string.
    // std::abs(INT_MIN) is undefined behavior for int, but std::to_string will
    // correctly convert INT_MIN itself. Using std::abs here for consistency with
    // positive numbers, though a direct to_string(num) would also work for negatives.
    // However, the question implies counting digits of the *magnitude*.
    std::string s = std::to_string(std::abs(num));
    return s.length();
}

int main() {
    std::cout << "Testing countDigits(12345): " << countDigits(12345) << std::endl;
    std::cout << "Testing countDigits(0): " << countDigits(0) << std::endl;
    std::cout << "Testing countDigits(-9876): " << countDigits(-9876) << std::endl;
    std::cout << "Testing countDigits(7): " << countDigits(7) << std::endl;
    std::cout << "Testing countDigits(-1): " << countDigits(-1) << std::endl;
    std::cout << "Testing countDigits(" << std::numeric_limits<int>::max() << "): " << countDigits(std::numeric_limits<int>::max()) << std::endl;
    std::cout << "Testing countDigits(" << std::numeric_limits<int>::min() << "): " << countDigits(std::numeric_limits<int>::min()) << std::endl;
    return 0;
}