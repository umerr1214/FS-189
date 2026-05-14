#include <iostream>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    // Logical Error: Only checks divisibility by 2 and 3 for numbers greater than 3.
    // This incorrectly classifies many composite numbers (e.g., 25, 35, 49) as prime.
    if (n % 2 == 0 || n % 3 == 0) return false;
    return true; // Incorrectly assumes prime if not divisible by 2 or 3
}

int main() {
    for (int i = 1; i <= 100; ++i) {
        if (is_prime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}