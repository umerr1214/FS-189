#include <iostream> // Required for std::cout, std::cin, std::endl

// Function containing the core logic to be tested
void solve() {
    int num;
    int sum = 0; // Using 'int' for sum, which can lead to overflow for large inputs.
                 // This is a potential robustness issue.

    std::cout << "Enter positive integers (0 to stop):\n";

    // Initial prompt for the first number
    std::cout << "Enter number: ";
    std::cin >> num; // This line is vulnerable to non-integer input.

    while (num != 0) {
        // Robustness Issue 1: No handling for non-integer input.
        // If std::cin fails (e.g., user enters "abc"), num will not be updated,
        // std::cin will be in a fail state, and the loop will likely become infinite
        // if num was not 0, or behave unpredictably.

        // Robustness Issue 2: Accepts negative numbers, violating "positive integers" constraint.
        if (num < 0) {
            std::cout << "Warning: Negative number entered. Adding to sum.\n";
        }
        
        sum += num; // Robustness Issue 3: 'sum' is 'int', vulnerable to overflow.

        // Prompt for the next number
        std::cout << "Enter number: ";
        std::cin >> num;
    }

    // Display the final sum
    std::cout << "Sum: " << sum << std::endl;
}

int main() {
    solve();
    return 0;
}