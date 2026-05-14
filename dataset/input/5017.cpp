#include <iostream>
#include <cstring> // For strcmp to verify

// Function with robustness issues:
// 1. Does not check for nullptr source or destination.
// 2. Does not handle overlapping memory regions correctly (like standard strcpy).
void myStrcpy(char* dest, const char* src) {
    // If src or dest were nullptr, this would result in a crash (segmentation fault).
    // If src and dest overlap in a way that src is within dest,
    // data corruption can occur, as the source content is overwritten before being read.
    while (*dest++ = *src++);
}

int main() {
    std::cout << "--- Testing myStrcpy with Robustness Issues ---\n\n";

    // Test Case 1: Normal copy
    char dest1[50];
    const char* src1 = "Hello, World!";
    myStrcpy(dest1, src1);
    std::cout << "Test 1: Normal copy\n";
    std::cout << "  Source: \"" << src1 << "\"\n";
    std::cout << "  Dest:   \"" << dest1 << "\"\n";
    std::cout << "  Expected: \"" << src1 << "\"\n";
    std::cout << "  Result: " << (std::strcmp(dest1, src1) == 0 ? "PASS" : "FAIL") << "\n\n";

    // Test Case 2: Empty string
    char dest2[10];
    const char* src2 = "";
    myStrcpy(dest2, src2);
    std::cout << "Test 2: Empty string\n";
    std::cout << "  Source: \"" << src2 << "\"\n";
    std::cout << "  Dest:   \"" << dest2 << "\"\n";
    std::cout << "  Expected: \"" << src2 << "\"\n";
    std::cout << "  Result: " << (std::strcmp(dest2, src2) == 0 ? "PASS" : "FAIL") << "\n\n";

    // Test Case 3: Overlapping buffers (Demonstrates robustness issue)
    // This scenario leads to undefined behavior with strcpy-like implementations
    // when the source and destination overlap and the source starts within the destination.
    // E.g., copying "abcdefghijk" starting at buffer[0] to buffer[2]
    // The original 'c' at buffer[2] is overwritten by 'a' before 'c' can be copied to buffer[4].
    char buffer[20] = "abcdefghijk"; // Sufficiently long buffer
    const char* original_buffer_state = "abcdefghijk";
    myStrcpy(buffer + 2, buffer); // Copy "abcdefghijk" starting at buffer[2]
    std::cout << "Test 3: Overlapping buffers (Robustness Issue - Data Corruption)\n";
    std::cout << "  Original buffer: \"" << original_buffer_state << "\"\n";
    std::cout << "  Call: myStrcpy(buffer + 2, buffer)\n";
    std::cout << "  Dest (buffer):   \"" << buffer << "\"\n";
    // For a naive strcpy, the expected outcome for buffer = "abcdefghijk", myStrcpy(buffer + 2, buffer)
    // is "abababijk" (or similar, it's technically undefined behavior but this is a common result).
    const char* expected_overlap_result = "abababijk";
    std::cout << "  Expected (naive strcpy result): \"" << expected_overlap_result << "\"\n";
    std::cout << "  Result: " << (std::strcmp(buffer, expected_overlap_result) == 0 ? "PASS" : "FAIL") << "\n\n";

    // Test Case 4: Another normal copy
    char dest4[30];
    const char* src4 = "Another string 123.";
    myStrcpy(dest4, src4);
    std::cout << "Test 4: Another normal copy\n";
    std::cout << "  Source: \"" << src4 << "\"\n";
    std::cout << "  Dest:   \"" << dest4 << "\"\n";
    std::cout << "  Expected: \"" << src4 << "\"\n";
    std::cout << "  Result: " << (std::strcmp(dest4, src4) == 0 ? "PASS" : "FAIL") << "\n\n";

    // Note: The following test cases are commented out because they would cause a crash
    // due to nullptr dereference, demonstrating the robustness issue without terminating the program.
    /*
    // Test Case 5: Null source (Robustness Issue)
    std::cout << "Test 5: Null source (EXPECTED CRASH IF UNCOMMENTED)\n";
    char dest5[10];
    const char* src5_null = nullptr;
    // myStrcpy(dest5, src5_null); // This would crash the program
    // std::cout << "  (Skipped to prevent crash during automated testing)\n\n";

    // Test Case 6: Null destination (Robustness Issue)
    std::cout << "Test 6: Null destination (EXPECTED CRASH IF UNCOMMENTED)\n";
    char* dest6_null = nullptr;
    const char* src6_valid = "hello";
    // myStrcpy(dest6_null, src6_valid); // This would crash the program
    // std::cout << "  (Skipped to prevent crash during automated testing)\n\n";
    */

    return 0;
}