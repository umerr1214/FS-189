#include <iostream>
#include <cstring> // For strlen

// This function contains a logical error: it doesn't correctly manage available space for str2,
// potentially leading to incorrect truncation or not copying str2 fully when space is available.
// Specifically, it calculates remaining space for str2 based on destSize - 1, but doesn't
// subtract the length of str1 already copied.
void concatenateStrings(const char* str1, const char* str2, char* dest, int destSize) {
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
    // Logical Error: The loop condition for str2 uses destSize - 1 as its limit,
    // which is incorrect. It should be destSize - currentDestLen - 1 to
    // account for space already taken by str1 and the final null terminator.
    // This will lead to str2 being truncated too early if str1 is short,
    // or not copied at all if str1 is long.
    while (str2[i] != '\0' && i < destSize - 1) { // Incorrect condition for str2
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
    std::cout << "Test 1: " << buffer << std::endl; // Expected: HelloWorld, Actual: HelloWorld (works by chance)

    // Test Case 2 (Truncation)
    char buffer2[5];
    concatenateStrings("One", "Two", buffer2, sizeof(buffer2));
    std::cout << "Test 2: " << buffer2 << std::endl; // Expected: OneT, Actual: One (str2 not copied due to i < destSize - 1 which is 4)

    // Test Case 3 (Empty str1)
    char buffer3[10];
    concatenateStrings("", "Test", buffer3, sizeof(buffer3));
    std::cout << "Test 3: " << buffer3 << std::endl; // Expected: Test, Actual: Test (works)

    // Test Case 4 (Empty str2)
    char buffer4[10];
    concatenateStrings("Test", "", buffer4, sizeof(buffer4));
    std::cout << "Test 4: " << buffer4 << std::endl; // Expected: Test, Actual: Test (works)

    // Test Case 5 (Buffer too small for anything)
    char buffer5[1];
    concatenateStrings("Long", "String", buffer5, sizeof(buffer5));
    std::cout << "Test 5: " << buffer5 << std::endl; // Expected: , Actual: (works)

    // Test Case 6 (str1 fills buffer, str2 is ignored)
    char buffer6[10];
    concatenateStrings("LongString", "More", buffer6, sizeof(buffer6));
    std::cout << "Test 6: " << buffer6 << std::endl; // Expected: LongString, Actual: LongString (works)
    
    // Test Case 7 (str1 is short, str2 is long, exposes logical error)
    char buffer7[10];
    concatenateStrings("A", "BBBBBBBBB", buffer7, sizeof(buffer7));
    std::cout << "Test 7: " << buffer7 << std::endl; // Expected: ABBBBBBBB, Actual: A (str2 not copied due to i < destSize - 1 being 9)

    return 0;
}