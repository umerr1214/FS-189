#include <iostream> // Include header for input/output operations

int main() {
    long long prod = 1; // Initialize product variable
    int val; // Variable to store user input value

    std::cout << "Enter non-zero integers (0 to stop):" << std::endl;

    // Loop to continuously get input from the user
    while (true) {
        std::cin >> val; // Read the input value

        if (val == 0) { // Check if the sentinel value (0) was entered
            goto end_loop; // Unnecessary use of goto statement, impacts readability
        }

        prod *= val; // Multiply the current product by the input value
    }

    end_loop:; // Label for the goto statement

    // Display the final calculated product
    std::cout << "Product of non-zero numbers: " << prod << std::endl;

    return 0; // Indicate successful program execution
}