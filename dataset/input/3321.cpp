#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    int n;
    std::cout << "Enter a positive integer 'n': ";
    std::cin >> n;

    // Correct Version: Includes robust input validation and uses an efficient iterative approach.
    // Handles non-positive or non-integer input gracefully.
    // Uses long long to prevent overflow for moderately large Fibonacci numbers.
    if (std::cin.fail() || n <= 0) {
        std::cerr << "Error: 'n' must be a positive integer." << std::endl;
        // Clear error flags and ignore remaining input for robustness, though exiting is fine here.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate an error
    }

    if (n == 1) {
        std::cout << "0" << std::endl;
    } else { // n >= 2
        long long a = 0;
        long long b = 1;

        std::cout << a << " " << b; // Print first two terms (F_0 and F_1)

        // Iterate from the third term (index 2) up to n-1
        for (int i = 2; i < n; ++i) {
            long long next = a + b;
            std::cout << " " << next;
            a = b;
            b = next;
        }
        std::cout << std::endl;
    }

    return 0;
}