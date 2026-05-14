#include <iostream>
#include <cstring> // Required for strlen, strcpy, strcat
#include <cstdio>  // Required for printf

// Correct and idiomatic C-style string concatenation function.
// It uses standard library functions for efficiency and readability,
// and dynamically allocates memory to ensure enough space.
void concatenateStrings(const char* s1, const char* s2) {
    // Calculate the lengths of the input strings.
    // This is efficient as strlen is typically highly optimized.
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    // Dynamically allocate a buffer large enough to hold both strings
    // plus one character for the null terminator.
    // This adheres to the "Assume the destination array has enough space" by creating it
    // with the exact required size.
    char* buffer = new char[len1 + len2 + 1];

    // Copy the first string into the buffer.
    strcpy(buffer, s1);
    // Append the second string to the buffer.
    strcat(buffer, s2);

    // Print the combined string.
    printf("%s\n", buffer);

    // Clean up the dynamically allocated memory to prevent memory leaks.
    delete[] buffer;
}

int main() {
    // Test cases for concatenateStrings
    std::cout << "--- Test Case 1: Basic Concatenation ---" << std::endl;
    concatenateStrings("Hello", " World"); // Expected: Hello World

    std::cout << "--- Test Case 2: Empty First String ---" << std::endl;
    concatenateStrings("", "World"); // Expected: World

    std::cout << "--- Test Case 3: Empty Second String ---" << std::endl;
    concatenateStrings("Hello", ""); // Expected: Hello

    std::cout << "--- Test Case 4: Both Empty Strings ---" << std::endl;
    concatenateStrings("", ""); // Expected: (empty line)

    std::cout << "--- Test Case 5: Longer Strings ---" << std::endl;
    concatenateStrings("Programming is fun!", " Let's learn C++."); // Expected: Programming is fun! Let's learn C++.

    std::cout << "--- Test Case 6: Strings with special characters ---" << std::endl;
    concatenateStrings("Path: C:\\Users\\", "Documents\\file.txt"); // Expected: Path: C:\Users\Documents\file.txt

    return 0;
}