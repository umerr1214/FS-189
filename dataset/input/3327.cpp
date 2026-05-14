#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    long long totalSum = 0;    // Clear and descriptive variable name, uses long long to prevent overflow
    int currentNumber;         // Clear and descriptive variable name

    while (true) {
        std::cin >> currentNumber;

        // Robustness: Handle non-integer input gracefully
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flags on std::cin
            // Discard the rest of the invalid line to prevent an infinite loop
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Continue to the next iteration to ask for valid input again, effectively skipping invalid input
            continue; 
        }

        if (currentNumber == 0) {
            break; // Exit loop when 0 is entered, clear and direct control flow
        }
        
        totalSum += currentNumber; // Accumulate sum
    }

    std::cout << totalSum << std::endl; // Print the final sum
    return 0;
}