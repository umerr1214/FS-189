#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    int n;
    int sum = 0; // Semantic error: 'sum' is an int, which can overflow for large 'n'
    std::cout << "Enter a positive integer n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    // Check for potential overflow before calculation for very large n
    // This check itself is part of a robust solution, but the error is in the type of 'sum'
    if (n > 0 && (long long)n * (n + 1) / 2 > std::numeric_limits<int>::max()) {
        // This specific check would prevent the calculation, but for the error demonstration,
        // we let it proceed to show the overflow.
        // For the purpose of this semantic error example, we assume 'n' is large enough to cause overflow.
    }

    for (int i = 1; i <= n; ++i) {
        sum += i; // This operation can cause signed integer overflow, which is undefined behavior.
    }

    std::cout << "The sum of integers from 1 to " << n << " is: " << sum << std::endl;

    return 0;
}