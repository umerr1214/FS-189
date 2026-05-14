#include <iostream>
#include <limits> // Required for std::numeric_limits to use std::numeric_limits<std::streamsize>::max()

// Core logic for 4779: Correct Version
void solve_4779() {
    int N;
    bool isValidInput = false;

    // Input validation loop to ensure N is a positive integer
    while (!isValidInput) {
        std::cout << "Enter a positive integer N: ";
        std::cin >> N;

        if (std::cin.fail()) { // Check for non-numeric input
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear(); // Clear error flags
            // Discard invalid input from the buffer up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (N <= 0) { // Check for non-positive input as per problem statement
            std::cout << "N must be a positive integer. Please try again." << std::endl;
            // Discard any remaining input on the line
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            isValidInput = true; // Input is valid, exit loop
            // Discard any remaining input on the line
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    long long sumOfOddNumbers = 0; // Use long long for sum to prevent potential overflow for very large N
    // Efficiently iterate only through odd numbers
    for (int i = 1; i <= N; i += 2) {
        sumOfOddNumbers += i;
    }

    std::cout << "The sum of odd numbers between 1 and " << N << " is: " << sumOfOddNumbers << std::endl;
}

int main() {
    solve_4779();
    return 0;
}