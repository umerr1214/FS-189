#include <iostream>

int main() {
    int num;
    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> num;
        if (num <= 0) {
            std::cout << "Invalid input. Please enter a positive integer." << std::endl;
        }
    } while (num > 0); // Logical Error: The loop continues as long as num is positive.
                       // It should terminate when num is positive, and continue when num is not positive (num <= 0).
                       // Correct condition should be: while (num <= 0);
    std::cout << "You entered: " << num << std::endl;
    return 0;
}