#include <iostream>
#include <string>

// Function to determine if a number is positive, negative, or zero
std::string check_number(int num) {
    // Logical Error: Classifies zero as positive
    if (num >= 0) { // Should be 'num > 0' for positive, then 'num == 0' for zero
        return "The number is positive.";
    } else { // This else block correctly handles negative numbers
        return "The number is negative.";
    }
}

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    std::cout << check_number(num) << std::endl;
    return 0;
}