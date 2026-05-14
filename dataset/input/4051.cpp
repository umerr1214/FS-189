#include <iostream>

int main() {
    int num;
    std::cout << "Enter a number to generate its multiplication table: ";
    std::cin >> num; // No input validation; if non-numeric, 'num' might be 0 or garbage.

    // If std::cin fails (e.g., non-numeric input), 'num' will likely be 0
    // after a failed read into an int, and the program will continue
    // to print the multiplication table for 0, which is incorrect behavior
    // for an invalid input.
    for (int i = 1; i <= 10; ++i) {
        std::cout << num << " x " << i << " = " << (num * i) << std::endl;
    }

    return 0;
}