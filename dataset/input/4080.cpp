#include <iostream>

bool isPalindrome(int num) {
    // Semantic Error: This function is named isPalindrome but checks if the number is even.
    // It compiles and runs, but its behavior does not match its declared intent.
    return num % 2 == 0;
}

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    if (isPalindrome(num)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    return 0;
}