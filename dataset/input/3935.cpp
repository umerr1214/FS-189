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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (num <= 0) { // This condition correctly identifies non-positive numbers for the prompt
            std::cout << "Input must be a positive integer. Try again.\n";
        }
    } while (num < 0); // Logical Error: The loop condition should be `num <= 0`.
                       // With `num < 0`, if the user enters 0, the condition is false,
                       // and the loop terminates, accepting 0 as a valid positive integer.
    std::cout << "You entered: " << num << "\n";
    return 0;
}