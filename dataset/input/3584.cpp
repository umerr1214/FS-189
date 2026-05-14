#include <iostream>
#include <string>

int main() {
    int number_to_check;
    std::cout << "Please enter an integer number: ";
    std::cin >> number_to_check;

    std::string result_message;

    // Readability/Efficiency Issue:
    // This code uses three independent 'if' statements instead of the requested 'if-else if-else' chain.
    // While it produces correct output for this specific problem (because the conditions are mutually exclusive),
    // it is less efficient as all three conditions are evaluated regardless of previous matches.
    // It also reduces readability by not clearly expressing the mutually exclusive nature of the conditions.
    // Additionally, the output messages are overly verbose.
    if (number_to_check > 0) {
        result_message = "The number is definitely positive.";
    }
    if (number_to_check < 0) {
        result_message = "The number is certainly negative.";
    }
    if (number_to_check == 0) {
        result_message = "The number is exactly zero.";
    }

    std::cout << result_message << std::endl;

    return 0;
}