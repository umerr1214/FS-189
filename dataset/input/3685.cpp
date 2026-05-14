#include <iostream> // For std::cout, std::endl

// Function to concatenate strings with a robustness issue (buffer overflow).
// It does not take the destination buffer's capacity as an argument,
// leading to potential writes beyond its bounds if 'dest' is too small.
void customConcatenate(char* dest, const char* s1, const char* s2) {
    int i = 0;
    // Copy s1 to dest
    while (s1[i] != '\0') {
        dest[i] = s1[i];
        i++;
    }

    int j = 0;
    // Copy s2 to dest, starting after s1
    while (s2[j] != '\0') {
        // This is the robustness issue: no bounds checking on 'dest'.
        // If (i + j) exceeds the allocated size of 'dest', this will cause
        // a buffer overflow, leading to undefined behavior.
        dest[i + j] = s2[j];
        j++;
    }
    dest[i + j] = '\0'; // Null-terminate the result
}

int main() {
    // Example demonstrating the robustness issue: buffer overflow
    // A small buffer that will definitely overflow with longer strings
    char smallBuffer[20]; // Capacity for 19 characters + null terminator

    const char* strA = "Hello";
    const char* strB = "World";
    // Expected: "HelloWorld" (10 chars + null = 11 chars). Fits in smallBuffer.
    customConcatenate(smallBuffer, strA, strB);
    std::cout << "Test 1 (fits): '" << smallBuffer << "'" << std::endl;

    const char* strC = "This is a very long first part"; // 30 chars
    const char* strD = "and a second part!";             // 18 chars
    // Total needed: 30 + 18 + 1 = 49 characters.
    // smallBuffer (capacity 19) will overflow significantly.
    std::cout << "Test 2 (overflow expected - behavior undefined):" << std::endl;
    // Calling the function here will likely cause a buffer overflow.
    // The output might be corrupted, or the program might crash.
    customConcatenate(smallBuffer, strC, strD);
    std::cout << "Test 2 result (potentially corrupted): '" << smallBuffer << "'" << std::endl;

    // To prevent a crash in the general case for test drivers,
    // a sufficiently large buffer would be used for actual expected outputs.
    // The issue lies in the function's lack of safety, not necessarily in every call.
    char largeBuffer[100]; // Sufficiently large for typical test cases
    customConcatenate(largeBuffer, strC, strD);
    std::cout << "Test 3 (with large buffer): '" << largeBuffer << "'" << std::endl;

    return 0;
}