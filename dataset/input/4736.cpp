#include <iostream>
#include <string>

// Function containing the program's logic, exhibiting readability/efficiency issues
void execute_program_logic() {
    std::string s; // Less descriptive variable name for sentence
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, s);

    char c; // Less descriptive variable name for character
    std::cout << "Enter a character to count: ";
    std::cin >> c;

    // No std::cin.ignore() after reading char, which can cause issues in chained inputs (though not this specific program's main error type)

    int count = 0;
    // Inefficient loop:
    // 1. `s.length()` is called in each iteration of the loop condition, potentially re-calculating the string length.
    // 2. Using `s.at(i)` adds bounds checking overhead compared to `s[i]`.
    // 3. A simple C-style for loop is used instead of a more idiomatic and potentially clearer range-based for loop or std::count.
    for (int i = 0; i < s.length(); ++i) {
        if (s.at(i) == c) {
            count++;
        }
    }

    std::cout << "The character '" << c << "' appears " << count << " times." << std::endl;
}

int main() {
    execute_program_logic();
    return 0;
}