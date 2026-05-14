#include <iostream>

// This version has efficiency issues.
// It checks divisibility up to n/2, which is less efficient than sqrt(n).
// It also checks all numbers (even and odd) up to n/2, instead of optimizing by checking only 2 and then odd numbers.
bool isPrimeInefficient(int n) {
    if (n <= 1) { // Correctly handles 0 and 1
        return false;
    }
    if (n == 2) { // Correctly handles 2
        return true;
    }
    // Efficiency issue: loop goes up to n/2, which is less efficient than sqrt(n).
    // Also, it checks all numbers (even and odd) up to n/2,
    // instead of optimizing by checking only 2 and then odd numbers.
    for (int i = 2; i <= n / 2; ++i) { 
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int num;
    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    // Basic validation to meet "positive integer" requirement, but not fully robust for non-integer input.
    if (std::cin.fail() || num <= 0) {
        std::cout << "Please enter a positive integer greater than 0." << std::endl;
        return;
    }

    if (isPrimeInefficient(num)) {
        std::cout << num << " is a prime number." << std::endl;
    } else {
        std::cout << num << " is not a prime number." << std::endl;
    }
}

int main() {
    solve();
    return 0;
}