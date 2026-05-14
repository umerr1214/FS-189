#include <iostream> // For std::cout
#include <cstring>  // For strlen (used in main for setup, not in my_strcat)

// Function to concatenate two C-style strings into a third
// This version has a robustness issue: it does not check if 'dest' is large enough,
// leading to a buffer overflow if the combined length of src1 and src2 exceeds dest's capacity.
void my_strcat(char* dest, const char* src1, const char* src2) {
    if (dest == nullptr || src1 == nullptr || src2 == nullptr) {
        // Basic null pointer check, but doesn't prevent buffer overflow if dest is valid but too small
        return;
    }

    int i = 0;
    int j = 0;

    // Copy src1 to dest
    while (src1[i] != '\0') {
        dest[i] = src1[i];
        i++;
    }

    // Append src2 to dest starting from the end of src1 in dest
    // This loop will write past the allocated memory for dest if it's too small
    while (src2[j] != '\0') {
        dest[i + j] = src2[j];
        j++;
    }

    // Null-terminate the resulting string
    // This is the character that will cause an overflow if dest was precisely sized for (src1+src2)
    dest[i + j] = '\0';
}

int main() {
    // Test Case 1: Normal operation, dest buffer is sufficiently large
    char buffer1[50];
    const char* s1_1 = "Hello";
    const char* s2_1 = "World";
    my_strcat(buffer1, s1_1, s2_1);
    std::cout << "Test 1 (Normal): " << buffer1 << std::endl; // Expected: HelloWorld

    // Test Case 2: Buffer overflow scenario
    // Combined length of "Overflow" (8) + "Test" (4) = 12.
    // A buffer of size 12 can hold "OverflowTest" but not the null terminator.
    // The null terminator will write one byte past the allocated memory.
    char buffer2[12]; // Intentionally too small by 1 byte for null terminator
    const char* s1_2 = "Overflow";
    const char* s2_2 = "Test";
    my_strcat(buffer2, s1_2, s2_2);
    // The output might appear correct, but a buffer overflow has occurred.
    std::cout << "Test 2 (Overflow): " << buffer2 << std::endl; // Expected: OverflowTest (with overflow)

    // Test Case 3: Empty first string
    char buffer3[50];
    const char* s1_3 = "";
    const char* s2_3 = "EmptyFirst";
    my_strcat(buffer3, s1_3, s2_3);
    std::cout << "Test 3 (Empty src1): " << buffer3 << std::endl; // Expected: EmptyFirst

    // Test Case 4: Empty second string
    char buffer4[50];
    const char* s1_4 = "EmptySecond";
    const char* s2_4 = "";
    my_strcat(buffer4, s1_4, s2_4);
    std::cout << "Test 4 (Empty src2): " << buffer4 << std::endl; // Expected: EmptySecond

    return 0;
}