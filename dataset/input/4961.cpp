#include <iostream>

bool isPerfect(int num) {
    if (num <= 1) {
        return false;
    }
    int sum_divisors = 0;
    // Logical Error: The loop condition `i <= num` includes the number itself as a divisor.
    // For a perfect number, the sum of its *proper* divisors (excluding itself) should equal the number.
    // Including `num` in `sum_divisors` will make `sum_divisors` always greater than `num` (for num > 1),
    // causing the function to incorrectly return `false` for all perfect numbers.
    for (int i = 1; i <= num; ++i) 
    {
        if (num % i == 0) {
            sum_divisors += i;
        }
    }
    return sum_divisors == num;
}

int main() {
    // Driver code for testing
    std::cout << "Is 6 perfect? " << (isPerfect(6) ? "true" : "false") << std::endl;      // Expected: true, Actual: false
    std::cout << "Is 28 perfect? " << (isPerfect(28) ? "true" : "false") << std::endl;    // Expected: true, Actual: false
    std::cout << "Is 1 perfect? " << (isPerfect(1) ? "true" : "false") << std::endl;      // Expected: false, Actual: false
    std::cout << "Is 7 perfect? " << (isPerfect(7) ? "true" : "false") << std::endl;      // Expected: false, Actual: false
    std::cout << "Is 0 perfect? " << (isPerfect(0) ? "true" : "false") << std::endl;      // Expected: false, Actual: false
    std::cout << "Is -6 perfect? " << (isPerfect(-6) ? "true" : "false") << std::endl;    // Expected: false, Actual: false
    std::cout << "Is 12 perfect? " << (isPerfect(12) ? "true" : "false") << std::endl;    // Expected: false, Actual: false
    std::cout << "Is 496 perfect? " << (isPerfect(496) ? "true" : "false") << std::endl; // Expected: true, Actual: false
    return 0;
}