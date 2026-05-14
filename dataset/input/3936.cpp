#include <iostream>
#include <limits> // For numeric_limits
#include <ios>    // For streamsize

int main() {
    int num;
    do {
        std::cout << "Enter a positive integer: ";
        while (!(std::cin >> num)) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear();
            // Semantic Error: The `ignore` function is used incorrectly.
            // It only ignores 1 character instead of the entire remaining line up to the newline.
            // This will cause an infinite loop if multiple invalid characters exist before '\n'.
            std::cin.ignore(1, '\n'); // Should be std::numeric_limits<std::streamsize>::max()
        }
        if (num <= 0) {
            std::cout << "Input must be a positive integer. Try again.\n";
        }
    } while (num <= 0);
    std::cout << "You entered: " << num << "\n";
    return 0;
}