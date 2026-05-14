#include <iostream> // For standard input/output operations

// Function containing the core logic to be tested
void solve() {
    long long a = 0; // Cryptic variable name for sum
    int b;           // Cryptic variable name for the number read

    std::cout << "Enter positive integers (0 to stop):\n"; // Initial instruction

    // Using a do-while loop with an unnecessary check inside, reducing efficiency and readability
    do {
        std::cout << "Enter number: "; // Prompt for input
        std::cin >> b;                // Read the number

        // Redundant check: if 'b' is 0, it will be handled by the while condition
        // and should not be added to 'a'. This 'if' is technically correct but unnecessary.
        if (b != 0) {
            a += b; // Add 'b' to 'a'
        }
    } while (b != 0); // Loop until 'b' is 0

    std::cout << "Sum: " << a << std::endl; // Display the final sum
}

int main() {
    solve();
    return 0;
}