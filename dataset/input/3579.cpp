#include <iostream>
#include <algorithm> // Required for std::max

int main() {
    int num1, num2, num3;

    std::cout << "Enter three integer numbers: ";
    std::cin >> num1 >> num2 >> num3;

    // It's good practice to check if input was successful,
    // but for the 'Correct Version' focusing on core logic.
    if (std::cin.fail()) {
        std::cerr << "Invalid input. Please enter three integers." << std::endl;
        return 1; // Indicate an error
    }

    // Determine the largest using std::max for conciseness and readability
    int largest = std::max({num1, num2, num3}); // Using initializer list for C++11 and above

    std::cout << "The largest number is: " << largest << std::endl;

    return 0;
}