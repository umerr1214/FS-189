#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    // Logical Error: The loop for divisors starts from 3.
    // This implementation fails to explicitly check for divisibility by 2.
    // Consequently, even numbers greater than 2 (e.g., 4, 8, 10)
    // will be incorrectly identified as prime unless they are also divisible by an odd factor (e.g., 6 is divisible by 3).
    for (int i = 3; i * i <= n; ++i) { 
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << std::boolalpha; // To print true/false instead of 1/0
    std::cout << "Is 7 prime? " << isPrime(7) << std::endl;      // Expected: true, Actual: true
    std::cout << "Is 4 prime? " << isPrime(4) << std::endl;      // Expected: false, Actual: true (BUG)
    std::cout << "Is 2 prime? " << isPrime(2) << std::endl;      // Expected: true, Actual: true
    std::cout << "Is 1 prime? " << isPrime(1) << std::endl;      // Expected: false, Actual: false
    std::cout << "Is 0 prime? " << isPrime(0) << std::endl;      // Expected: false, Actual: false
    std::cout << "Is 11 prime? " << isPrime(11) << std::endl;    // Expected: true, Actual: true
    std::cout << "Is 6 prime? " << isPrime(6) << std::endl;      // Expected: false, Actual: false (6%3==0)
    std::cout << "Is 8 prime? " << isPrime(8) << std::endl;      // Expected: false, Actual: true (BUG)
    std::cout << "Is 9 prime? " << isPrime(9) << std::endl;      // Expected: false, Actual: false (9%3==0)
    return 0;
}