#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    int choice;
    double temperature;

    std::cout << "Temperature Conversion Program\n";
    std::cout << "------------------------------\n";
    std::cout << "1. Celsius to Fahrenheit\n";
    std::cout << "2. Fahrenheit to Celsius\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice; // Robustness issue: no check for non-numeric input

    std::cout << std::fixed << std::setprecision(2); // Set precision for consistent output

    if (choice == 1) {
        std::cout << "Enter temperature in Celsius: ";
        std::cin >> temperature; // Robustness issue: no check for non-numeric input
        // If std::cin fails (e.g., non-numeric input), 'temperature' will likely be 0.0
        // and std::cin's failbit will be set. Program proceeds with potentially invalid data.
        double fahrenheit = temperature * 9.0/5.0 + 32.0;
        std::cout << temperature << " Celsius is " << fahrenheit << " Fahrenheit.\n";
    } else if (choice == 2) {
        std::cout << "Enter temperature in Fahrenheit: ";
        std::cin >> temperature; // Robustness issue: no check for non-numeric input
        // If std::cin fails, 'temperature' will likely be 0.0.
        double celsius = (temperature - 32.0) * 5.0/9.0;
        std::cout << temperature << " Fahrenheit is " << celsius << " Celsius.\n";
    } else {
        std::cout << "Invalid choice. Please enter 1 or 2.\n";
        // This handles invalid *value*, but if choice was non-numeric,
        // std::cin will be in a fail state, and subsequent reads might fail or skip.
    }

    return 0;
}