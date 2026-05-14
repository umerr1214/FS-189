#include <iostream>

int main() {
    double principal = 0.0;
    double rate = 0.0;
    double time_period = 0.0;
    double simple_interest;

    std::cout << "Enter principal amount: ";
    std::cin >> principal;

    std::cout << "Enter annual rate of interest (%): ";
    std::cin >> rate;

    std::cout << "Enter time period (years): ";
    std::cin >> time_period;

    // Robustness Issue: No input validation.
    // - Does not check if cin operations failed (e.g., non-numeric input).
    //   If input fails, variables retain their initialized 0.0 values, leading to 0 interest.
    // - Does not handle negative principal, rate, or time, leading to potentially
    //   illogical negative interest values without warning.
    simple_interest = (principal * rate * time_period) / 100.0;

    std::cout << "Simple Interest: " << simple_interest << std::endl;

    return 0;
}