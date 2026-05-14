#include <iostream>

template <typename T>
void compareAndPrint(T a, T b) {
    if (a > b) {
        std::cout << a << " is greater than " << b << std::endl // Missing semicolon here
    } else if (b > a) {
        std::cout << b << " is greater than " << a << std::endl;
    } else {
        std::cout << a << " is equal to " << b << std::endl;
    }
}

int main() {
    std::cout << "--- int comparison ---" << std::endl;
    compareAndPrint(5, 10);
    compareAndPrint(15, 5);
    compareAndPrint(7, 7);

    std::cout << "\n--- double comparison ---" << std::endl;
    compareAndPrint(3.14, 2.71);
    compareAndPrint(10.5, 20.1);
    compareAndPrint(9.9, 9.9);

    std::cout << "\n--- char comparison ---" << std::endl;
    compareAndPrint('A', 'B');
    compareAndPrint('Z', 'M');
    compareAndPrint('X', 'X');
    return 0;
}