#include <iostream>
#include <string> // Not strictly needed for const char* literals, but good practice if string ops were intended

// Function template to find the maximum of two values
template <typename T>
T findMax(T val1, T val2) {
    // This implementation correctly compares values using the '>' operator.
    // However, for certain types like C-style strings (const char*),
    // the default '>' operator compares memory addresses, not string content,
    // which can lead to unexpected and incorrect results for the user's intent.
    return (val1 > val2) ? val1 : val2;
}

int main() {
    // Test with int data type
    int num1 = 10;
    int num2 = 5;
    std::cout << "Max of " << num1 << " and " << num2 << " (int): " << findMax(num1, num2) << std::endl;

    // Test with double data type
    double dbl1 = 3.14;
    double dbl2 = 2.718;
    std::cout << "Max of " << dbl1 << " and " << dbl2 << " (double): " << findMax(dbl1, dbl2) << std::endl;

    // Robustness Issue: Comparing C-style strings (const char*)
    // The default operator> for const char* compares memory addresses, not string content.
    // The output here will depend on where the string literals are stored in memory.
    const char* s1 = "apple";
    const char* s2 = "banana";
    const char* max_s12 = findMax(s1, s2);
    std::cout << "Max of \"" << s1 << "\" and \"" << s2 << "\" (const char*): " << max_s12 << std::endl;

    const char* s3 = "zebra";
    const char* s4 = "aardvark";
    const char* max_s34 = findMax(s3, s4);
    std::cout << "Max of \"" << s3 << "\" and \"" << s4 << "\" (const char*): " << max_s34 << std::endl;

    return 0;
}