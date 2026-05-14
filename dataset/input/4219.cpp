#include <iostream>

int main() {
    double num1 = 0.0, num2 = 0.0; // Initialize to make behavior more predictable on input failure
    char op = '\0'; // Initialize to make behavior more predictable on input failure

    std::cout << "Enter first number: ";
    std::cin >> num1;

    // Robustness issue: Not checking cin.fail() or clearing state here.
    // If num1 input fails (e.g., user enters 'abc'), cin will be in a fail state.
    // Subsequent std::cin operations (for op and num2) will then immediately fail
    // without reading new input, leaving 'op' and 'num2' as their initialized values.

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op; // This will likely fail if num1 input failed

    std::cout << "Enter second number: ";
    std::cin >> num2; // This will likely fail if num1 input failed

    double result;
    bool valid_operation = true;

    switch (op) { // 'op' might be '\0' or garbage if previous reads failed
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) { // num2 might be 0 due to failed input or actual zero
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                valid_operation = false;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            // This case will likely be hit if 'op' failed to read due to prior input error
            // (e.g., if num1 input failed, op remains '\0' from initialization).
            std::cout << "Error: Invalid operator or input stream error." << std::endl;
            valid_operation = false;
            break;
    }

    if (valid_operation) {
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}