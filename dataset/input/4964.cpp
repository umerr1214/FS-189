#include <iostream>

// Function to check if a number is perfect
bool isPerfect(int x) {
    // Correctly handles non-positive numbers as perfect numbers are positive.
    if (x <= 0) return false;

    int s = 0; // Poor variable name: 's' for sum
    // Efficiency Issue: The loop iterates up to `x-1`.
    // This is less efficient than iterating up to `x/2` or `sqrt(x)`.
    // For large 'x', this can lead to significant performance degradation.
    // Readability Issue: Variable names 'x' and 's' are not descriptive.
    for (int i = 1; i < x; ++i) { 
        if (x % i == 0) {
            s += i;
        }
    }
    return s == x;
}

int main() {
    std::cout << "isPerfect(6): " << (isPerfect(6) ? "true" : "false") << std::endl;
    std::cout << "isPerfect(28): " << (isPerfect(28) ? "true" : "false") << std::endl;
    std::cout << "isPerfect(12): " << (isPerfect(12) ? "true" : "false") << std::endl;
    std::cout << "isPerfect(1): " << (isPerfect(1) ? "true" : "false") << std::endl;
    std::cout << "isPerfect(0): " << (isPerfect(0) ? "true" : "false") << std::endl;
    std::cout << "isPerfect(-6): " << (isPerfect(-6) ? "true" : "false") << std::endl;
    std::cout << "isPerfect(8128): " << (isPerfect(8128) ? "true" : "false") << std::endl; // A larger perfect number to highlight efficiency

    return 0;
}