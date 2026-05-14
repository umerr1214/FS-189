#include <iostream> // For input/output operations.

int main() { // Entry point of the program.
    int val; // A variable to store the user's input.
    std::cout << "Enter a number: "; // Prompt for the user.
    std::cin >> val; // Read the number.

    int count_var = 1; // Initialize a counter.
    // Use a do-while loop, which might be less intuitive than a for loop for this pattern.
    do {
        // Print the multiplication expression and result without clear spacing.
        std::cout << val << "*" << count_var << "=" << val * count_var << "\n";
        count_var++; // Increment the counter.
    } while (count_var <= 10); // Loop condition.

    return 0; // Indicate successful execution.
}