#include <iostream>
#include <cstring> // For strlen, strncat
#include <algorithm> // For std::min (though not strictly needed for this inefficiency example)

// Function with readability/efficiency issues:
// 1. Inefficient: Uses strncat twice. strncat itself scans the destination buffer
//    to find its current end. Calling it twice means the destination is scanned twice.
//    A more efficient approach would be to calculate total lengths once and use memcpy/strncpy
//    with explicit offsets, or a single loop.
// 2. Readability: While not terrible, the logic could be slightly more streamlined
//    by pre-calculating lengths and available space more explicitly.
void concatenateStrings(const char* str1, const char* str2, char* dest, size_t dest_size) {
    if (dest == nullptr || dest_size == 0) {
        return;
    }

    // Ensure initial null termination for safe strncat operation
    dest[0] = '\0';

    // First strncat call. It will scan 'dest' (which is '\0') to find its end.
    // It will then copy up to dest_size - 1 characters from str1.
    strncat(dest, str1, dest_size - 1);

    // Second strncat call. It will now scan 'dest' again (which contains str1)
    // to find its new end. This is an inefficient re-scan.
    // The third argument is the maximum number of characters from str2 to append.
    // It's calculated based on the current length of dest, and total dest_size.
    size_t current_len = strlen(dest); // This strlen is also a scan
    if (dest_size > current_len + 1) { // Ensure space for at least 1 char + null terminator
        strncat(dest, str2, dest_size - current_len - 1);
    }
    
    // Ensure null termination (strncat typically null terminates if it doesn't fill entirely,
    // but explicit termination at dest_size - 1 is safer for full buffer scenarios)
    dest[dest_size - 1] = '\0';
}

int main() {
    char buffer[20];
    char buffer_small[5];
    char buffer_exact[11];
    char buffer_tiny[1];

    std::cout << "--- Readability / Efficiency Issue Test Cases ---" << std::endl;

    // Test 1: Normal concatenation
    std::memset(buffer, '#', sizeof(buffer));
    concatenateStrings("Hello", "World", buffer, sizeof(buffer));
    std::cout << "Test 1 (Hello+World, size 20): " << buffer << std::endl; // Expected: HelloWorld

    // Test 2: Truncation of str2
    std::memset(buffer_small, '#', sizeof(buffer_small));
    concatenateStrings("ABCD", "E", buffer_small, sizeof(buffer_small));
    std::cout << "Test 2 (ABCD+E, size 5): " << buffer_small << std::endl; // Expected: ABCDE

    // Test 3: Truncation of str1
    std::memset(buffer_small, '#', sizeof(buffer_small));
    concatenateStrings("ABCDEF", "GH", buffer_small, sizeof(buffer_small));
    std::cout << "Test 3 (ABCDEF+GH, size 5): " << buffer_small << std::endl; // Expected: ABCD

    // Test 4: dest_size is 1
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