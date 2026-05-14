#include <iostream>
#include <vector>
#include <string>
#include <sstream> // Required for driver

// Function definition with Readability / Efficiency Issue
int calculatePower(int base, int exponent) {
    // Problem states exponent is non-negative.
    if (exponent == 0) {
        return 1; // Special case for exponent 0.
    }
    
    // This approach is slightly less efficient/readable than initializing
    // result to 1 and looping 'exponent' times.
    // It handles exponent 0 separately and then loops 'exponent - 1' times.
    // Variable names could also be more descriptive.
    int res = base; // Start with base, as exponent is at least 1 here
    int count = 1;  // We've already accounted for one 'base' factor

    while (count < exponent) { // Loop until 'count' reaches 'exponent'
        res *= base;
        count++;
    }
    return res;
}

int main() {
    std::vector<std::string> inputs = {
        "2 3", "5 0", "1 10", "10 1", "0 5", "0 0", "-2 3", "-3 2", "3 4", "2 10",
        "3 20" 
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