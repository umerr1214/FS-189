#include <iostream>
#include <cstring> // For strlen
#include <algorithm> // For std::swap

char* reverse_cstring(char* str) {
    if (str == nullptr) {
        return nullptr;
    }
    int length = std::strlen(str);
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return str;
}

int main() {
    // Semantic Error: Attempting to modify a string literal.
    // String literals are typically stored in read-only memory.
    // Assigning a string literal to 'char*' requires a cast in C++11 and later,
    // and attempting to modify it leads to undefined behavior (often a segmentation fault).
    char* s1 = (char*)"hello"; // Casting to char* to compile, but causes UB at runtime
    std::cout << "Original: " << s1 << ", Reversed: ";
    char* reversed_s1 = reverse_cstring(s1); // This line attempts to modify read-only memory
    std::cout << reversed_s1 << std::endl; // Likely crashes here

    char s2_arr[] = "world"; // This is a modifiable character array, so it's fine.
    std::cout << "Original: " << s2_arr << ", Reversed: " << reverse_cstring(s2_arr) << std::endl;
    
    char* s3 = (char*)"test"; // Another string literal leading to UB
    std::cout << "Original: " << s3 << ", Reversed: ";
    char* reversed_s3 = reverse_cstring(s3);
    std::cout << reversed_s3 << std::endl;

    char s4_arr[] = ""; // Modifiable empty array, fine.
    std::cout << "Original: " << s4_arr << ", Reversed: " << reverse_cstring(s4_arr) << std::endl;

    return 0;
}