#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

// Function containing the main logic for robustness issue
int _user_main_function_3877() {
    double celsius = 0.0; // Initialize to 0.0 for predictable behavior on bad input
    double fahrenheit;

    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius; // No input validation here. If non-numeric, celsius remains 0.0

    // Formula: F = C * 9/5 + 32
    // Use 9.0/5.0 to ensure floating-point division
    fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    std::cout << std::fixed << std::setprecision(2)
              << "Temperature in Fahrenheit: " << fahrenheit << std::endl;

    return 0;
}

int main() {
    return _user_main_function_3877();
}