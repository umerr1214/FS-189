#include <iostream> // Required for std::cout, std::cin, std::endl
#include <limits>   // Required for std::numeric_limits

// Function containing the core logic to be tested
void solve() {
    long long sum = 0; // Use long long for sum to prevent potential overflow with large inputs
    int number;        // Variable to store each integer input

    std::cout << "Enter positive integers (0 to stop):\n";

    // Use a priming read before the loop to handle the first input
    std::cout << "Enter number: ";
    std::cin >> number;

    // Loop continues as long as the entered number is not zero
    while (number != 0) {
        // Robustness: Handle non-integer input gracefully
        if (std::cin.fail()) {
            std::cout << "Invalid input: Please enter an integer.\n";
            std::cin.clear(); // Clear the error flags on std::cin
            // Discard invalid input from the buffer up to the next newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Prompt for input again without adding anything to sum
            std::cout << "Enter number: ";
            std::cin >> number;
            continue; // Skip the rest of this iteration and re-evaluate loop condition
        }

        // Input validation: ensure the number is positive as requested by the problem
        if (number < 0) {
            std::cout << "Invalid input: Please enter a positive integer. (Negative numbers will be ignored.)\n";
            // Read next number without adding the current invalid one
            std::cout << "Enter number: ";
            std::cin >> number;
            continue; // Skip the rest of this iteration and re-evaluate loop condition
        }

        sum += number; // Add the valid positive number to the sum

        // Prompt for the next number
        std::cout << "Enter number: ";
        std::cin >> number;
    }

    // Display the final sum
    std::cout << "Sum: " << sum << std::endl;
}

int main() {
    solve();
    return 0;
}