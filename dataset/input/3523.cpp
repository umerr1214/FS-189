#include <iostream>

int main() {
    int number = 0; // Initialize to ensure the loop condition works reliably if cin fails
    do {
        std::cout << "Enter a positive integer: ";
        // Robustness issue: Does not handle non-integer input.
        // If the user enters characters, std::cin will enter a fail state.
        // The 'number' variable will not be updated, the stream's error flag is not cleared,
        // and subsequent reads will also fail, leading to an infinite loop.
        std::cin >> number;
    } while (number <= 0); // Loop condition: continues if number is not positive
    
    std::cout << "You entered: " << number << std::endl;
    
    return 0;
}