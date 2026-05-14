#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::transform (though not used in final bug version)
#include <cctype>    // For std::tolower, std::isalnum
#include <stdexcept> // For std::exception

// This version has a robustness issue: it will crash for strings that
// become empty after filtering (e.g., "", " ", "!@#") due to direct
// access of filtered_str[0] without checking if the string is empty.
bool isPalindrome(const std::string& str) {
    std::string filtered_str;
    for (char c : str) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            filtered_str += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
    }

    // Robustness issue: If filtered_str is empty (e.g., input "", " ", "!@#"),
    // accessing filtered_str[0] will result in undefined behavior, typically a crash (segmentation fault).
    // A robust solution would check `filtered_str.empty()` before attempting to access elements.
    if (filtered_str.empty()) {
        // This line is specifically added to demonstrate a robustness issue (crash).
        // In a real scenario, this would likely be an accidental omission of an empty check.
        volatile char c = filtered_str[0]; // CRASH if filtered_str is empty
        (void)c; // To suppress unused variable warning
        return true; // This line is logically unreachable if the above line crashes.
    }

    int left = 0;
    int right = filtered_str.length() - 1;

    while (left < right) {
        if (filtered_str[left] != filtered_str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::vector<std::string> test_inputs = {
        "",         // Should crash with this implementation
        " ",        // Should crash
        "!@#",      // Should crash
        "madam",
        "A man a plan a canal Panama",
        "hello",
        "Race car",
        "No lemon, no melon",
        "12321",
        "Was it a car or a cat I saw?"
    };

    std::cout << "--- Predefined Test Cases ---\n";
    for (const std::string& tc : test_inputs) {
        std::cout << "Input: \"" << tc << "\"\n";
        try {
            if (isPalindrome(tc)) {
                std::cout << "true\n";
            } else {
                std::cout << "false\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Caught exception: " << e.what() << "\n";
            std::cout << "ERROR\n"; // Output "ERROR" if it catches an exception (e.g., std::out_of_range)
        } catch (...) {
            // This block might not be reached for a segmentation fault, but indicates a severe error.
            std::cerr << "Caught unknown exception (likely crash due to robustness issue).\n";
            std::cout << "ERROR\n"; // Output "ERROR" for potential crashes
        }
        std::cout << "---\n";
    }

    // Also demonstrate with user input as required by question
    std::string user_input;
    std::cout << "\n--- User Input Demo ---\n";
    std::cout << "Enter a string: ";
    std::getline(std::cin, user_input);
    std::cout << "Input: \"" << user_input << "\"\n";
    try {
        if (isPalindrome(user_input)) {
            std::cout << "true\n";
        } else {
            std::cout << "false\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
        std::cout << "ERROR\n";
    } catch (...) {
        std::cerr << "Caught unknown exception (likely crash).\n";
        std::cout << "ERROR\n";
    }

    return 0;
}