#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int num1, num2, num3;

    std::cout << "Enter three distinct integers: ";

    // Robust input handling loop: Prompts user until valid integers are entered.
    while (!(std::cin >> num1 >> num2 >> num3)) {
        std::cout << "Invalid input. Please enter three distinct integers: ";
        std::cin.clear(); // Clear the error flags (e.g., failbit)
        // Discard invalid input from the buffer up to the next newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Identify the largest number using a clear and efficient if-else if-else structure.
    // Using >= handles cases where numbers might not be strictly distinct,
    // ensuring correctness even if the user deviates from the 'distinct' instruction.
    if (num1 >= num2 && num1 >= num3) {
        std::cout << "The largest number is: " << num1 << std::endl;
    } else if (num2 >= num1 && num2 >= num3) {
        std::cout << "The largest number is: " << num2 << std::endl;
    } else { // If num1 is not largest and num2 is not largest, then num3 must be the largest.
        std::cout << "The largest number is: " << num3 << std::endl;
    }

    return 0;
}