#include <iostream>
#include <string>    // Required for std::string
#include <iomanip>   // Required for std::fixed and std::setprecision

int main() {
    double first_number_input, second_number_input;
    std::string operator_string_input; // Using string for operator, then converting
    char actual_operator_char = ' '; // Will hold the single char operator
    double final_calculated_result;

    std::cout << "Enter first number: ";
    std::cin >> first_number_input;

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> operator_string_input; // Read as string

    std::cout << "Enter second number: ";
    std::cin >> second_number_input;

    // Readability/Efficiency Issue: Unnecessary conversion from string to char
    // for a single character operator, using multiple if-else if statements.
    // Reading directly into a char would be simpler and more efficient.
    if (operator_string_input.length() == 1) {
        if (operator_string_input[0] == '+') {
            actual_operator_char = '+';
        } else if (operator_string_input[0] == '-') {
            actual_operator_char = '-';
        } else if (operator_string_input[0] == '*') {
            actual_operator_char = '*';
        } else if (operator_string_input[0] == '/') {
            actual_operator_char = '/';
        } else {
            actual_operator_char = 'I'; // 'I' for Invalid
        }
    } else {
        actual_operator_char = 'I'; // 'I' for Invalid
    }

    switch (actual_operator_char) {
        case '+':
            final_calculated_result = first_number_input + second_number_input;
            std::cout << std::fixed << std::setprecision(2) << "Result: " << final_calculated_result << std::endl;
            break;
        case '-':
            final_calculated_result = first_number_input - second_number_input;
            std::cout << std::fixed << std::setprecision(2) << "Result: " << final_calculated_result << std::endl;
            break;
        case '*':
            final_calculated_result = first_number_input * second_number_input;
            std::cout << std::fixed << std::setprecision(2) << "Result: " << final_calculated_result << std::endl;
            break;
        case '/':
            if (second_number_input == 0) {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            } else {
                final_calculated_result = first_number_input / second_number_input;
                std::cout << std::fixed << std::setprecision(2) << "Result: " << final_calculated_result << std::endl;
            }
            break;
        case 'I': // Handle the 'Invalid' operator case
        default:  // Fallback for any other unexpected char, though 'I' covers it
            std::cout << "Error: Invalid operator." << std::endl;
            break;
    }

    return 0;
}