#include <iostream>
#include <cstring> // For strcpy, strcat, strlen

// This function contains a semantic error: it uses strcpy and strcat without
// proper bounds checking, leading to potential buffer overflow (undefined behavior).
void concatenateStrings(const char* str1, const char* str2, char* dest, int destSize) {
    if (destSize <= 0 || !dest) {
        return;
    }
    
    // Ensure the destination is null-terminated initially
    if (destSize > 0) {
        dest[0] = '\0';
    }

    // Semantic Error: Using strcpy without checking if strlen(str1) < destSize.
    // This can lead to buffer overflow if str1 is too long.
    // Even if str1 fits, it doesn't leave space for str2 or the null terminator.
    strcpy(dest, str1);

    // Semantic Error: Using strcat without checking if strlen(dest) + strlen(str2) + 1 < destSize.
    // This is a classic buffer overflow vulnerability. The function will write past
    // the end of 'dest' if the combined length exceeds 'destSize'.
    strcat(dest, str2);

    // Attempt to null terminate, but it might be too late if overflow already occurred
    // and destSize was exceeded. Also, if destSize is 0 or 1, this will try to write
    // past the buffer.
    if (destSize > 0) {
        dest[destSize - 1] = '\0'; // This attempts to null terminate, but if overflow happened before,
                                   // it might not fix the problem or might overwrite a valid character.
                                   // Also, it might cut off a valid character if the string perfectly fits.
    }
}

int main() {
    char buffer[20];

    // Test Case 1
    concatenateStrings("Hello", "World", buffer, sizeof(buffer));
    std::cout << "Test 1: " << buffer << std::endl; // Expected: HelloWorld, Actual: HelloWorld (might work if buffer is large enough)

    // Test Case 2 (Truncation/Overflow - depends on environment)
    char buffer2[5];
    concatenateStrings("One", "Two", buffer2, sizeof(buffer2));
    std::cout << "Test 2: " << buffer2 << std::endl; // Expected: OneT, Actual: Undefined behavior (likely overflow)

    // Test Case 3 (Empty str1)
    char buffer3[10];
    concatenateStrings("", "Test", buffer3, sizeof(buffer3));
    std::cout << "Test 3: " << buffer3 << std::endl; // Expected: Test, Actual: Test (might work)

    // Test Case 4 (Empty str2)
    char buffer4[10];
    concatenateStrings("Test", "", buffer4, sizeof(buffer4));
    std::cout << "Test 4: " << buffer4 << std::endl; // Expected: Test, Actual: Test (might work)

    // Test Case 5 (Buffer too small for anything)
    char buffer5[1];
    concatenateStrings("Long", "String", buffer5, sizeof(buffer5));
    std::cout << "Test 5: " << buffer5 << std::endl; // Expected: , Actual: Undefined behavior (likely overflow immediately)

    // Test Case 6 (str1 fills buffer, str2 causes overflow)
    char buffer6[10]; // Max 9 chars + null
    concatenateStrings("ABCDEFGHI", "J", buffer6, sizeof(buffer6));
    std::cout << "Test 6: " << buffer6 << std::endl; // Expected: ABCDEFGHI, Actual: Undefined behavior (strcat overflows)

    // Test Case 7 (str1 + str2 exceeds buffer slightly)
    char buffer7[10];
    concatenateStrings("Hello", "World", buffer7, sizeof(buffer7));
    std::cout << "Test 7: " << buffer7 << std::endl; // Expected: HelloWorl, Actual: Undefined behavior (strcat overflows)

    return 0;
}