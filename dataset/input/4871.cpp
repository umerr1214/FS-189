#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    char choice;
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

    if (choice == '1') {
        // Celsius to Fahrenheit: F = C * 9/5 + 32
        converted_temperature = temperature * 9.0 / 5.0 + 32.0;
        std::cout << temperature << " Celsius is " << converted_temperature << " Fahrenheit.\n";
    } else if (choice == '2') {
        // Fahrenheit to Celsius: C = (F - 32) * 5/9
        // Logical Error: Using '+' instead of '-' for Fahrenheit to Celsius conversion
        converted_temperature = (temperature + 32.0) * 5.0 / 9.0;
        std::cout << temperature << " Fahrenheit is " << converted_temperature << " Celsius.\n";
    } else {
        std::cout << "Invalid choice. Please enter 1 or 2.\n";
    }

    return 0;
}