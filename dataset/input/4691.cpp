#include <iostream>

void strConcatenate(char* dest, const char* src) {
    int dest_len = 0;
    while (dest[dest_len] != '\0') {
        dest_len++;
    }

    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    // Logical error: Missing null-terminator.
    // The concatenated string will not be properly null-terminated,
    // leading to undefined behavior when printed or used by other string functions.
    // Correct line would be: dest[dest_len + i] = '\0';
}

int main() {
    char buffer1[100] = "Hello";
    const char* src1 = " World";
    strConcatenate(buffer1, src1);
    std::cout << "Test 1 Output: \"" << buffer1 << "\"" << std::endl; // Expected: "Hello World" (but will likely print more or garbage)

    char buffer2[100] = "First";
    const char* src2 = " Second";
    strConcatenate(buffer2, src2);
    std::cout << "Test 2 Output: \"" << buffer2 << "\"" << std::endl; // Expected: "First Second" (but will likely print more or garbage)

    char buffer3[100] = "Base";
    const char* src3 = "";
    strConcatenate(buffer3, src3);
    std::cout << "Test 3 Output: \"" << buffer3 << "\"" << std::endl; // Expected: "Base" (might be correct if there's a pre-existing null)

    char buffer4[100] = "";
    const char* src4 = "Append";
    strConcatenate(buffer4, src4);
    std::cout << "Test 4 Output: \"" << buffer4 << "\"" << std::endl; // Expected: "Append" (but will likely print more or garbage)

    return 0;
}