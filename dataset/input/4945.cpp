#include <iostream>

int user_main() {
    std::cout << "Enter a positive integer limit: ";
    int limit = 0; // Initialize to 0 for predictable behavior on failed input
    // Robustness Issue: No validation for cin.fail() or for positive limit.
    // If non-numeric input, cin fails, limit remains 0.
    // If negative or zero input, the loop proceeds without warning.
    std::cin >> limit; 

    long long sum = 0;
    for (int i = 1; i <= limit; ++i) { 
        if (i % 2 == 0) {
            sum += i;
        }
    }

    std::cout << "The sum of even numbers up to " << limit << " is: " << sum << std::endl;

    return 0;
}