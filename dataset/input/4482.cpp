#include <iostream>
#include <iomanip>

int main() {
    double principal;
    double rate;
    double time;

    std::cout << "Enter principal amount: ";
    std::cin >> principal;

    std::cout << "Enter annual interest rate (in percent): ";
    std::cin >> rate;

    std::cout << "Enter time period (in years): ";
    std::cin >> time;

    // Semantic Error: The rate is first converted to a decimal (rate / 100.0),
    // and then the entire product is divided by 100.0 again.
    // This effectively divides the rate by 100 twice, leading to a much smaller interest.
    double simpleInterest = (principal * (rate / 100.0) * time) / 100.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Simple Interest: " << simpleInterest << std::endl;

    return 0;
}