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

    // Calculate simple interest
    double simpleInterest = (principal * rate * time) / 100.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Simple Interest: " << simpleInterest << std::endl // Syntax Error: Missing semicolon here

    return 0;
}