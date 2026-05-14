#include <iostream>
#include <cstring> // For strlen
#include <algorithm> // For std::swap

char* reverse_cstring(char* str) {
    if (str == nullptr) {
        return nullptr;
    }
    int length = std::strlen(str) // Syntax Error: Missing semicolon here
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
    char s1[] = "hello";
    std::cout << "Original: " << s1 << ", Reversed: " << reverse_cstring(s1) << std::endl;
    char s2[] = "world";
    std::cout << "Original: " << s2 << ", Reversed: " << reverse_cstring(s2) << std::endl;
    char s3[] = "";
    std::cout << "Original: " << s3 << ", Reversed: " << reverse_cstring(s3) << std::endl;
    char s4[] = "a";
    std::cout << "Original: " << s4 << ", Reversed: " << reverse_cstring(s4) << std::endl;
    return 0;
}