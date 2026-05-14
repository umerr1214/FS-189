#include <iostream>
#include <cstring> // For strlen

// This function contains a syntax error
void concatenateStrings(const char* str1, const char* str2, char* dest, int destSize { // Missing ')' here
    if (destSize <= 0 || !dest) {
        return;
    }
    
    // Ensure the destination is null-terminated initially
    if (destSize > 0) {
        dest[0] = '\0';
    }

    int currentDestLen = 0;
    int i = 0;

    // Copy str1
    while (str1[i] != '\0' && currentDestLen < destSize - 1) {
        dest[currentDestLen] = str1[i];
        currentDestLen++;
        i++;
    }
    dest[currentDestLen] = '\0'; // Null terminate after str1

    // Reset i for str2
    i = 0;
    // Copy str2
    while (str2[i] != '\0' && currentDestLen < destSize - 1) {
        dest[currentDestLen] = str2[i];
        currentDestLen++;
        i++;
    }
    dest[currentDestLen] = '\0'; // Final null termination
}

int main() {
    char buffer[20];

    // Test Case 1
    concatenateStrings("Hello", "World", buffer, sizeof(buffer));
    std::cout << "Test 1: " << buffer << std::endl; // Expected: HelloWorld

    // Test Case 2 (Truncation)
    char buffer2[5];
    concatenateStrings("One", "Two", buffer2, sizeof(buffer2));
    std::cout << "Test 2: " << buffer2 << std::endl; // Expected: OneT

    // Test Case 3 (Empty str1)
    char buffer3[10];
    concatenateStrings("", "Test", buffer3, sizeof(buffer3));
    std::cout << "Test 3: " << buffer3 << std::endl; // Expected: Test

    // Test Case 4 (Empty str2)
    char buffer4[10];
    concatenateStrings("Test", "", buffer4, sizeof(buffer4));
    std::cout << "Test 4: " << buffer4 << std::endl; // Expected: Test

    // Test Case 5 (Buffer too small for anything)
    char buffer5[1];
    concatenateStrings("Long", "String", buffer5, sizeof(buffer5));
    std::cout << "Test 5: " << buffer5 << std::endl; // Expected: (empty string)

    // Test Case 6 (str1 fills buffer, str2 is ignored)
    char buffer6[10];
    concatenateStrings("LongString", "More", buffer6, sizeof(buffer6));
    std::cout << "Test 6: " << buffer6 << std::endl; // Expected: LongString

    return 0;
}