#include <iostream>

int main() {
    int number; // 'number' is uninitialized.
    std::cout << "Enter an integer: ";
    std::cin >> number; // If input fails (e.g., non-integer), 'number' remains indeterminate.

    // The program proceeds without checking if input was successful.
    // If 'std::cin >> number;' failed, 'number' holds an indeterminate value,
    // leading to undefined behavior when printed or used in calculations.
    // The stream also remains in a failed state.
    for (int i = 1; i <= 10; ++i) {
        std::cout << number << " x " << i << " = " << (number * i) << "\n";
    }

    return 0;
}