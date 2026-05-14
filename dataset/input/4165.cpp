#include <iostream>
#include <string> // Included for clarity, though not directly used by getLarger for char*

// Function template to get the larger of two comparable values
template <typename T>
T getLarger(T val1, T val2) {
    return val1 > val2 ? val1 : val2;
}

int main() {
    // Demonstrate with int
    int int1 = 10;
    int int2 = 25;
    std::cout << "Larger of " << int1 << " and " << int2 << ": " << getLarger(int1, int2) << std::endl; // Expected: 25

    // Demonstrate with double
    double double1 = 3.14;
    double double2 = 2.718;
    std::cout << "Larger of " << double1 << " and " << double2 << ": " << getLarger(double1, double2) << std::endl; // Expected: 3.14

    // Demonstrate with C-style strings (char*) - Robustness Issue
    // This will compare pointer addresses, not lexicographical string content.
    // The actual output depends on where the compiler places these string literals in memory.
    const char* str1 = "apple";
    const char* str2 = "banana";
    std::cout << "Larger of \"" << str1 << "\" and \"" << str2 << "\": " << getLarger(str1, str2) << std::endl; // Output will be either "apple" or "banana" based on address comparison

    const char* str3 = "zebra";
    const char* str4 = "aardvark";
    std::cout << "Larger of \"" << str3 << "\" and \"" << str4 << "\": " << getLarger(str3, str4) << std::endl; // Output will be either "zebra" or "aardvark" based on address comparison

    return 0;
}