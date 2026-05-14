#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int num;
    std::cout << "Enter an integer: ";

    // Robustness Issue: This loop attempts to read an integer.
    // If a non-integer is entered, std::cin will enter a fail state.
    // The loop condition `!(std::cin >> num)` will remain true,
    // and without `std::cin.clear()` and `std::cin.ignore()`,
    // the stream error flags are not cleared, and the bad input remains in the buffer.
    // This results in an infinite loop, continuously printing the error message
    // without ever allowing new input or clearing the bad input.
    while (!(std::cin >> num)) {
        std::cout << "Invalid input. Please enter an integer: ";
        // Missing: std::cin.clear();
        // Missing: std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (num > 0) {
        std::cout << "The number is positive." << std::endl;
    } else if (num < 0) {
        std::cout << "The number is negative." << std::endl;
    } else { // num must be 0
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}