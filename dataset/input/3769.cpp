#include <iostream>
#include <vector>
#include <string>
#include <sstream> // Required for driver

// Function definition with a Robustness Issue (integer overflow)
int calculatePower(int base, int exponent) {
    // Problem states exponent is non-negative.
    // For exponent = 0, any base^0 is 1.
    // This implementation works for small numbers but does not
    // handle potential integer overflow for large results.
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        // Multiplication might overflow 'int' without warning or check.
        // For example, 3^20 exceeds INT_MAX.
        result *= base;
    }
    return result;
}

int main() {
    std::vector<std::string> inputs = {
        "2 3", "5 0", "1 10", "10 1", "0 5", "0 0", "-2 3", "-3 2", "3 4", "2 10",
        "3 20" // This input will cause an integer overflow in 'calculatePower'
    };
    
    for (size_t i = 0; i < inputs.size(); ++i) {
        std::stringstream ss(inputs[i]);
        int base, exponent;
        ss >> base >> exponent;

        int result = calculatePower(base, exponent);
        
        std::cout << result << std::endl;
    }
    return 0;
}