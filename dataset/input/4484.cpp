#include <iostream>

// No 'using namespace std;' to make code slightly more verbose
// No comments for readability
// Poor variable names

int main() {
    double p, r, t; // Poor variable names: p for principal, r for rate, t for time
    double si;      // Poor variable name: si for simple interest

    std::cout << "Enter principal amount: ";
    std::cin >> p;

    std::cout << "Enter annual rate of interest (%): ";
    std::cin >> r;

    std::cout << "Enter time period (years): ";
    std::cin >> t;

    // Calculation is correct, but variable names reduce readability
    si = (p * r * t) / 100.0;

    std::cout << "Simple Interest: " << si << std::endl;

    return 0;
}