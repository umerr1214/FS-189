#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    double value = 0.0; // Initialize to 0.0 to ensure a predictable (though incorrect) output on bad input
    
    std::cout << "Enter monetary value: ";
    std::cin >> value; // Robustness issue: No check for input stream failure

    // Print the value formatted to two decimal places, prefixed with a dollar sign
    std::cout << std::fixed << std::setprecision(2) << "$" << value << std::endl;

    return 0;
}