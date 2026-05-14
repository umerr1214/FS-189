#include <iostream> // Required for std::cout, std::endl
#include <cstddef>  // Required for nullptr

// Function to calculate the length of a C-style string
// This version contains a syntax error (missing semicolon)
int customStrlen(const char* str) {
    if (str == nullptr) {
        return 0;
    }
    int length = 0 // ERROR: Missing semicolon here
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    // Example usage and test cases
    std::cout << "--- Testing customStrlen (Syntax Error Version) ---" << std::endl;

    const char* s1 = "hello";
    std::cout << "String: \"" << s1 << "\"" << std::endl;
    std::cout << "Expected length: 5" << std::endl;
    // This line will cause a compilation error due to the syntax error in customStrlen
    // std::cout << "Actual length: " << customStrlen(s1) << std::endl << std::endl;

    const char* s2 = "";
    std::cout << "String: \"" << s2 << "\"" << std::endl;
    std::cout << "Expected length: 0" << std::endl;
    // std::cout << "Actual length: " << customStrlen(s2) << std::endl << std::endl;

    const char* s3 = "programming";
    std::cout << "String: \"" << s3 << "\"" << std::endl;
    std::cout << "Expected length: 11" << std::endl;
    // std::cout << "Actual length: " << customStrlen(s3) << std::endl << std::endl;

    const char* s4 = nullptr;
    std::cout << "String: nullptr" << std::endl;
    std::cout << "Expected length: 0" << std::endl;
    // std::cout << "Actual length: " << customStrlen(s4) << std::endl << std::endl;

    return 0;
}