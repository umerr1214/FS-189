#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Function with a robustness issue: potential integer overflow for large results
int calculatePower(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        // This simple multiplication can easily overflow if 'result' or 'base' are large
        // and the intermediate product exceeds INT_MAX.
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
        // The driver captures the int result as a long long to display it,
        // even if the int result has overflowed.
        long long result = calculatePower(base, exponent); 
        std::cout << result << std::endl;
    }
    return 0;
}