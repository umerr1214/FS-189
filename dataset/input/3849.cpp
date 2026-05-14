#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int num;
    bool isValid = false;

    do {
        std::cout << "Enter an integer between 1 and 10 (inclusive): ";
        std::cin >> num;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear(); // Clear the error flag
            // Ignore remaining characters in the input buffer up to newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (num >= 1 && num <= 10) {
            isValid = true;
        } else {
            std::cout << "Input out of range. Please enter a number between 1 and 10.\n";
            // No need to clear/ignore here, as cin state is good for integer input,
            // even if out of range. The next `cin >> num` will work correctly.
        }
    } while (!isValid);

    std::cout << "You entered: " << num << "\n";
    return 0;
}