#include <iostream>
#include <limits> // Required for std::numeric_limits

void solve_question() {
    int N;
    int sum_of_odds = 0;
    int current_odd_number = 1;

    std::cout << "Enter a positive integer N: ";
    std::cin >> N;

    // Input validation for positive integer and correct input type
    if (std::cin.fail() || N <= 0) {
        std::cerr << "Invalid input. Please enter a positive integer." << std::endl;
        // Clear error flags and ignore remaining input for robustness in interactive use
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return; // Exit function on invalid input
    }

    // Efficiently sums only odd numbers using a while loop
    // Iterates by incrementing by 2, directly targeting odd numbers.
    while (current_odd_number <= N) {
        sum_of_odds += current_odd_number;
        current_odd_number += 2; // Increment by 2 to get the next odd number
    }

    std::cout << "The sum of odd numbers from 1 to " << N << " is: " << sum_of_odds << std::endl;
}

int main() {
    solve_question();
    return 0;
}