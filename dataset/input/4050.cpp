#include <iostream>

int main() {
    int user_input_number;
    std::cout << "Enter a number: ";
    std::cin >> user_input_number; // User input is read

    // Semantic error: The program ignores the user's input number
    // and always generates the multiplication table for a fixed number (5).
    int fixed_number = 5; 

    for (int i = 1; i <= 10; ++i) {
        std::cout << fixed_number << " x " << i << " = " << (fixed_number * i) << std::endl;
    }

    return 0;
}