#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    // Semantic Error: Reading input as int instead of double
    // This will truncate any decimal values provided by the user.
    int celsius_int; 
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius_int;

    // Cast to double for calculation to avoid further integer arithmetic issues,
    // but the initial truncation of input is the semantic error.
    double celsius = static_cast<double>(celsius_int);

    // The formula is F = C * 9/5 + 32
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Temperature in Fahrenheit: " << fahrenheit << std::endl;

    return 0;
}