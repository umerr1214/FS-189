#include <iostream>
#include <cstring> // For strlen, strncpy, strncat
#include <algorithm> // For std::min (though not strictly used in the bug)

// Function with robustness issues:
// 1. Does not check if 'dest' is a nullptr.
// 2. Uses strncpy for the first string without guaranteeing null termination.
//    If str1 is longer than or equal to `dest_size - 1`, strncpy will fill
//    `dest` up to `dest_size - 1` characters, but will NOT null-terminate it.
//    This makes 'dest' an invalid C-string.
// 3. Subsequent call to `strlen` (to determine `current_len`) or `strncat`
//    on an unterminated 'dest' will lead to undefined behavior, as it scans
//    past the buffer boundary looking for a null terminator.
void concatenateStrings(const char* str1, const char* str2, char* dest, size_t dest_size) {
    // No nullptr check for dest, str1, str2 - assuming valid pointers as per common C-style string usage
    // but a truly robust function would check.

    if (dest_size == 0) {
        return; // Cannot write anything, not even null terminator
    }

    // --- ROBUSTNESS ISSUE HERE ---
    // strncpy copies at most dest_size - 1 characters from str1 to dest.
    // If strlen(str1) >= dest_size - 1, strncpy will NOT null-terminate dest.
    // Example: dest_size = 5, str1 = "ABCDE". strncpy copies "ABCD" to dest[0-3]. dest[4] is untouched.
    // dest is now "ABCD" followed by whatever was previously in dest[4], not '\0'.
    strncpy(dest, str1, dest_size - 1);
    // After this, dest might not be null-terminated.

    // --- SECOND PART OF ROBUSTNESS ISSUE ---
    // Calling strlen(dest) on a potentially non-null-terminated buffer is UNDEFINED BEHAVIOR.
    // It will read past the allocated buffer until it finds a '\0' or crashes.
    size_t current_len = strlen(dest); // !!! UB if dest is not null-terminated !!!

    // Calculate remaining space for str2 and the final null terminator.
    // This calculation is also flawed if current_len is wrong due to UB.
    size_t remaining_space = 0;
    if (dest_size > current_len + 1) { // Ensure there's at least one char space + null
        remaining_space = dest_size - current_len - 1;
    }

    // strncat appends at most 'remaining_space' characters from str2 to 'dest'.
    // It will also append a null terminator if it copies less than 'remaining_space' characters.
    // However, if 'dest' was not null-terminated to begin with, strncat's initial scan for
    // the end of 'dest' will also cause UB.
    if (remaining_space > 0) {
        strncat(dest, str2, remaining_space);
    }

    // Final manual null termination to try and recover, but the UB might have already happened.
    // This also might overwrite a character from str2 if str2 filled exactly `remaining_space`
    // and strncat didn't get a chance to null terminate itself.
    dest[dest_size - 1] = '\0';
}

int main() {
    // A driver for testing this specific robustness issue.
    // Note: Due to UB, actual output can vary. This demonstrates the potential failure.
    char buffer_small[5]; // Max 4 chars + '\0'
    char buffer_normal[20];
    char buffer_tiny[1];

    std::cout << "--- Robustness Issue Test Cases (potential UB) ---" << std::endl;

    // Test 1: str1 exactly fills dest_size-1. strncpy will NOT null terminate.
    // strlen(buffer_small) will cause UB.
    std::memset(buffer_small, 'X', sizeof(buffer_small)); // Fill with non-null
    concatenateStrings("ABCD", "E", buffer_small, sizeof(buffer_small));
    // Expected (if no UB crash): "ABCDE" or "ABCDX" or crash.
    std::cout << "Test 1 (str1=ABCD, str2=E, size=5): [" << buffer_small << "] (Expected: ABCDE, but UB likely)" << std::endl;

    // Test 2: str1 longer than dest_size-1. strncpy will NOT null terminate.
    std::memset(buffer_small, 'Y', sizeof(buffer_small));
    concatenateStrings("ABCDEF", "GH", buffer_small, sizeof(buffer_small));
    // Expected (if no UB crash): "ABCD" followed by garbage, but strncat would have failed.
    std::cout << "Test 2 (str1=ABCDEF, str2=GH, size=5): [" << buffer_small << "] (Expected: ABCD, but UB likely)" << std::endl;

    // Test 3: Normal case, where strncpy *does* null terminate.
    std::memset(buffer_normal, 'Z', sizeof(buffer_normal));
    concatenateStrings("Hello", "World", buffer_normal, sizeof(buffer_normal));
    std::cout << "Test 3 (str1=Hello, str2=World, size=20): [" << buffer_normal << "] (Expected: HelloWorld)" << std::endl;

    // Test 4: dest_size is 1 (only null terminator possible).
    // strncpy(dest, str1, 0) copies nothing. strlen(dest) is UB if dest[0] is not null.
    std::memset(buffer_tiny, 'T', sizeof(buffer_tiny));
    concatenateStrings("A", "B", buffer_tiny, sizeof(buffer_tiny));
    std::cout << "Test 4 (str1=A, str2=B, size=1): [" << buffer_tiny << "] (Expected: )" << std::endl; // Should be empty string

    // Test 5: Empty str1, non-empty str2. strncpy copies nothing, dest[0] is potentially not null.
    std::memset(buffer_small, 'W', sizeof(buffer_small));
    concatenateStrings("", "World", buffer_small, sizeof(buffer_small));
    std::cout << "Test 5 (str1=, str2=World, size=5): [" << buffer_small << "] (Expected: Worl)" << std::endl; // truncated

    return 0;
}