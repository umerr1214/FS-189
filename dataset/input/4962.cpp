#include <iostream>

bool isPerfect(int num) {
    if (num <= 1) {
        return false;
    }
    // Semantic Error: 'sum_divisors' is declared as 'short'.
    // While this works for small perfect numbers (like 6, 28, 496),
    // a 'short' integer type typically has a maximum value of 32,767.
    // The next perfect number after 496 is 8128, which also fits in 'short'.
    // However, the fifth perfect number is 33,550,336, which would cause an overflow
    // for 'short' and even 'int' on systems where int is 16-bit.
    // This is a semantic error because the chosen data type is insufficient for the problem's
    // general scope, leading to incorrect behavior for larger valid inputs without a compile-time error.
    short sum_divisors = 0; // Should be 'int' or 'long long' for general perfect numbers
    for (int i = 1; i < num; ++i) {
        if (num % i == 0) {
            sum_divisors += i;
        }
    }
    return sum_divisors == num;
}

int main() {
    // Driver code for testing
    std::cout << "Is 6 perfect? " << (isPerfect(6) ? "true" : "false") << std::endl;      // Expected: true, Actual: true
    std::cout << "Is 28 perfect? " << (isPerfect(28) ? "true" : "false") << std::endl;    // Expected: true, Actual: true
    std::cout << "Is 1 perfect? " << (isPerfect(1) ? "true" : "false") << std::endl;      // Expected: false, Actual: false
    std::cout << "Is 7 perfect? " << (isPerfect(7) ? "true" : "false") << std::endl;      // Expected: false, Actual: false
    std::cout << "Is 0 perfect? " << (isPerfect(0) ? "true" : "false") << std::endl;      // Expected: false, Actual: false
    std::cout << "Is -6 perfect? " << (isPerfect(-6) ? "true" : "false") << std::endl;    // Expected: false, Actual: false
    std::cout << "Is 12 perfect? " << (isPerfect(12) ? "true" : "false") << std::endl;    // Expected: false, Actual: false
    std::cout << "Is 496 perfect? " << (isPerfect(496) ? "true" : "false") << std::endl; // Expected: true, Actual: true
    // Note: For larger perfect numbers like 33550336, this code would produce incorrect results due to 'short' overflow.
    return 0;
}