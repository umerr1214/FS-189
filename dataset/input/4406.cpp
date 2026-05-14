#include <iostream>
#include <cstring> // Included for strlen, but not used in the concatenation logic for demonstration
#include <cstdio>  // For printf

// Function with readability and efficiency issues:
// It implements string concatenation using manual loops for character copying
// and length calculation, which is less readable and potentially less efficient
// than using optimized standard library functions like `strcpy` and `strcat`.
void concatenateStrings(const char* s1, const char* s2) {
    // Assuming 'destination array has enough space' by using a fixed-size buffer.
    // For general robustness, dynamic allocation or checking buffer size would be better,
    // but the focus here is on the manual loop implementation.
    char buffer[512]; // Fixed-size buffer, assuming it's large enough for test cases

    int i = 0;
    // Manually copy characters from s1 to buffer
    // This loop effectively re-calculates the length of s1 as it copies.
    while (s1[i] != '\0') {
        buffer[i] = s1[i];
        i++;
    }

    int j = 0;
    // Manually copy characters from s2 to buffer, starting after s1's content
    // This loop effectively re-calculates the length of s2 as it copies.
    while (s2[j] != '\0') {
        buffer[i + j] = s2[j];
        j++;
    }
    // Manually add the null terminator at the end of the combined string
    buffer[i + j] = '\0';

    printf("%s\n", buffer);
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

    return 0;
}