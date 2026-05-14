#include <iostream>
#include <cstring> // For strlen, memcpy
#include <algorithm> // For std::min

// Correct and efficient implementation of concatenateStrings
void concatenateStrings(const char* str1, const char* str2, char* dest, size_t dest_size) {
    // Robustness: Check for null pointers for destination buffer.
    // (str1 and str2 are assumed to be valid C-style strings as per common usage,
    // but a truly paranoid function might check those too.)
    if (dest == nullptr) {
        return;
    }

    // Edge case: If dest_size is 0, no characters (not even null terminator) can be written.
    if (dest_size == 0) {
        return;
    }

    // Ensure at least space for null terminator.
    // If dest_size is 1, only '\0' can be written.
    if (dest_size == 1) {
        dest[0] = '\0';
        return;
    }

    // Calculate lengths once for efficiency
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    size_t current_dest_len = 0;

    // Copy str1
    // Number of characters to copy from str1 is limited by its length and remaining buffer space (-1 for null terminator)
    size_t chars_to_copy_str1 = std::min(len1, dest_size - 1);
    memcpy(dest, str1, chars_to_copy_str1);
    current_dest_len += chars_to_copy_str1;

    // Copy str2
    // Remaining space for str2 is dest_size - current_dest_len - 1 (for null terminator)
    size_t remaining_space_for_str2 = dest_size - current_dest_len - 1;
    size_t chars_to_copy_str2 = std::min(len2, remaining_space_for_str2);
    memcpy(dest + current_dest_len, str2, chars_to_copy_str2);
    current_dest_len += chars_to_copy_str2;

    // Ensure null termination
    dest[current_dest_len] = '\0';
}

int main() {
    char buffer[20];
    char buffer_small[5];
    char buffer_exact[11]; // "FirstSecond" + null = 11 chars
    char buffer_tiny[1]; // Only for null terminator

    std::cout << "--- Correct Version Test Cases ---" << std::endl;

    // Test 1: Normal concatenation
    std::memset(buffer, '#', sizeof(buffer));
    concatenateStrings("Hello", "World", buffer, sizeof(buffer));
    std::cout << "Test 1 (Hello+World, size 20): " << buffer << std::endl; // Expected: HelloWorld

    // Test 2: Truncation of str2
    std::memset(buffer_small, '#', sizeof(buffer_small));
    concatenateStrings("ABCD", "E", buffer_small, sizeof(buffer_small));
    std::cout << "Test 2 (ABCD+E, size 5): " << buffer_small << std::endl; // Expected: ABCDE

    // Test 3: Truncation of str1 (str1 is too long, str2 won't fit)
    std::memset(buffer_small, '#', sizeof(buffer_small));
    concatenateStrings("ABCDEF", "GH", buffer_small, sizeof(buffer_small));
    std::cout << "Test 3 (ABCDEF+GH, size 5): " << buffer_small << std::endl; // Expected: ABCD

    // Test 4: dest_size is 1 (only null terminator possible)
    std::memset(buffer_tiny, '#', sizeof(buffer_tiny));
    concatenateStrings("A", "B", buffer_tiny, sizeof(buffer_tiny));
    std::cout << "Test 4 (A+B, size 1): [" << buffer_tiny << "]" << std::endl; // Expected: ""

    // Test 5: Exact fit
    std::memset(buffer_exact, '#', sizeof(buffer_exact));
    concatenateStrings("First", "Second", buffer_exact, sizeof(buffer_exact));
    std::cout << "Test 5 (First+Second, size 11): " << buffer_exact << std::endl; // Expected: FirstSecond

    // Test 6: Empty strings
    std::memset(buffer, '#', sizeof(buffer));
    concatenateStrings("", "", buffer, sizeof(buffer));
    std::cout << "Test 6 (+, size 20): " << buffer << std::endl; // Expected: ""

    // Test 7: Empty str1
    std::memset(buffer, '#', sizeof(buffer));
    concatenateStrings("", "OnlySecond", buffer, sizeof(buffer));
    std::cout << "Test 7 (+OnlySecond, size 20): " << buffer << std::endl; // Expected: OnlySecond

    // Test 8: Empty str2
    std::memset(buffer, '#', sizeof(buffer));
    concatenateStrings("OnlyFirst", "", buffer, sizeof(buffer));
    std::cout << "Test 8 (OnlyFirst+, size 20): " << buffer << std::endl; // Expected: OnlyFirst

    // Test 9: str1 + str2 combined length is exactly dest_size - 1
    std::memset(buffer_exact, '#', sizeof(buffer_exact)); // size 11
    concatenateStrings("12345", "67890", buffer_exact, sizeof(buffer_exact)); // 5+5=10. size 11 allows 10 chars + null
    std::cout << "Test 9 (12345+67890, size 11): " << buffer_exact << std::endl; // Expected: 1234567890

    // Test 10: str1 + str2 combined length is dest_size - 1, but str1 takes up too much.
    std::memset(buffer_exact, '#', sizeof(buffer_exact)); // size 11
    concatenateStrings("123456789", "0123", buffer_exact, sizeof(buffer_exact)); // 9 chars from str1, 1 char from str2
    std::cout << "Test 10 (123456789+0123, size 11): " << buffer_exact << std::endl; // Expected: 1234567890

    return 0;
}