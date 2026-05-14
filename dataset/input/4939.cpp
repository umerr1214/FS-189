#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    double num1, num2;
    int choice;

    while (true) { // Loop indefinitely until input stream ends
        std::cout << "Menu:\n";
        std::cout << "1. Add\n";
        std::cout << "2. Subtract\n";
        std::cout << "3. Multiply\n";
        std::cout << "4. Divide\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Robustness Issue: Incomplete input validation for choice
        // If non-numeric input, cin.fail() will be true, cleared, but no specific error message or recovery.
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Simply re-loop without a clear error message for invalid choice type
            continue;
        }

        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        // Basic input failure check for numbers, but recovery is not perfect (loops without re-prompting choice)
        if (std::cin.fail()) {
            std::cout << "Invalid number input. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Result: " << num1 + num2 << "\n";
                break;
            case 2:
                std::cout << "Result: " << num1 - num2 << "\n";
                break;
            case 3:
                std::cout << "Result: " << num1 * num2 << "\n";
                break;
            case 4:
                // Robustness Issue: No division by zero check
                // For doubles, this will typically result in 'inf' or 'nan' without a proper error message.
                std::cout << "Result: " << num1 / num2 << "\n";
                break;
            default:
                // Robustness Issue: No clear error message for invalid numeric choice, just loops
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}