#include <iostream>

// Efficiency Issue: This `isPrime` function is inefficient for larger numbers.
// It checks divisibility up to `n/2` instead of `sqrt(n)`, which drastically increases
// the number of operations for large inputs. For example, for n = 1,000,000,
// it checks up to 500,000 iterations, whereas an efficient algorithm would check up to 1,000.
bool isPrime(int n) {
    if (n <= 1) return false; // Correctly handles 0, 1, and negatives
    if (n == 2) return true; // Optimization for 2
    if (n % 2 == 0) return false; // Optimization for even numbers greater than 2

    // Inefficient loop: iterates up to n/2.
    // An efficient algorithm would iterate up to sqrt(n) (or i*i <= n).
    for (int i = 3; i <= n / 2; i += 2) { // Only checks odd divisors
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    std::cin >> num;
    if (isPrime(num)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    return 0;
}