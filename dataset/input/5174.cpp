#include <iostream>
#include <string> // Required for std::string

// Function with an efficiency issue: uses std::string conversion
int customStrlen(const char* str) {
    if (str == nullptr) {
        // Handle nullptr gracefully for correctness, but the issue is in the main logic.
        return 0;
    }
    // Efficiency issue: creates a temporary std::string object, which involves
    // an internal iteration and memory allocation/copy of the C-style string.
    std::string temp_str(str); 
    return static_cast<int>(temp_str.length()); // Then calls its length method.
}

int main() {
    // Test cases
    const char* s1 = "hello";
    const char* s2 = "";
    const char* s3 = "a";
    const char* s4 = "long string with spaces";
    const char* s5 = nullptr; // Handled gracefully

    std::cout << "Testing with \"hello\": " << customStrlen(s1) << std::endl;
    std::cout << "Testing with \"\": " << customStrlen(s2) << std::endl;
    std::cout << "Testing with \"a\": " << customStrlen(s3) << std::endl;
    std::cout << "Testing with \"long string with spaces\": " << customStrlen(s4) << std::endl;
    std::cout << "Testing with nullptr: " << customStrlen(s5) << std::endl;

    return 0;
}