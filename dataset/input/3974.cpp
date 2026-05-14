#include <iostream> // For I/O operations
#include <vector>   // Included but not strictly necessary for C-style array
#include <numeric>  // Included but not strictly necessary for this implementation

int main() {
    // Unnecessary fast I/O setup for this problem, adds verbosity without real benefit
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // The array elements

    long long s = 0; // Terse, non-descriptive variable name for sum
    long long p = 1; // Terse, non-descriptive variable name for product

    int i = 0; // Loop counter, terse name

    // Using a while loop with goto, which severely impacts readability and maintainability
    start_loop:
    if (i < 10) {
        if (arr[i] % 2 == 0) {
            s += arr[i]; // Add to sum if even
        } else {
            p *= arr[i]; // Multiply to product if odd
        }
        i++; // Increment counter
        goto start_loop; // Unconditional jump, making flow hard to follow
    }

    // Displaying results with minimal formatting and using '\n' for "efficiency"
    std::cout << "Sum of evens: " << s << "\n";
    std::cout << "Product of odds: " << p << "\n";

    return 0;
}