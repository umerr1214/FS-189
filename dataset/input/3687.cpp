#include <iostream> // For std::cout, std::endl

// Function to concatenate two C-style strings into a third.
// Assumes 'dest' has enough allocated memory to hold s1 + s2 + null terminator.
// This version is clear, efficient, and correct for its purpose.
void customConcatenate_correct(char* dest, const char* s1, const char* s2) {
    int i = 0;
    // Copy s1 to dest
    while (s1[i] != '\0') {
        dest[i] = s1[i];
        i++;
    }

    int j = 0;
    // Copy s2 to dest, starting from where s1 ended (at index i)
    while (s2[j] != '\0') {
        dest[i + j] = s2[j];
        j++;
    }
    dest[i + j] = '\0'; // Null-terminate the result
}

int main() {
    char buffer[100]; // Sufficient buffer size for all test cases

    // Test cases
    const char* s1_1 = "Hello";
    const char* s2_1 = "World";
    customConcatenate_correct(buffer, s1_1, s2_1);
    std::cout << "Test 1: '" << buffer << "'" << std::endl; // Expected: HelloWorld

    const char* s1_2 = "C++";
    const char* s2_2 = "Programming";
    customConcatenate_correct(buffer, s1_2, s2_2);
    std::cout << "Test 2: '" << buffer << "'" << std::endl; // Expected: C++Programming

    const char* s1_3 = "";
    const char* s2_3 = "EmptyFirst";
    customConcatenate_correct(buffer, s1_3, s2_3);
    std::cout << "Test 3: '" << buffer << "'" << std::endl; // Expected: EmptyFirst

    const char* s1_4 = "FirstOnly";
    const char* s2_4 = "";
    customConcatenate_correct(buffer, s1_4, s2_4);
    std::cout << "Test 4: '" << buffer << "'" << std::endl; // Expected: FirstOnly

    const char* s1_5 = "LongStringExample";
    const char* s2_5 = "AnotherLongStringExample";
    customConcatenate_correct(buffer, s1_5, s2_5);
    std::cout << "Test 5: '" << buffer << "'" << std::endl; // Expected: LongStringExampleAnotherLongStringExample

    return 0;
}