#include <iostream>

// Function declaration with a syntax error: 'vodi' instead of 'void'
vodi strConcatenate(char* dest, const char* src) {
    int dest_len = 0;
    while (dest[dest_len] != '\0') {
        dest_len++;
    }

    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0'; // Null-terminate the new string
}

int main() {
    char buffer1[100] = "Hello";
    const char* src1 = " World";
    strConcatenate(buffer1, src1);
    std::cout << "Test 1 Output: \"" << buffer1 << "\"" << std::endl; // Expected: "Hello World"

    char buffer2[100] = "First";
    const char* src2 = " Second";
    strConcatenate(buffer2, src2);
    std::cout << "Test 2 Output: \"" << buffer2 << "\"" << std::endl; // Expected: "First Second"

    char buffer3[100] = "Base";
    const char* src3 = "";
    strConcatenate(buffer3, src3);
    std::cout << "Test 3 Output: \"" << buffer3 << "\"" << std::endl; // Expected: "Base"

    char buffer4[100] = "";
    const char* src4 = "Append";
    strConcatenate(buffer4, src4);
    std::cout << "Test 4 Output: \"" << buffer4 << "\"" << std::endl; // Expected: "Append"

    return 0;
}