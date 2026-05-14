#include <iostream>

// Function to convert Celsius to Fahrenheit
double convertCelsiusToFahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

int user_main() {
    double celsius = 0.0; // Initialize to avoid potential UB if cin fails
    double fahrenheit;

    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius; // No input validation here

    // Robustness Issue:
    // If non-numeric input is given (e.g., "abc"), std::cin will fail.
    // The 'celsius' variable will retain its initialized value (0.0).
    // The program will then proceed to calculate Fahrenheit for 0.0 Celsius,
    // which is 32.0 Fahrenheit. This provides a misleading, incorrect result
    // for invalid input, rather than prompting for re-entry or exiting gracefully.
    // The program does not crash, but it behaves incorrectly without user awareness.

    fahrenheit = convertCelsiusToFahrenheit(celsius);

    std::cout << "Temperature in Fahrenheit: " << fahrenheit << std::endl;

    return 0;
}