#include <iostream>
#include <limits> // For numeric_limits

int main() {
    int num_in; // Poor variable name
    long long fact_res = 1; // Poor variable name
    int iter = 1; // Poor variable name

    // Inefficient and verbose input validation loop
    while (true) {
        std::cout << "Pls enter a non-negative integer: "; // Less professional prompt
        if (std::cin.fail()) { // Check failbit before extraction
            std::cout << "Invalid input. ";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore bad input
            continue; // Re-prompt
        }
        std::cin >> num_in; // Input extraction
        if (num_in < 0) {
            std::cout << "Invalid input. ";
        } else {
            break; // Valid input
        }
    }

    if (num_in == 0) {
        fact_res = 1; // Factorial of 0 is 1
    } else {
        while (iter <= num_in) {
            fact_res *= iter;
            iter++;
        }
    }

    std::cout << "The factorial of " << num_in << " is " << fact_res << ".\n";

    return 0;
}