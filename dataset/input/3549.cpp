#include <iostream>
#include <string>
#include <algorithm> // Not strictly needed for two-pointer, but often included.

int main() {
    std::string inputStr;
    std::getline(std::cin, inputStr); // Robustly reads the entire line from standard input

    if (inputStr.empty()) {
        std::cout << "Palindrome" << std::endl; // An empty string is conventionally a palindrome
        return 0;
    }

    int start = 0;
    int end = inputStr.length() - 1;
    bool isPalindrome = true;

    // Efficient two-pointer approach: compares characters from both ends inwards.
    // This method uses O(N) time complexity and O(1) extra space complexity.
    while (start < end) {
        if (inputStr[start] != inputStr[end]) {
            isPalindrome = false;
            break; // Mismatch found, no need to check further
        }
        start++;
        end--;
    }

    if (isPalindrome) {
        std::cout << "Palindrome" << std::endl;
    } else {
        std::cout << "Not a palindrome" << std::endl;
    }

    return 0;
}