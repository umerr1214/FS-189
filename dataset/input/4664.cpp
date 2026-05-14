#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision

int main() {
    double v1, v2; // Poor variable names (v1, v2)
    char op_char_val; // Verbose and slightly redundant variable name

    std::cout << "Kindly input the initial numerical value: "; // Overly verbose prompt
    std::cin >> v1;

    std::cout << "Kindly input the mathematical operation symbol (+, -, *, /): "; // Overly verbose prompt
    std::cin >> op_char_val;

    std::cout << "Kindly input the subsequent numerical value: "; // Overly verbose prompt
    std::cin >> v2;

    double calc_result; // Poor variable name

    // Using std::fixed and std::setprecision for all outputs,
    // which is fine but the precision is hardcoded and might not always be desired.
    std::cout << std::fixed << std::setprecision(2);

    switch (op_char_val) {
        case '+':
            calc_result = v1 + v2;
            std::cout << "The calculated sum of " << v1 << " and " << v2 << " is: " << calc_result << std::endl; // Verbose output
            break;
        case '-':
            calc_result = v1 - v2;
            std::cout << "The calculated difference of " << v1 << " and " << v2 << " is: " << calc_result << std::endl; // Verbose output
            break;
        case '*':
            calc_result = v1 * v2;
            std::cout << "The calculated product of " << v1 << " and " << v2 << " is: " << calc_result << std::endl; // Verbose output
            break;
        case '/':
            if (v2 != 0) { // Division by zero check is present, but overall readability is low.
                calc_result = v1 / v2;
                std::cout << "The calculated quotient of " << v1 << " and " << v2 << " is: " << calc_result << std::endl; // Verbose output
            } else {
                std::cout << "An arithmetic error occurred: Division by zero is not permissible." << std::endl; // Verbose error
                return 1;
            }
            break;
        default:
            std::cout << "An input error occurred: The provided operator symbol is not recognized." << std::endl; // Verbose error
            return 1;
    }

    return 0;
}