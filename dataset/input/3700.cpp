#include <iostream>

template <T> // SYNTAX ERROR: Missing 'typename' or 'class' keyword for template parameter
T findMax(T a, T b) {
    return (a > b) ? a : b;
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