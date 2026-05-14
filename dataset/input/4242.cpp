#include <iostream>
#include <string>

// Function template to find the maximum of two comparable values (with a semantic error)
template <typename T>
int find_maximum(T a, T b) { // Semantic error: Return type is fixed to 'int' instead of 'T'
    if (a > b) {
        return a; // If T is double, this involves an implicit conversion from double to int, losing precision.
    } else {
        return b; // Same here.
    }
}

int main() {
    // Test with integers
    int int_a = 5;
    int int_b = 10;
    std::cout << "Maximum of " << int_a << " and " << int_b << " is: " << find_maximum(int_a, int_b) << std::endl;

    // Test with doubles - this will highlight the semantic error
    double double_a = 3.14;
    double double_b = 2.718;
    // The call `find_maximum(double_a, double_b)` will return an int, potentially truncating the double value.
    std::cout << "Maximum of " << double_a << " and " << double_b << " is: " << find_maximum(double_a, double_b) << std::endl;

    // Test with equal values
    int int_c = 7;
    int int_d = 7;
    std::cout << "Maximum of " << int_c << " and " << int_d << " is: " << find_maximum(int_c, int_d) << std::endl;

    return 0;
}