#include <iostream>
#include <cctype> // For islower, toupper (though manual conversion is used)
#include <cstring>

// Correct strToUpper function implementation
void strToUpper(char* str) {
    if (str == nullptr) {
        return;
    }
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') { // Check if it's a lowercase letter
            str[i] = str[i] - ('a' - 'A');    // Convert to uppercase
        }
        i++;
    }
}

int main() {
    // SEMANTIC ERROR: Attempting to modify a string literal.
    // String literals (e.g., "hello World!") are typically stored in read-only memory.
    // Assigning them to a `char*` and then attempting to modify the contents
    // results in undefined behavior at runtime (often a segmentation fault).
    char* myString = "hello World! 123"; // myString points to a string literal
    
    std::cout << "Original string (before conversion attempt): " << myString << std::endl;
    strToUpper(myString); // This line causes undefined behavior
    std::cout << "Modified string (after conversion attempt): " << myString << std::endl;

    // A correct demonstration would use a mutable character array:
    // char correctExample[] = "another example";
    // strToUpper(correctExample);
    // std::cout << "Correct example: " << correctExample << std::endl;

    return 0;
}