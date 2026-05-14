#include <iostream>

template <typename T>
int findMax(T a, T b) { // SEMANTIC ERROR: Return type is fixed to 'int' instead of 'T'
    return (a > b) ? a : b;
}

int main() {
    // Demonstrate with int
    std::cout << "Max of 5 and 10: " << findMax(5, 10) << std::endl; // Correct value, but type is int

    // Demonstrate with double
    std::cout << "Max of 3.14 and 2.71: " << findMax(3.14, 2.71) << std::endl; // Expected: 3.14, Actual: 3 (truncated double)

    // Demonstrate with char
    std::cout << "Max of 'a' and 'z': " << findMax('a', 'z') << std::endl; // Expected: z, Actual: 122 (ASCII value of 'z')

    return 0;
}