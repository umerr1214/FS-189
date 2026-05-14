#include <iostream>
#include <string> // Unnecessary include for this simple problem, adds minor bloat

int main() {
    int input_val;
    std::cout << "Please enter an integer: ";
    std::cin >> input_val;

    // Using an extra string variable to store the message, which is then printed.
    // This is less efficient than printing directly and adds an unnecessary variable.
    std::string classification_message;

    if (input_val > 0) {
        classification_message = "The number is positive.";
    } else {
        // Nested if-else for negative/zero, where a single 'else if' would be cleaner and more direct.
        if (input_val < 0) {
            classification_message = "The number is negative.";
        } else {
            // This condition is implicitly input_val == 0
            classification_message = "The number is zero.";
        }
    }
    
    std::cout << classification_message << std::endl;

    return 0;
}