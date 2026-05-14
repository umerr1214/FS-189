#include <iostream>

// Core logic for 4777: Robustness Issue (lack of non-numeric input handling)
void solve_4777() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N; // No input validation for non-numeric input or N > 0

    // If std::cin fails (e.g., non-numeric input), N's value might be 0 or indeterminate.
    // The failbit is set, and further input operations might also fail without clearing.
    // The program proceeds with this potentially invalid N.
    // If N is 0 or negative, the loop correctly results in a sum of 0 for "between 1 and N".
    // The primary robustness issue is the lack of handling for failed std::cin.

    int sum = 0;
    for (int i = 1; i <= N; i += 2) {
        sum += i;
    }

    std::cout << "The sum of odd numbers between 1 and " << N << " is: " << sum << std::endl;
}

int main() {
    solve_4777();
    return 0;
}