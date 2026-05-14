#include <iostream>
#include <string>
#include <cstring> // For strncpy

// Function to calculate string length without using standard library functions
int myStrlen(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to concatenate two C-style strings into a third without using standard library functions
void myStrcat(char* dest, const char* src1, const char* src2) {
    int i = 0;
    int j = 0;

    // Copy src1 to dest
    while (src1[i] != '\0') {
        dest[i] = src1[i];
        i++;
    }

    // Copy src2 to dest after src1
    while (src2[j] != '\0') {
        dest[i + j] = src2[j];
        j++;
    }
    dest[i + j] = '\0'; // Null-terminate the result
}

int main() {
    std::string s1_str, s2_str;
    std::cout << "Enter first string: ";
    std::getline(std::cin, s1_str);
    std::cout << "Enter second string: ";
    std::getline(std::cin, s2_str);

    const int MAX_INPUT_LEN = 200;
    char str1_arr[MAX_INPUT_LEN];
    char str2_arr[MAX_INPUT_LEN];

    std::strncpy(str1_arr, s1_str.c_str(), MAX_INPUT_LEN - 1);
    str1_arr[MAX_INPUT_LEN - 1] = '\0';
    std::strncpy(str2_arr, s2_str.c_str(), MAX_INPUT_LEN - 1);
    str2_arr[MAX_INPUT_LEN - 1] = '\0';

    // SEMANTIC ERROR: The 'result_arr' buffer is intentionally made too small.
    // If the combined length of str1_arr and str2_arr exceeds this,
    // myStrcat will write beyond the allocated memory, leading to a buffer overflow
    // and undefined behavior at runtime.
    const int SMALL_BUFFER_SIZE = 15; // Example: "Hello World!" is 12 chars + null = 13.
                                     // If input is longer, this will overflow.
    char result_arr[SMALL_BUFFER_SIZE];

    // Initialize result_arr to ensure a clean state (though overflow will corrupt it)
    for(int k=0; k < SMALL_BUFFER_SIZE; ++k) result_arr[k] = '\0';

    myStrcat(result_arr, str1_arr, str2_arr); // This call can cause buffer overflow

    std::cout << "Concatenated: " << result_arr << std::endl;

    return 0;
}