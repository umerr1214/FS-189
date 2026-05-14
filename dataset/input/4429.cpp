#include <iostream>
// No cmath needed for this specific robustness issue implementation

// This version has robustness issues.
// It incorrectly classifies 0, 1, and negative numbers as prime.
// The loop condition (i*i <= n) will immediately fail for n <= 1 or negative n,
// causing the function to incorrectly return true.
bool isPrimeRobustness(int n) {
    // Missing initial checks for n <= 1.
    // For n=0, n=1, or negative n, the loop condition i*i <= n will be false for i=2,
    // so it will incorrectly return true.
    for (int i = 2; i * i <= n; ++i) { 
        if (n % i == 0) {
            return false;
        }
    }
    return true; // Incorrectly returns true for 0, 1, and negative numbers
}

void solve() {
    int num;
    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    // A robust program would validate num > 0 here.
    // This program will proceed with any integer input, demonstrating the robustness issue.

    if (isPrimeRobustness(num)) {
        std::cout << num << " is a prime number." << std::endl;
    } else {
        std::cout << num << " is not a prime number." << std::endl;
    }
}

int main() {
    solve();
    return 0;
}