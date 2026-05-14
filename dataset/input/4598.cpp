#include <iostream> // For std::cout
#include <cstring>  // For strlen (used in main for setup, not in my_strcat_inefficient)

// Function to concatenate two C-style strings into a third
// This version demonstrates an efficiency issue by repeatedly scanning the destination
// string to find its current end, making the operation O(N*M) instead of O(N+M).
void my_strcat_inefficient(char* dest, const char* src1, const char* src2) {
    if (dest == nullptr || src1 == nullptr || src2 == nullptr) {
        return;
    }

    int i = 0;
    // Copy src1 to dest
    while (src1[i] != '\0') {
        dest[i] = src1[i];
        i++;
    }
    dest[i] = '\0'; // Temporarily null-terminate after src1 (this is okay)

    // Append src2. This part is inefficient.
    // For each character of src2, it re-scans dest to find its current end.
    int k = 0;
    while (src2[k] != '\0') {
        // Find the current end of dest for *each character* of src2
        int current_dest_len = 0;
        while (dest[current_dest_len] != '\0') {
            current_dest_len++;
        }
        dest[current_dest_len] = src2[k];
        k++;
    }

    // After appending all characters, find the final end and null-terminate.
    // This final scan is also redundant if the previous loop managed the null terminator.
    int final_dest_len = 0;
    while (dest[final_dest_len] != '\0') {
        final_dest_len++;
    }
    dest[final_dest_len] = '\0';
}

int main() {
    // Test Case 1: Normal operation
    char buffer1[100];
    const char* s1_1 = "Hello";
    const char* s2_1 = "World";
    my_strcat_inefficient(buffer1, s1_1, s2_1);
    std::cout << "Test 1 (Normal): " << buffer1 << std::endl; // Expected: HelloWorld

    // Test Case 2: Long strings to highlight inefficiency
    char buffer2[200];
    const char* s1_2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; // 50 'a's
    const char* s2_2 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"; // 50 'b's
    my_strcat_inefficient(buffer2, s1_2, s2_2);
    std::cout << "Test 2 (Long strings): " << buffer2 << std::endl; // Expected: 100 chars (50a + 50b)

    // Test Case 3: Empty first string
    char buffer3[100];
    const char* s1_3 = "";
    const char* s2_3 = "EmptyFirst";
    my_strcat_inefficient(buffer3, s1_3, s2_3);
    std::cout << "Test 3 (Empty src1): " << buffer3 << std::endl; // Expected: EmptyFirst

    // Test Case 4: Empty second string
    char buffer4[100];
    const char* s1_4 = "EmptySecond";
    const char* s2_4 = "";
    my_strcat_inefficient(buffer4, s1_4, s2_4);
    std::cout << "Test 4 (Empty src2): " << buffer4 << std::endl; // Expected: EmptySecond

    return 0;
}