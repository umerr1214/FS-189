#include <iostream>
#include <iomanip> // For consistent double precision printing

template <typename T>
void compareAndPrint(T a, T b) {
    // Correct Version:
    // This implementation is clean, concise, and correctly uses standard comparison
    // operators for the given types. The output is clear and direct.
    // For floating-point numbers, it uses direct comparison as implied by the
    // problem statement, which is correct in a strict sense, even if real-world
    // robust floating-point equality often requires an epsilon.

    std::cout << std::fixed << std::setprecision(10); // Ensures consistent output for doubles

    if (a > b) {
        std::cout << a << " is greater than " << b << std::endl;
    } else if (a < b) {
        std::cout << a << " is less than " << b << std::endl;
    } else { // If not greater and not less, they must be equal
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
    // As per the problem statement, direct comparison is used.
    // (0.1 + 0.2 is slightly greater than 0.3 in binary floating-point)
    compareAndPrint(0.1 + 0.2, 0.3);
    // (0.3 is slightly less than 0.1 + 0.2 in binary floating-point)
    compareAndPrint(0.3, 0.1 + 0.2);

    // Demonstrate with char
    compareAndPrint('a', 'b');
    compareAndPrint('b', 'a');
    compareAndPrint('c', 'c');

    return 0;
}