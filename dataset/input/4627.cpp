#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int n;
    std::cout << "Enter a positive integer n: ";
    std::cin >> n;

    // Robustness Issue: Basic check for input failure, but no re-prompt or
    // clearing of remaining invalid input on the line.
    // Also, no validation that 'n' is actually positive as required by the question.
    // If n is 0 or negative, the sum will be 0, which is logically incorrect
    // for "sum of natural numbers from 1 to n" when n is not positive.
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        // std::cin.clear(); // Missing: Clear error flags
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Missing: Discard bad input
        return 1; // Exit on invalid input
    }

    long long sum = 0; // Use long long for sum to prevent overflow for large n
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    std::cout << "The sum of natural numbers from 1 to " << n << " is: " << sum << std::endl;

    return 0;
}