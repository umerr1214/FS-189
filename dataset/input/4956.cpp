#include <iostream>

int main() {
    int sum = 0;
    signed char num; // Semantic Error: Using 'signed char' for integer input.
                     // 'signed char' has a limited range (typically -128 to 127).
                     // Entering numbers outside this range will cause integer overflow/wrap-around.

    do {
        std::cout << "Enter an integer: ";
        std::cin >> num; // If user enters 150, 'num' will wrap around to -106 (150 - 256).
                         // If user enters 200, 'num' will wrap around to -56 (200 - 256).

        if (num >= 0) { // This condition will be evaluated based on the potentially wrapped value.
                        // For example, if 150 is entered, 'num' becomes -106, so -106 >= 0 is false.
                        // The number 150 (now -106) will not be added to the sum.
            sum += num;
        }
    } while (num >= 0); // The loop termination condition also relies on the wrapped value.
                        // If a large positive number is entered, it might wrap to a negative value,
                        // causing premature loop termination.

    std::cout << "Sum of positive numbers: " << sum << std::endl;

    return 0;
}