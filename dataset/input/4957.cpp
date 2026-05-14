#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int num;
    long long sum = 0; // Using long long to prevent integer overflow for the sum itself

    std::cout << "Enter integers. Enter a negative number to stop." << std::endl;

    do {
        std::cout << "Enter integer: ";
        std::cin >> num;

        // Robustness Issue:
        // This program does not check for std::cin.fail() after reading input.
        // If the user enters non-integer input (e.g., "abc"), std::cin will enter a fail state,
        // 'num' will retain its previous value (or be uninitialized if it's the first input),
        // the fail bit on std::cin will not be cleared, and the input buffer will not be cleared.
        // This typically leads to an infinite loop, as std::cin will continuously fail
        // to read, and the loop condition 'num >= 0' might remain true indefinitely,
        // without consuming new input from the user.
        // The program will keep printing "Enter integer: " without progressing.

        if (num > 0) {
            sum += num;
        }
    } while (num >= 0);

    std::cout << "Sum of positive numbers entered: " << sum << std::endl;

    return 0;
}