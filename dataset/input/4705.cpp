#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    double celsius;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius; // No input validation; vulnerable to non-numeric input

    // If std::cin fails (e.g., due to non-numeric input), 'celsius' might
    // retain its default-initialized value (which is 0.0 for global/static,
    // or an indeterminate value for local variables without explicit initialization).
    // For this demonstration, we'll assume it proceeds with 0.0 or a similar
    // default, leading to an incorrect but non-crashing result.
    // The stream will also be in a fail state, affecting subsequent reads if any.

    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Temperature in Fahrenheit: " << fahrenheit << std::endl;

    return 0;
}