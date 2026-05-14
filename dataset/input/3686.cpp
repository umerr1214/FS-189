#include <iostream> // For std::cout, std::endl

// Function to concatenate strings with an efficiency and readability issue.
// It re-iterates over the destination buffer to find the insertion point
// for the second string, which is redundant.
void concatenate_strings_inefficient(char* target_buffer, const char* source_one, const char* source_two) {
    // First, copy source_one to target_buffer using an index.
    int i = 0;
    while (source_one[i] != '\0') {
        target_buffer[i] = source_one[i];
        i++;
    }
    // At this point, 'i' holds the length of source_one and is the correct
    // starting index for source_two.

    // Efficiency issue: Instead of directly using 'i', the code re-iterates
    // from the beginning of target_buffer to find the null terminator again.
    char* current_dest_ptr = target_buffer;
    while (*current_dest_ptr != '\0') { // This loop is redundant and inefficient
        current_dest_ptr++;
    }

    // Now copy source_two using pointer arithmetic.
    const char* current_src2_ptr = source_two;
    while (*current_src2_ptr != '\0') {
        *current_dest_ptr = *current_src2_ptr;
        current_dest_ptr++;
        current_src2_ptr++;
    }
    *current_dest_ptr = '\0'; // Null-terminate the result
}

int main() {
    char buffer[100]; // Assume sufficient buffer size for test cases

    // Test cases
    const char* s1_1 = "Hello";
    const char* s2_1 = "World";
    concatenate_strings_inefficient(buffer, s1_1, s2_1);
    std::cout << "Test 1: '" << buffer << "'" << std::endl; // Expected: HelloWorld

    const char* s1_2 = "C++";
    const char* s2_2 = "Programming";
    concatenate_strings_inefficient(buffer, s1_2, s2_2);
    std::cout << "Test 2: '" << buffer << "'" << std::endl; // Expected: C++Programming

    const char* s1_3 = "";
    const char* s2_3 = "EmptyFirst";
    concatenate_strings_inefficient(buffer, s1_3, s2_3);
    std::cout << "Test 3: '" << buffer << "'" << std::endl; // Expected: EmptyFirst

    const char* s1_4 = "FirstOnly";
    const char* s2_4 = "";
    concatenate_strings_inefficient(buffer, s1_4, s2_4);
    std::cout << "Test 4: '" << buffer << "'" << std::endl; // Expected: FirstOnly

    return 0;
}