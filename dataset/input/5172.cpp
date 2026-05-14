#include <iostream> // Required for std::cout, std::endl
#include <cstddef>  // Required for nullptr

// Function to calculate the length of a C-style string
// This version contains a semantic error (dereferences nullptr without check)
int customStrlen(const char* str) {
    // Semantic error: No check for nullptr. If 'str' is nullptr,
    // dereferencing '*str' will lead to Undefined Behavior (e.g., a crash).
    int length = 0;
    while (*str != '\0') { // This line causes UB if str is nullptr
        length++;
        str++;
    }
    return length;
}

int main() {
    // Example usage and test cases
    std::cout << "--- Testing customStrlen (Semantic Error Version) ---" << std::endl;

    const char* s1 = "hello";
    std::cout << "String: \"" << s1 << "\"" << std::endl;
    std::cout << "Expected length: 5, Actual length: " << customStrlen(s1) << std::endl << std::endl;

    const char* s2 = "";
    std::cout << "String: \"" << s2 << "\"" << std::endl;
    std::cout << "Expected length: 0, Actual length: " << customStrlen(s2) << std::endl << std::endl;

    const char* s3 = "programming";
    std::cout << "String: \"" << s3 << "\"" << std::endl;
    std::cout << "Expected length: 11, Actual length: " << customStrlen(s3) << std::endl << std::endl;

    const char* s4 = nullptr;
    std::cout << "String: nullptr" << std::endl;
    std::cout << "Expected length: 0" << std::endl;
    // This call will likely cause a runtime crash due to dereferencing nullptr
    std::cout << "Actual behavior: Calling customStrlen(nullptr) will result in Undefined Behavior (likely crash)." << std::endl;
    // customStrlen(s4); // Uncommenting this line would cause the crash
    
    return 0;
}