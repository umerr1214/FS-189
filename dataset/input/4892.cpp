#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::transform, std::reverse
#include <cctype>    // For std::tolower, std::isalnum

// This version is functionally correct but has readability and efficiency issues.
// It creates multiple intermediate strings and performs several full string passes,
// leading to unnecessary memory allocations and copies.
bool isPalindrome(const std::string& str) {
    std::string filtered_str;
    // Step 1: Filter out non-alphanumeric characters.
    // This creates a new string with only alphanumeric characters.
    for (char c : str) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            filtered_str += c;
        }
    }

    std::string lower_cased_str = filtered_str;
    // Step 2: Convert the filtered string to lowercase.
    // This creates another temporary string and iterates over it again.
    std::transform(lower_cased_str.begin(), lower_cased_str.end(), lower_cased_str.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    std::string reversed_str = lower_cased_str;
    // Step 3: Create a reversed version of the lowercase string.
    // This creates yet another temporary string and iterates over it again.
    std::reverse(reversed_str.begin(), reversed_str.end());

    // Step 4: Compare the original lowercase string with its reversed version.
    return lower_cased_str == reversed_str;
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