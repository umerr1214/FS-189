#include <iostream> // For I/O operations

int main() {
    double c; // Short, non-descriptive variable name
    std::cout << "Enter temp (C): "; // Abbreviated prompt
    std::cin >> c; // No input validation
    double f = c * 9.0 / 5.0 + 32.0; // Calculation on one line, no specific formatting for output
    std::cout << "Temp (F): " << f << std::endl; // Abbreviated prompt, default precision output
    return 0;
}