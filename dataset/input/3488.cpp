#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <limits>  // For std::numeric_limits

// Function to encapsulate calculator logic for testing
void solve() {
    double n1, n2; // Cryptic variable names
    char op; // Cryptic variable name
    double r = 0.0; // Initialize result

    // Poor formatting and excessive std::endl
    std::cout << "Enter first number: " << std::endl;
    std::cin >> n1;

    std::cout << "Enter operator (+, -, *, /): " << std::endl;
    std::cin >> op;

    std::cout << "Enter second number: " << std::endl;
    std::cin >> n2;

    // No comments explaining input validation or logic
    if (std::cin.fail()) {
        std::cout << "Bad input for numbers." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    switch (op) {
        case '+': r = n1 + n2; break;
        case '-': r = n1 - n2; break;
        case '*': r = n1 * n2; break;
        case '/':
            if (n2 == 0) {
                std::cout << "Cannot divide by zero!" << std::endl;
                return;
            }
            r = n1 / n2;
            break;
        default:
            // Readability/Efficiency Issue: Generic error message, still prints default result
            std::cout << "Invalid operation!" << std::endl;
            break;
    }

    // Inconsistent formatting for output
    std::cout << "Result: " << std::fixed << std::setprecision(2) << r << std::endl;
}

int main() {
    // Calling the function
    solve();
    return 0;
}