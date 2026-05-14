#include <iostream>

int user_main() {
    int num;
    do {
        std::cout << "Enter a positive integer: ";
        // Robustness Issue: This code does not handle non-integer input gracefully.
        // If the user enters non-numeric input (e.g., "abc"), std::cin will enter a fail state.
        // The fail bit will not be cleared, and std::cin will not attempt to read again.
        // 'num' will retain its previous value (or be uninitialized if first input).
        // This leads to an infinite loop, repeatedly printing the prompt and the "Invalid input" message.
        std::cin >> num;
        if (num <= 0) {
            std::cout << "Invalid input. Please enter a positive integer.\n";
        }
    } while (num <= 0);
    std::cout << "You entered: " << num << ". This is a valid positive integer.\n";
    return 0;
}