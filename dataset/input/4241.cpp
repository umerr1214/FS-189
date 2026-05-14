#include <iostream>
#include <string>

// Function template to find the maximum of two comparable values (with a logical error)
template <typename T>
T find_maximum(T a, T b) {
    // Logical error: Returns the smaller value instead of the larger
    if (a > b) {
        return b; // Should be 'return a;'
    } else {
        return a; // Should be 'return b;'
    }
}

int main() {
    // Test with integers
    int int_a = 5;
    int int_b = 10;
    std::cout << "Maximum of " << int_a << " and " << int_b << " is: " << find_maximum(int_a, int_b) << std::endl;

    // Test with doubles
    double double_a = 3.14;
    double double_b = 2.718;
    std::cout << "Maximum of " << double_a << " and " << double_b << " is: " << find_maximum(double_a, double_b) << std::endl;

    // Test with equal values
    int int_c = 7;
    int int_d = 7;
    std::cout << "Maximum of " << int_c << " and " << int_d << " is: " << find_maximum(int_c, int_d) << std::endl;

    return 0;
}