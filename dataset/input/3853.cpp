#include <iostream>
#include <iomanip> // For consistent double precision printing

template <typename T>
void compareAndPrint(T a, T b) {
    // Robustness Issue:
    // This implementation uses direct equality comparison (a == b) for all types.
    // While technically correct for integer and character types, it introduces
    // a robustness issue for floating-point numbers (like `double`).
    // Due to the nature of floating-point representation, values that are
    // mathematically considered equal (e.g., 0.1 + 0.2 and 0.3) may not be
    // represented identically, leading to an 'not equal' result when direct
    // comparison is used. A more robust solution for floating-point equality
    // would involve comparing with a small epsilon.
    std::cout << std::fixed << std::setprecision(10);

    if (a > b) {
        std::cout << a << " is greater than " << b << std::endl;
    } else if (a < b) {
        std::cout << a << " is less than " << b << std::endl;
    } else { // This branch is problematic for some floating-point 'equal' values
        std::cout << a << " is equal to " << b << std::endl;
    }
}

int main() {
    // Demonstrate with int
    compareAndPrint(5, 10);
    compareAndPrint(10, 5);
    compareAndPrint(7, 7);

    // Demonstrate with double
    compareAndPrint(3.14, 2.71);
    compareAndPrint(2.71, 3.14);
    compareAndPrint(5.0, 5.0);
    // This case highlights the robustness issue for double equality:
    // 0.1 + 0.2 is not exactly 0.3 in binary floating-point representation.
    // 0.1 + 0.2 results in 0.30000000000000004
    // 0.3 results in 0.29999999999999999
    // So, (0.1 + 0.2) is actually slightly greater than 0.3.
    compareAndPrint(0.1 + 0.2, 0.3);
    compareAndPrint(0.3, 0.1 + 0.2);

    // Demonstrate with char
    compareAndPrint('a', 'b');
    compareAndPrint('b', 'a');
    compareAndPrint('c', 'c');

    return 0;
}