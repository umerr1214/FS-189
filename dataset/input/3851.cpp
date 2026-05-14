#include <iostream>

template <typename T>
void compareAndPrint(T a, T b) {
    if (a > b) {
        // Logical error: When 'a' is greater than 'b', it incorrectly prints 'b' as greater.
        std::cout << b << " is greater than " << a << std::endl;
    } else if (b > a) {
        std::cout << b << " is greater than " << a << std::endl;
    } else {
        std::cout << a << " is equal to " << b << std::endl;
    }
}

int main() {
    std::cout << "--- int comparison ---" << std::endl;
    compareAndPrint(5, 10);
    compareAndPrint(15, 5); // Expected: "15 is greater than 5", Actual: "5 is greater than 15"
    compareAndPrint(7, 7);

    std::cout << "\n--- double comparison ---" << std::endl;
    compareAndPrint(3.14, 2.71); // Expected: "3.14 is greater than 2.71", Actual: "2.71 is greater than 3.14"
    compareAndPrint(10.5, 20.1);
    compareAndPrint(9.9, 9.9);

    std::cout << "\n--- char comparison ---" << std::endl;
    compareAndPrint('A', 'B');
    compareAndPrint('Z', 'M'); // Expected: "Z is greater than M", Actual: "M is greater than Z"
    compareAndPrint('X', 'X');
    return 0;
}