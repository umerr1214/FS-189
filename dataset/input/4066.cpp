#include <iostream> // Standard library for input/output

// Function to reverse an integer using a while loop
// This function itself is intended to be logically correct.
int reverse_integer_logic(int n) {
    int reversed_n = 0, remainder;
    bool is_negative = false;

    if (n == 0) return 0; // Handle 0 explicitly

    if (n < 0) {
        is_negative = true;
        n = -n; // Work with the absolute value for reversal
    }

    while (n != 0) {
        remainder = n % 10;
        reversed_n = reversed_n * 10 + remainder;
        n /= 10;
    }

    if (is_negative) {
        reversed_n = -reversed_n; // Reapply the negative sign if original was negative
    }
    return reversed_n;
}

int main() {
    int input_num;
    std::cout << "Enter an integer: ";
    std::cin >> input_num // Missing semicolon here, causing a syntax error

    int result = reverse_integer_logic(input_num);
    std::cout << "Reversed number: " << result << std::endl;
    return 0;
}