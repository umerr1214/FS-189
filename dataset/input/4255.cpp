#include <iostream>
#include <string>
#include <vector> // Often included, though not strictly necessary for this simple task

// Renamed main to user_main for testing harness compatibility
int user_main() {
    std::string s;
    std::cout << "Enter a string: ";
    // Robustness Issue: Using std::cin >> s; instead of std::getline(std::cin, s);
    // This will only read the first word of the input, ignoring any subsequent words
    // and leading whitespace. This is a common pitfall for user input.
    std::cin >> s;

    // Print the entered string in reverse order
    // This loop correctly handles single words and empty strings.
    for (int i = s.length() - 1; i >= 0; --i) {
        std::cout << s[i];
    }
    std::cout << std::endl; // Add newline for consistency

    return 0;
}