#include <iostream>
#include <vector>
#include <string>
#include <sstream> // Required for driver

// Correct Version of the function
int calculatePower(int base, int exponent) {
    // According to problem statement, exponent is non-negative.
    // Initialize result to 1.
    // This handles the base case correctly: any number to the power of 0 is 1.
    // If exponent is 0, the loop will not execute, and 1 will be returned.
    int result = 1;

    // Loop 'exponent' times, multiplying result by base in each iteration.
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
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