#include <iostream>
#include <algorithm> // Not strictly needed for ternary, but good for std::max alternative

// Function template to find the maximum of two values
template <typename T>
T findMax(T val1, T val2) {
    // Using the concise and efficient ternary operator for comparison.
    // This is a standard and readable way to implement max for two values.
    return (val1 > val2) ? val1 : val2;
    // Alternative: return std::max(val1, val2);
}

int main() {
    // Test with int data type
    int num1 = 20;
    int num2 = 30;
    std::cout << "Max of " << num1 << " and " << num2 << " (int): " << findMax(num1, num2) << std::endl;

    // Test with double data type
    double dbl1 = 5.5;
    double dbl2 = 5.4;
    std::cout << "Max of " << dbl1 << " and " << dbl2 << " (double): " << findMax(dbl1, dbl2) << std::endl;

    // Test with char data type
    char char1 = 'a';
    char char2 = 'z';
    std::cout << "Max of '" << char1 << "' and '" << char2 << "' (char): " << findMax(char1, char2) << std::endl;

    // Test with negative numbers
    int neg1 = -10;
    int neg2 = -5;
    std::cout << "Max of " << neg1 << " and " << neg2 << " (int): " << findMax(neg1, neg2) << std::endl;

    return 0;
}