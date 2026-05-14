#include <iostream>

void solve() {
    int N;
    long long sum = 0;
    int i = 1;

    std::cout << "Enter a positive integer N: ";
    std::cin >> N;

    // Input validation for N being a positive integer
    if (std::cin.fail() || N <= 0) {
        std::cerr << "Error: N must be a positive integer.\n";
        return; // Exit if input is invalid
    }

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