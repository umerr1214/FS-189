#include <iostream>

// Function to encapsulate the core logic for testing
void run_multiplication_table_logic() {
    int num_val; // Less descriptive variable name for the user's number
    std::cout << "Enter the number you want to multiply: "; // Slightly verbose prompt
    std::cin >> num_val;

    // Readability/Efficiency Issue:
    // Using std::endl in a loop: std::endl flushes the output buffer on each iteration,
    // which can be less efficient than using '\n' (newline character) especially in tight loops.
    // Variable names could be more descriptive for improved readability.
    for (int idx = 1; idx <= 10; idx++) { // 'idx' is acceptable, but 'factor' might be clearer
        int prod_val = num_val * idx; // 'prod_val' is an unnecessary temporary variable; calculation could be done directly in output.
        std::cout << num_val << " x " << idx << " = " << prod_val << std::endl; // Efficiency issue: std::endl
    }
}

int main() {
    run_multiplication_table_logic();
    return 0;
}