#include <iostream>
#include <string> // Required for driver, not for problem logic

// Function containing the core logic
void solve() {
    int b; // Poor variable name for base
    int e; // Poor variable name for exponent
    long long r = 1; // Using long long to prevent overflow, but the method is inefficient for large 'e'

    std::cout << "Enter base (positive integer): ";
    std::cin >> b;
    std::cout << "Enter exponent (positive integer): ";
    std::cin >> e;

    if (b <= 0 || e <= 0) {
        std::cerr << "Error: Both base and exponent must be positive integers." << std::endl;
        return;
    }

    // Efficiency issue: This simple loop is O(e) (linear with exponent).
    // For very large exponents, exponentiation by squaring (O(log e)) is significantly more efficient.
    // Readability issue: Lack of helper function, short and non-descriptive variable names ('b', 'e', 'r').
    for (int i = 0; i < e; ++i) {
        r = r * b;
    }

    std::cout << "Result: " << r << std::endl;
}

int main() {
    solve();
    return 0;
}