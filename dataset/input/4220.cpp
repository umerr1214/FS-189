#include <iostream>

int main() {
    double n1, n2; // Poor variable names (n1, n2 instead of num1, num2)
    char opr;      // Poor variable name (opr instead of operation)

    std::cout << "Please input first value: "; // Verbose and less clear prompt
    std::cin >> n1;
    std::cout << std::endl; // Excessive use of std::endl, leading to unnecessary buffer flushes and verbosity

    std::cout << "Now, what operation do you want to perform (+, -, *, /)? "; // Verbose and less clear prompt
    std::cin >> opr;
    std::cout << std::endl; // Excessive use of std::endl

    std::cout << "Finally, input second value: "; // Verbose and less clear prompt
    std::cin >> n2;
    std::cout << std::endl; // Excessive use of std::endl

    double res; // Poor variable name (res instead of result)
    bool ok = true; // Poor variable name (ok instead of calculation_successful)

    switch (opr) {
        case '+':
            res = n1 + n2;
            break;
        case '-':
            res = n1 - n2;
            break;
        case '*':
            res = n1 * n2;
            break;
        case '/':
            if (n2 == 0) { // Correct logic, but message is slightly less professional
                std::cout << "Cannot divide by zero here. This is an error." << std::endl;
                ok = false;
            } else {
                res = n1 / n2;
            }
            break;
        default: // Correct default handling
            std::cout << "That's not a valid operation symbol. Try again next time." << std::endl;
            ok = false;
            break;
    }

    if (ok) {
        std::cout << "The final outcome is: " << res << std::endl; // Verbose and less clear output
    }

    return 0;
}