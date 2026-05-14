#include <iostream> 
// This program generates a multiplication table.
int main() { 
    int n; // Variable to hold the input number.
    std::cout << "Enter a number to generate its multiplication table: "; // Display prompt.
    std::cin >> n; // Get number from user.
    // Loop to print the table.
    int j = 1; // Initialize loop counter.
    while (j < 11) { // Loop condition.
        int res = n * j; // Calculate product.
        std::cout << n << " x " << j << " = " << res << std::endl; // Print current line.
        j = j + 1; // Increment counter.
    }
    return 0; // Exit successfully.
}