#include <iostream>
#include <cstring> // Not used in copyCString, but good practice for C-string manipulation examples

// Readability / Efficiency Issue:
// 1. Inefficient: The function performs two passes over the `source` string.
//    The first pass calculates the length, and the second pass copies the characters.
//    A single-pass approach (copying characters and checking for null terminator simultaneously)
//    is more efficient for this operation.
// 2. Readability: While functionally correct, using a separate loop for length calculation
//    and then another `for` loop for copying is less idiomatic and potentially less clear
//    than a single `while` loop with pointer arithmetic or a direct character-by-character copy.
void copyCString(const char* source, char* destination) {
    // First pass: Calculate the length of the source string
    int len = 0;
    while (source[len] != '\0') {
        len++;
    }

    // Second pass: Copy characters from source to destination, including the null terminator
    for (int i = 0; i <= len; ++i) { // Loop includes the null terminator at index 'len'
        destination[i] = source[i];
    }
}

int main() {
    char dest1[50];
    char dest2[50];
    char dest3[50];

    // Test case 1
    const char* src1 = "Hello, World!";
    copyCString(src1, dest1);
    std::cout << "Source: \"" << src1 << "\"" << std::endl;
    std::cout << "Destination (Readability/Efficiency): \"" << dest1 << "\"" << std::endl;

    // Test case 2
    const char* src2 = "";
    copyCString(src2, dest2);
    std::cout << "Source: \"" << src2 << "\"" << std::endl;
    std::cout << "Destination (Readability/Efficiency): \"" << dest2 << "\"" << std::endl;

    // Test case 3
    const char* src3 = "Short";
    copyCString(src3, dest3);
    std::cout << "Source: \"" << src3 << "\"" << std::endl;
    std::cout << "Destination (Readability/Efficiency): \"" << dest3 << "\"" << std::endl;

    return 0;
}