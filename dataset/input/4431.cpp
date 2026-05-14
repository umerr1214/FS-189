#include <iostream>
#include <cmath> // For std::sqrt
#include <limits> // Required for std::numeric_limits

// This is the correct and efficient version.
// It handles edge cases (0, 1, 2, negative numbers) and uses an optimized primality test.
bool isPrimeCorrect(int n) {
    if (n <= 1) { // Numbers less than or equal to 1 are not prime
        return false;
    }
    if (n == 2) { // 2 is the only even prime number
        return true;
    }
    if (n % 2 == 0) { // All other even numbers are not prime
        return false;
    }
    // Check for divisibility from 3 up to sqrt(n), only odd numbers
    // Using i*i <= n instead of i <= sqrt(n) to avoid floating point operations and potential precision issues.
    for (int i = 3; i * i <= n; i += 2) {
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

    // Robust input validation
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        // Clear error flags and ignore remaining input in buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    if (num <= 0) {
        std::cout << "Please enter a positive integer greater than 0." << std::endl;
        return;
    }

    if (isPrimeCorrect(num)) {
        std::cout << num << " is a prime number." << std::endl;
    } else {
        std::cout << num << " is not a prime number." << std::endl;
    }
}

int main() {
    solve();
    return 0;
}