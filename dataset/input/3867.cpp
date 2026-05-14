#include <iostream> // Required for std::cout, std::endl

// Correct Version: This function correctly copies a C-style string from `source` to `destination`.
// It uses a single-pass loop with pointer arithmetic, which is both efficient and idiomatic C++.
// The loop continues until the null terminator ('\0') is copied, ensuring the `destination`
// string is properly null-terminated and a valid C-style string.
void copyCString(const char* source, char* destination) {
    // Loop copies character by character.
    // The assignment `*destination++ = *source++` copies the character pointed to by `source`
    // to the location pointed to by `destination`, then increments both pointers.
    // The loop continues as long as the character *just copied* is not the null terminator.
    while ((*destination++ = *source++) != '\0');
}

int main() {
    char dest1[50]; // Sufficient capacity for all test cases
    char dest2[50];
    char dest3[50];
    char dest4[50];

    // Test case 1
    const char* src1 = "Hello, World!";
    copyCString(src1, dest1);
    std::cout << "Source: \"" << src1 << "\"" << std::endl;
    std::cout << "Destination (Correct): \"" << dest1 << "\"" << std::endl;

    // Test case 2: Empty string
    const char* src2 = "";
    copyCString(src2, dest2);
    std::cout << "Source: \"" << src2 << "\"" << std::endl;
    std::cout << "Destination (Correct): \"" << dest2 << "\"" << std::endl;

    // Test case 3: Longer string
    const char* src3 = "Another example string";
    copyCString(src3, dest3);
    std::cout << "Source: \"" << src3 << "\"" << std::endl;
    std::cout << "Destination (Correct): \"" << dest3 << "\"" << std::endl;

    // Test case 4: Short string
    const char* src4 = "Hi";
    copyCString(src4, dest4);
    std::cout << "Source: \"" << src4 << "\"" << std::endl;
    std::cout << "Destination (Correct): \"" << dest4 << "\"" << std::endl;

    return 0;
}