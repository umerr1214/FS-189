#include <iostream>
#include <cstring> // For strcmp to verify
#include <cstddef> // For size_t

// Function with readability/efficiency issues:
// 1. Inefficient: Performs two passes over the source string.
// 2. Less idiomatic: Uses an indexed loop after calculating length, instead of direct pointer arithmetic.
void myStrcpy(char* dest, const char* src) {
    // First pass: Calculate the length of the source string.
    // This is inefficient as it iterates through the string once just to find its length.
    size_t len = 0;
    while (src[len] != '\0') {
        len++;
    }

    // Second pass: Copy characters from source to destination, including the null terminator.
    // This iterates through the string a second time.
    for (size_t i = 0; i <= len; ++i) {
        dest[i] = src[i];
    }
}

int main() {
    std::cout << "--- Testing myStrcpy with Readability/Efficiency Issues ---\n\n";

    // Test Case 1: Normal copy
    char dest1[50];
    const char* src1 = "Hello, World!";
    myStrcpy(dest1, src1);
    std::cout << "Test 1: Normal copy\n";
    std::cout << "  Source: \"" << src1 << "\"\n";
    std::cout << "  Dest:   \"" << dest1 << "\"\n";
    std::cout << "  Expected: \"" << src1 << "\"\n";
    std::cout << "  Result: " << (std::strcmp(dest1, src1) == 0 ? "PASS" : "FAIL") << "\n\n";

    // Test Case 2: Empty string
    char dest2[10];
    const char* src2 = "";
    myStrcpy(dest2, src2);
    std::cout << "Test 2: Empty string\n";
    std::cout << "  Source: \"" << src2 << "\"\n";
    std::cout << "  Dest:   \"" << dest2 << "\"\n";
    std::cout << "  Expected: \"" << src2 << "\"\n";
    std::cout << "  Result: " << (std::strcmp(dest2, src2) == 0 ? "PASS" : "FAIL") << "\n\n";

    // Test Case 3: Short string
    char dest3[20];
    const char* src3 = "Test";
    myStrcpy(dest3, src3);
    std::cout << "Test 3: Short string\n";
    std::cout << "  Source: \"" << src3 << "\"\n";
    std::cout << "  Dest:   \"" << dest3 << "\"\n";
    std::cout << "  Expected: \"" << src3 << "\"\n";
    std::cout << "  Result: " << (std::strcmp(dest3, src3) == 0 ? "PASS" : "FAIL") << "\n\n";

    // Test Case 4: String with numbers/symbols
    char dest4[30];
    const char* src4 = "123 Go! ABC";
    myStrcpy(dest4, src4);
    std::cout << "Test 4: String with numbers/symbols\n";
    std::cout << "  Source: \"" << src4 << "\"\n";
    std::cout << "  Dest:   \"" << dest4 << "\"\n";
    std::cout << "  Expected: \"" << src4 << "\"\n";
    std::cout << "  Result: " << (std::strcmp(dest4, src4) == 0 ? "PASS" : "FAIL") << "\n\n";

    return 0;
}