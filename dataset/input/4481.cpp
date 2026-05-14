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

    // Logical Error: The rate is divided by 10 instead of 100.
    // This will result in an interest amount 10 times higher than expected.
    double simpleInterest = (principal * rate * time) / 10.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Simple Interest: " << simpleInterest << std::endl;

    return 0;
}