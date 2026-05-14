#include <iostream>

void solve() {
    int N;
    long long sum = 0;
    int i = 1;

    std::cout << "Enter a positive integer N: ";
    std::cin >> N;

    // Robustness Issue: No validation for N > 0.
    // If N is 0 or negative, the loop won't execute, and sum will be 0,
    // which is technically "correct" for natural numbers up to a non-positive N,
    // but the problem specifies "positive integer N". A robust solution
    // would explicitly check N > 0 and prompt for valid input or error.
    while (i <= N) {
        sum += i;
        i++;
    }

    std::cout << "The sum of natural numbers up to " << N << " is: " << sum << std::endl;
}

int main() {
    solve();
    return 0;
}