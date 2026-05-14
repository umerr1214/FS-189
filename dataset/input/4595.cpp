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
    // LOGICAL ERROR: Missing null termination here.
    // The concatenated string will not be properly null-terminated,
    // leading to undefined behavior when printed or processed further.
    // dest[i + j] = '\0'; // This line is intentionally omitted
}

int main() {
    std::string s1_str, s2_str;
    std::cout << "Enter first string: ";
    std::getline(std::cin, s1_str);
    std::cout << "Enter second string: ";
    std::getline(std::cin, s2_str);

    const int MAX_LEN = 200; // Sufficiently large buffer for most inputs
    char str1_arr[MAX_LEN];
    char str2_arr[MAX_LEN];
    char result_arr[MAX_LEN * 2]; // Buffer for concatenated string

    // Copy std::string to char array, ensuring null termination
    std::strncpy(str1_arr, s1_str.c_str(), MAX_LEN - 1);
    str1_arr[MAX_LEN - 1] = '\0';
    std::strncpy(str2_arr, s2_str.c_str(), MAX_LEN - 1);
    str2_arr[MAX_LEN - 1] = '\0';

    // Initialize result_arr to ensure a clean state and make the logical error visible
    for(int k=0; k < MAX_LEN * 2; ++k) result_arr[k] = '\0';

    myStrcat(result_arr, str1_arr, str2_arr);

    std::cout << "Concatenated: " << result_arr << std::endl;

    return 0;
}