#include <iostream>

int main() {
    // Dynamically allocate memory for an array of 5 integers
    int* numbers = new int[5];
    const int ARRAY_SIZE = 5;

    std::cout << "Enter " << ARRAY_SIZE << " integer values:\n";

    // Prompt user to enter values
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Enter value " << i + 1 << ": ";
        std::cin >> numbers[i]; // Robustness issue: No input validation.
                                // If non-integer input is given, cin.failbit will be set,
                                // leading to an infinite loop or incorrect behavior.
    }

    // Print the values
    std::cout << "You entered:\n";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Value " << i + 1 << ": " << numbers[i] << "\n";
    }

    // Deallocate the memory
    delete[] numbers;
    numbers = nullptr; // Good practice to set pointer to nullptr after deletion

    return 0;
}