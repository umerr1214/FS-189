#include <iostream>
#include <string>
#include <cstring> // Not directly used by findMin, but relevant for char* context

template <typename T>
T findMin(T val1, T val2) {
    // This generic comparison works for types where operator< is defined correctly (e.g., int, double, std::string)
    // However, for C-style strings (char*), operator< compares pointer addresses, not string content.
    return (val1 < val2) ? val1 : val2;
}

int main() {
    // Demonstrate with int
    int i1 = 10, i2 = 5;
    std::cout << "Min of " << i1 << " and " << i2 << " (int): " << findMin(i1, i2) << std::endl;

    // Demonstrate with double
    double d1 = 3.14, d2 = 2.71;
    std::cout << "Min of " << d1 << " and " << d2 << " (double): " << findMin(d1, d2) << std::endl;

    // Demonstrate with C-style strings (char*) - This highlights the robustness issue
    // The comparison `s1 < s2` will compare memory addresses of the pointers, not the lexicographical content.
    // The result is unpredictable and often incorrect for comparing string values.
    const char* s1 = "apple";
    const char* s2 = "banana";
    // Depending on memory allocation, findMin(s1, s2) might return s1 or s2 based on address,
    // not based on "apple" being lexicographically smaller than "banana".
    std::cout << "Min of \"" << s1 << "\" and \"" << s2 << "\" (char*): " << findMin(s1, s2) << std::endl;

    // Demonstrate with std::string (works correctly due to overloaded operator<)
    std::string str1 = "grape";
    std::string str2 = "fig";
    std::cout << "Min of \"" << str1 << "\" and \"" << str2 << "\" (std::string): " << findMin(str1, str2) << std::endl;

    return 0;
}