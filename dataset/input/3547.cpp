#include <iostream>
#include <string>
#include <algorithm> // Not strictly needed for this logic, but often included.

int main() {
    std::string inputString;
    // Robustness issue: std::cin >> inputString reads only until the first whitespace.
    // This makes the program not handle multi-word inputs as a single string for palindrome check.
    // For example, "race car" will be read as "race".
    std::cin >> inputString; 

    if (inputString.empty()) {
        std::cout << "Palindrome" << std::endl;
        return 0;
    }

    int left = 0;
    int right = inputString.length() - 1;
    bool isPalindrome = true;

    while (left < right) {
        if (inputString[left] != inputString[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        std::cout << "Palindrome" << std::endl;
    } else {
        std::cout << "Not a palindrome" << std::endl;
    }

    return 0;
}