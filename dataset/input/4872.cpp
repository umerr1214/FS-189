#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    char choice; // Using char for choice
    double temperature;
    double converted_temperature;

    std::cout << "Temperature Conversion Menu:\n";
    std::cout << "1. Celsius to Fahrenheit\n";
    std::cout << "2. Fahrenheit to Celsius\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    std::cout << "Enter the temperature: ";
    std::cin >> temperature;

    std::cout << std::fixed << std::setprecision(2);

    // Semantic Error: Comparing char '1' (ASCII 49) with int 1, which will always be false.
    // The user intends to compare the character '1' or '2' with the input.
    if (choice == 1) { // This condition will never be true for input '1'
        // Celsius to Fahrenheit: F = C * 9/5 + 32
        converted_temperature = temperature * 9.0 / 5.0 + 32.0;
        std::cout << temperature << " Celsius is " << converted_temperature << " Fahrenheit.\n";
    } else if (choice == 2) { // This condition will never be true for input '2'
        // Fahrenheit to Celsius: C = (F - 32) * 5/9
        converted_temperature = (temperature - 32.0) * 5.0 / 9.0;
        std::cout << temperature << " Fahrenheit is " << converted_temperature << " Celsius.\n";
    } else {
        std::cout << "Invalid choice. Please enter 1 or 2.\n";
    }

    return 0;
}