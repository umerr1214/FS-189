#include <iostream>

int main() {
    int sum = 0; // Robustness Issue: Potential integer overflow for large sums
    int num;

    while (true) {
        std::cin >> num;

        // Robustness Issue: Lack of input validation and error handling for non-integer input.
        // If std::cin fails (e.g., non-integer input), num might retain its previous value,
        // and std::cin's failbit will be set. Subsequent reads will also fail,
        // potentially leading to an infinite loop if num is not 0 and the error state is not cleared.
        // For the purpose of demonstrating the issue, we intentionally omit error handling here.

        if (num == 0) {
            break; // Exit loop if 0 is entered
        }
        
        sum += num; // Accumulate sum
    }

    std::cout << sum << std::endl; // Print the final sum
    return 0;
}