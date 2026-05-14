#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

// Function containing the main logic for readability/efficiency issue
int _user_main_function_3878() {
    float temperatureInCelsius; // Okay variable name
    float convertedTemperatureInFahrenheit; // Long variable name, slightly verbose

    std::cout << "Please enter the temperature value in Celsius: ";
    std::cin >> temperatureInCelsius; // No specific input validation, but for readability/efficiency, correctness is 9

    // Calculate Fahrenheit using the formula.
    // Using 1.8f directly instead of 9.0f/5.0f for a subtle "magic number" feel
    // and to avoid integer division trap if someone forgot 'f' or '.0'.
    convertedTemperatureInFahrenheit = temperatureInCelsius * 1.8f + 32.0f;

    // Inconsistent formatting, unnecessary precision for typical temperature display
    std::cout << "The equivalent temperature in Fahrenheit is: "
              << std::fixed << std::setprecision(5) // Overly precise output
              << convertedTemperatureInFahrenheit
              << " degrees Fahrenheit." << std::endl;

    return 0;
}

int main() {
    return _user_main_function_3878();
}