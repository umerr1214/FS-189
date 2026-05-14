#include <iostream> // For std::cout
#include <cstring>  // For strlen (used in main for setup, not in my_strcat_correct)

// Function to concatenate two C-style strings into a third
// This is the correct, efficient, and readable implementation.
// It assumes 'dest' is a pre-allocated buffer large enough to hold src1 + src2 + null terminator.
void my_strcat_correct(char* dest, const char* src1, const char* src2) {
    // Basic null pointer checks for robustness
    if (dest == nullptr) {
        // Handle error: destination buffer is null
        return;
    }
    if (src1 == nullptr) {
        src1 = ""; // Treat null src1 as an empty string
    }
    if (src2 == nullptr) {
        src2 = ""; // Treat null src2 as an empty string
    }

    int i = 0; // Index for dest and src1
    int j = 0; // Index for src2

    // Copy characters from src1 to dest
    while (src1[i] != '\0') {
        dest[i] = src1[i];
        i++;
    }

    // Append characters from src2 to dest, starting where src1 ended
    while (src2[j] != '\0') {
        dest[i + j] = src2[j];
        j++;
    }

    // Null-terminate the resulting string
    dest[i + j] = '\0';
}

int main() {
    // Test Case 1: Standard concatenation
    char buffer1[50];
    const char* s1_1 = "Hello";
    const char* s2_1 = "World";
    my_strcat_correct(buffer1, s1_1, s2_1);
    std::cout << "Test 1 (Normal): " << buffer1 << std::endl; // Expected: HelloWorld

    // Test Case 2: Empty first string
    char buffer2[50];
    const char* s1_2 = "";
    const char* s2_2 = "EmptyFirst";
    my_strcat_correct(buffer2, s1_2, s2_2);
    std::cout << "Test 2 (Empty src1): " << buffer2 << std::endl; // Expected: EmptyFirst

    // Test Case 3: Empty second string
    char buffer3[50];
    const char* s1_3 = "EmptySecond";
    const char* s2_3 = "";
    my_strcat_correct(buffer3, s1_3, s2_3);
    std::cout << "Test 3 (Empty src2): " << buffer3 << std::endl; // Expected: EmptySecond

    // Test Case 4: Both strings empty
    char buffer4[50];
    const char* s1_4 = "";
    const char* s2_4 = "";
    my_strcat_correct(buffer4, s1_4, s2_4);
    std::cout << "Test 4 (Both Empty): " << buffer4 << std::endl; // Expected: (empty string)

    // Test Case 5: Long strings
    char buffer5[150];
    const char* s1_5 = "ProgrammingIs";
    const char* s2_5 = "FunAndChallenging";
    my_strcat_correct(buffer5, s1_5, s2_5);
    std::cout << "Test 5 (Long strings): " << buffer5 << std::endl; // Expected: ProgrammingIsFunAndChallenging

    // Test Case 6: Null pointers (handled gracefully by treating as empty strings)
    char buffer6[50];
    const char* s1_6 = "Prefix";
    const char* s2_6 = nullptr;
    my_strcat_correct(buffer6, s1_6, s2_6);
    std::cout << "Test 6 (Null src2): " << buffer6 << std::endl; // Expected: Prefix

    return 0;
}