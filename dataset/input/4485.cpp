#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision
#include <limits>  // Required for std::numeric_limits

int main() {
    double principal;
    double rate;
    double time_period;
    double simple_interest;

    std::cout << "Enter principal amount: ";
    std::cin >> principal;

    // Input validation for principal
    if (std::cin.fail() || principal < 0) {
        std::cerr << "Error: Invalid principal amount. Please enter a non-negative number." << std::endl;
        return 1; // Indicate an error
    }

    std::cout << "Enter annual rate of interest (%): ";
    std::cin >> rate;

    // Input validation for rate
    if (std::cin.fail() || rate < 0) {
        std::cerr << "Error: Invalid rate of interest. Please enter a non-negative number." << std::endl;
        return 1;
    }

    std::cout << "Enter time period (years): ";
    std::cin >> time_period;

    // Input validation for time period
    if (std::cin.fail() || time_period < 0) {
        std::cerr << "Error: Invalid time period. Please enter a non-negative number." << std::endl;
        return 1;
    }

    // Calculate simple interest
    simple_interest = (principal * rate * time_period) / 100.0;

    // Display the calculated interest with two decimal places
    std::cout << "Simple Interest: " << std::fixed << std::setprecision(2) << simple_interest << std::endl;

    return 0;
}