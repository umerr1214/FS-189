#include <iostream>
#include <limits> // Required for std::numeric_limits

void solve_question() {
    int N = 0; // Initialize N to 0 for predictable behavior on input failure
    int sum = 0;
    int current_odd = 1;

    std::cout << "Enter a positive integer N: ";
    std::cin >> N; // No input validation for std::cin.fail() or N <= 0.

    // Robustness issue:
    // 1. If input is 'a', std::cin.fail() will be true, N will remain 0.
    //    The program silently proceeds, outputting 0, without warning the user.
    // 2. If N is negative (e.g., -3) or zero, the loop condition (1 <= N) will be false,
    //    sum will be 0. The program outputs 0 without warning that N should be positive,
    //    as per the problem statement.
    while (current_odd <= N) {
        sum += current_odd;
        current_odd += 2;
    }

    std::cout << "The sum of odd numbers from 1 to " << N << " is: " << sum << std::endl;
}

int main() {
    solve_question();
    return 0;
}