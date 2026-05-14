#include <iostream>

// Function to reverse an integer using a while loop
// This function contains a logical error in handling negative numbers.
int reverse_integer_logic(int n) {
    int reversed_n = 0, remainder;
    // Logical error: The sign is handled by making n positive,
    // but the original sign is not reapplied to reversed_n at the end.
    // For an input like -123, n becomes 123, reversed_n becomes 321.
    // The program then outputs 321, instead of -321.

    if (n == 0) return 0; // Handle 0 explicitly

    if (n < 0) {
        n = -n; // Make the number positive for reversal
        // The boolean 'is_negative' is not used or set here,
        // so the negative sign will not be reapplied.
    }

    while (n != 0) {
        remainder = n % 10;
        reversed_n = reversed_n * 10 + remainder;
        n /= 10;
    }

    // Missing logic to reapply the negative sign if the original number was negative.
    // For example, an 'if (is_negative) reversed_n = -reversed_n;' is needed here.
    return reversed_n;
}

int main() {
    int input_num;
    std::cout << "Enter an integer: ";
    std::cin >> input_num;

    int result = reverse_integer_logic(input_num);
    std::cout << "Reversed number: " << result << std::endl;
    return 0;
}