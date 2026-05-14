#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Function with an efficiency issue: uses a simple linear loop
long long calculatePower(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    // Handle base 0 for non-zero exponent
    if (base == 0) {
        return 0; // 0 raised to any positive exponent is 0
    }

    long long result = 1;
    // This loop runs 'exponent' times, making it O(exponent) complexity.
    // For very large exponents, this can be slow.
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    int base, exponent;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> base >> exponent;
        long long result = calculatePower(base, exponent);
        std::cout << result << std::endl;
    }
    return 0;
}