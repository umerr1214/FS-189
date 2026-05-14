#include <iostream>
#include <cctype> // For toupper (though not used in the buggy code)
#include <cstring>

// Function to convert a C-style string to uppercase in-place
// LOGICAL ERROR: Converts ALL characters, not just lowercase letters.
// This will incorrectly modify numbers, symbols, and already uppercase letters.
void strToUpper(char* str) {
    if (str == nullptr) {
        return;
    }
    int i = 0;
    while (str[i] != '\0') {
        // This logic subtracts the difference between 'a' and 'A' from every character.
        // It should first check if the character is a lowercase letter.
        str[i] = str[i] - ('a' - 'A'); // This operation is only valid for lowercase 'a'-'z'.
        i++;
    }
}

int main() {
    char exampleStr[] = "Hello World! 123";
    std::cout << "Original: " << exampleStr << std::endl;
    strToUpper(exampleStr);
    std::cout << "Modified: " << exampleStr << std::endl; // Output will be incorrect, e.g., "HELLO WORLD! !@#"
    return 0;
}