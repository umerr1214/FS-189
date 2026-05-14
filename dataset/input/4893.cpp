#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Not strictly needed for this specific two-pointer approach, but useful generally
#include <cctype>    // For std::tolower, std::isalnum

// This is a correct, efficient, and readable implementation.
// It uses a two-pointer approach to check for palindrome properties
// while ignoring non-alphanumeric characters and case, without
// creating additional string copies.
bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        // Move left pointer past non-alphanumeric characters
        while (left < right && !std::isalnum(static_cast<unsigned char>(str[left]))) {
            left++;
        }
        // Move right pointer past non-alphanumeric characters
        while (left < right && !std::isalnum(static_cast<unsigned char>(str[right]))) {
            right--;
        }

        // If pointers meet or cross, the remaining part is a palindrome (or empty/single char)
        if (left >= right) {
            break;
        }

        // Compare characters (case-insensitively)
        // Ensure to cast to unsigned char before passing to tolower/toupper to avoid UB with negative char values
        if (std::tolower(static_cast<unsigned char>(str[left])) != std::tolower(static_cast<unsigned char>(str[right]))) {
            return false; // Mismatch found
        }

        // Move pointers inward
        left++;
        right--;
    }

    return true; // All relevant characters matched
}

int main() {
    std::vector<std::string> test_inputs = {
        "",
        " ",
        "A",
        "racecar",
        "RaceCar",
        "A man, a plan, a canal: Panama",
        "No lemon, no melon",
        "Was it a car or a cat I saw?",
        "Madam, I'm Adam",
        "hello",
        "world",
        "12321",
        "1 2 3 2 1",
        "A.B.A",
        "apple",
        "test"
    };

    std::cout << "--- Predefined Test Cases ---\n";
    for (const std::string& input : test_inputs) {
        std::cout << "Input: \"" << input << "\"\n";
        std::cout << (isPalindrome(input) ? "true" : "false") << "\n";
        std::cout << "---\n";
    }

    // Also demonstrate with user input as required by question
    std::string user_input;
    std::cout << "\n--- User Input Demo ---\n";
    std::cout << "Enter a string: ";
    std::getline(std::cin, user_input);
    std::cout << "Input: \"" << user_input << "\"\n";
    std::cout << (isPalindrome(user_input) ? "true" : "false") << "\n";

    return 0;
}