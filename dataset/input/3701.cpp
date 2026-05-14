#include <iostream>

template <typename T>
T findMax(T a, T b) {
    // LOGICAL ERROR: Returns the smaller value instead of the larger
    return (a < b) ? a : b; // Should be (a > b) ? a : b;
}

int main() {
    // Demonstrate with int
    std::cout << "Max of 5 and 10: " << findMax(5, 10) << std::endl;

    // Demonstrate with double
    std::cout << "Max of 3.14 and 2.71: " << findMax(3.14, 2.71) << std::endl;

    // Demonstrate with char
    std::cout << "Max of 'a' and 'z': " << findMax('a', 'z') << std::endl;

    return 0;
}