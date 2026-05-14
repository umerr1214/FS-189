#include <iostream>
#include <limits> // Required for std::numeric_limits

int user_main() {
    int num;
    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> num;

        if (std::cin.fail()) {
            // Handle non-integer input
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
            num = 0; // Set num to 0 to ensure the loop continues
        } else if (num <= 0) {
            // Handle non-positive integer input
            std::cout << "Input must be a positive integer (greater than 0).\n";
        }
    } while (num <= 0); // Loop continues if num is not positive (or was invalid input)

    std::cout << "You entered: " << num << std::endl;
    return 0;
}

int main() {
    return user_main();
}