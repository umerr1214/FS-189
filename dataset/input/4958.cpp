#include <iostream>

int main() {
    int v; // Terse variable name for 'value' or 'number'
    int t = 0; // Terse variable name for 'total' or 'sumOfPositives'

    std::cout << "Provide numbers. A negative number will end the process." << std::endl; // Slightly less direct prompt

    do {
        std::cout << "Input an int: "; // Different, less descriptive prompt
        std::cin >> v;

        if (v > 0) {
            t = t + v; // Uses explicit addition rather than the more common and slightly more efficient 't += v;'
        }
        // No comments explaining logic or purpose of variables
    } while (v >= 0); // Condition is functionally correct but uses terse variable 'v'

    std::cout << "Total of positive inputs: " << t << std::endl; // Different output message, uses terse 't'

    return 0;
}