#include <iostream>
#include <cstring> // Required for std::strlen in main to determine print length

// Robustness Issue: This function copies characters from source to destination
// but explicitly *omits* copying the null terminator ('\0').
// This leaves the 'destination' character array unterminated, which is not a valid C-style string.
// Any subsequent operations on 'destination' that expect a null-terminated string (like std::cout << destination,
// or std::strlen(destination)) will lead to undefined behavior, potentially reading past the buffer
// or causing crashes.
void copyCString(const char* source, char* destination) {
    int i = 0;
    while (source[i] != '\0') { // Loop runs until the null terminator is encountered in source
        destination[i] = source[i];
        i++;
    }
    // Critical omission: destination[i] = '\0';
    // The destination array is left without a null terminator.
}

// Helper function for the driver to set up and print for a test case
void run_test(const char* source_val) {
    char dest_buffer[100]; // Sufficient capacity assumed by the question
    // Fill buffer with a known character (e.g., '#') to make the missing null terminator visible.
    // When printed, the copied string will be followed by these filler characters.
    for (int k = 0; k < 100; ++k) {
        dest_buffer[k] = '#';
    }

    copyCString(source_val, dest_buffer);

    std::cout << "Source: \"" << source_val << "\"" << std::endl;
    std::cout << "Destination (Robustness Issue): \"";
    // Print up to the source string's length plus a few extra characters
    // to clearly demonstrate that the null terminator is missing and garbage/filler follows.
    int print_len = std::strlen(source_val);
    for (int i = 0; i < print_len + 5 && i < 100; ++i) { // Print up to 5 extra chars or buffer end
        std::cout << dest_buffer[i];
    }
    std::cout << "\"" << std::endl;
}

int main() {
    run_test("Hello");
    run_test("");
    run_test("A");
    run_test("Long string test");

    return 0;
}