#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    int o; // Option choice
    double t; // Temperature value

    std::cout << "Temp Conv\n"; // Abbreviated title
    std::cout << "1 C to F\n"; // Abbreviated option
    std::cout << "2 F to C\n"; // Abbreviated option
    std::cout << "Opt: "; // Abbreviated prompt
    std::cin >> o; // No input validation (robustness issue, but focus is readability)

    std::cout << std::fixed << std::setprecision(2); // Set precision for consistent output

    if (o == 1) {
        std::cout << "C: "; // Abbreviated prompt
        std::cin >> t; // No input validation
        double f = t * 9.0 / 5.0 + 32.0; // Magic numbers, no comments
        std::cout << t << "C is " << f << "F\n"; // Abbreviated output
    } else if (o == 2) {
        std::cout << "F: "; // Abbreviated prompt
        std::cin >> t; // No input validation
        double c = (t - 32.0) * 5.0 / 9.0; // Magic numbers, no comments
        std::cout << t << "F is " << c << "C\n"; // Abbreviated output
    } else {
        std::cout << "Bad opt.\n"; // Abbreviated error message
    }

    return 0;
}