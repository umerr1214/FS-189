#include <iostream>
#include <string>
#include <algorithm> // For std::transform, std::reverse
#include <cctype>    // For std::isalnum, std::tolower
#include <vector>    // Not strictly needed but common for algorithms

// This version is correct but suffers from efficiency issues due to multiple string copies
// and transformations, making it less optimal for very long strings.
bool isPalindromeSolution(const std::string& s) {
    // Step 1: Filter out non-alphanumeric characters and build a new string.
    // This involves iterating through the input string and potentially allocating a new string.
    std::string filtered_s;
    for (char c : s) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            filtered_s += c;
        }
    }

    // Step 2: Convert the filtered string to lowercase.
    // This creates another copy of the string (`lower_s = filtered_s`) and then modifies it.
    std::string lower_s = filtered_s;
    std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    // Step 3: Create a reversed copy of the lowercase string.
    // This creates yet another copy of the string (`reversed_s = lower_s`) and then reverses it.
    std::string reversed_s = lower_s;
    std::reverse(reversed_s.begin(), reversed_s.end());

    // Step 4: Compare the original lowercase string with its reversed copy.
    // This involves character-by-character comparison.
    return lower_s == reversed_s;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (isPalindromeSolution(input)) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }

    return 0;
}