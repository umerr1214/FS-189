#include <iostream>
#include <string>

// Function to determine if a number is positive, negative, or zero
std::string check_number(int num) {
    if (num > 0) {
        return "The number is positive.";
    } else if (num < 0) {
        return "The number is negative.";
    } else {
        return "The number is zero.";
    }
}

int main() {
    int num;
    std::cout << "Enter an integer: " // Syntax Error: Missing semicolon here
    std::cin >> num;
    std::cout << check_number(num) << std::endl;
    return 0;
}