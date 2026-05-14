#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

// Readability / Efficiency Issue:
// - The function takes the string by value, creating a copy.
// - It then creates *another* copy to reverse, leading to O(N) space complexity where O(1) is possible.
// - The reversal and comparison approach is less efficient than a two-pointer method for very long strings.
bool isPalindrome(std::string s_word_copy) { // Passing by value creates a copy
    std::string s_reversed_copy = s_word_copy; // Creates another copy
    std::reverse(s_reversed_copy.begin(), s_reversed_copy.end()); // Modifies the second copy
    return s_word_copy == s_reversed_copy; // Compares the two strings
}

int main() {
    std::string myInputWord; // Informal variable name
    std::cout << "Please type a word for palindrome check: "; // Slightly informal prompt

    if (!(std::cin >> myInputWord)) {
        std::cerr << "Oops! Something went wrong reading your word. Try again?" << std::endl; // Informal error message
        return 1;
    }

    if (isPalindrome(myInputWord)) {
        std::cout << "Yep, '" << myInputWord << "' is totally a palindrome!" << std::endl; // Informal output
    } else {
        std::cout << "Nope, '" << myInputWord << "' is not a palindrome at all." << std::endl; // Informal output
    }

    return 0;
}