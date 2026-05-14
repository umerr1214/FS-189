#include <iostream>
#include <cstring> // For strlen
#include <algorithm> // For std::swap

char* reverse_cstring(char* str) {
    if (str == nullptr) {
        return nullptr;
    }
    int length = std::strlen(str);
    int start = 0;
    int end = length; // Logical Error: 'end' should be length - 1 to exclude the null terminator
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
    char s1[] = "hello"; // Expected: olleh, Actual: "" (due to null terminator being moved)
    std::cout << "Original: " << s1 << ", Reversed: " << reverse_cstring(s1) << std::endl;
    char s2[] = "world"; // Expected: dlrow, Actual: ""
    std::cout << "Original: " << s2 << ", Reversed: " << reverse_cstring(s2) << std::endl;
    char s3[] = ""; // Expected: "", Actual: "" (correct, loop not entered)
    std::cout << "Original: " << s3 << ", Reversed: " << reverse_cstring(s3) << std::endl;
    char s4[] = "a"; // Expected: a, Actual: ""
    std::cout << "Original: " << s4 << ", Reversed: " << reverse_cstring(s4) << std::endl;
    char s5[] = "ab"; // Expected: ba, Actual: ""
    std::cout << "Original: " << s5 << ", Reversed: " << reverse_cstring(s5) << std::endl;
    return 0;
}