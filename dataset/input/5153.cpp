#include <iostream>
#include <string>

int main() {
    int num1, num2;

    std::cout << "Enter the first integer: ";
    std::cin >> num1;

    std::cout << "Enter the second integer: ";
    std::cin >> num2;

    // Logical Error: The ternary operator incorrectly determines the smaller value
    // but the message claims it's the larger one.
    int result = (num1 < num2) ? num1 : num2; // This picks the smaller number

    std::string output_message;
    if (num1 == num2) {
        output_message = "Both integers are equal: ";
    } else {
        output_message = "The larger integer is: "; // This message is misleading for the 'result'
    }
    
    std::cout << output_message << result << std::endl;

    return 0;
}