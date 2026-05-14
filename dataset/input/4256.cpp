#include <iostream>
#include <string>
#include <algorithm> // Not strictly needed, but often included for string manipulation

// Renamed main to user_main for testing harness compatibility
int user_main() {
    std::string input_str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input_str);

    // Readability/Efficiency Issue:
    // 1. Inefficient string construction: building the reversed string character by character
    //    using repeated string concatenations, which can lead to O(N^2) complexity due to reallocations.
    // 2. Unnecessary intermediate string: the string could be printed directly in reverse.
    // 3. Suboptimal variable naming (`reversed_string_holder`, `current_idx`).

    std::string reversed_string_holder;
    // Using size_type for `current_idx` is technically correct but the variable name is not very descriptive.
    std::string::size_type current_idx = input_str.length();

    while (current_idx > 0) {
        current_idx--; // Decrement first to get a valid 0-based index
        // This repeated concatenation can be inefficient for long strings.
        reversed_string_holder += input_str[current_idx];
    }

    std::cout << reversed_string_holder << std::endl;

    return 0;
}