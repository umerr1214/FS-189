#include <iostream>

template <typename T // Syntax error: Missing closing angle bracket '>'
T findMin(T val1, T val2) {
    return (val1 < val2) ? val1 : val2;
}

int main() {
    // Demonstrate with int
    int a = 10, b = 20;
    std::cout << "Min of " << a << " and " << b << " is: " << findMin(a, b) << std::endl;

    // Demonstrate with double
    double x = 5.5, y = 3.14;
    std::cout << "Min of " << x << " and " << y << " is: " << findMin(x, y) << std::endl;

    // Demonstrate with char
    char c1 = 'Z', c2 = 'A';
    std::cout << "Min of " << c1 << " and " << c2 << " is: " << findMin(c1, c2) << std::endl;

    return 0;
}