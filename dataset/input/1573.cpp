#include <iostream>
#include <string> // Not strictly needed for this version, but good for completeness

// Definition of the Point class (from Question 15)
class Point {
public:
    int x;
    int y;

    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}
};

// Robustness Issue:
// 1. Does not take 'const Point&' as parameter, preventing its use with const Point objects.
// 2. Returns 'void' instead of 'std::ostream&', breaking operator chaining.
void operator<<(std::ostream& os, Point p) { // 'p' is passed by value, and not const
    os << "(" << p.x << ", " << p.y << ")";
}

int main() {
    Point p1(10, 20);
    Point p2(-5, 15);
    Point p3(0, 0);

    // This will print correctly for individual points,
    // but chaining like 'std::cout << p1 << p2;' will not compile.
    std::cout << "P1: ";
    operator<<(std::cout, p1); // Calling directly as operator<< returns void
    std::cout << std::endl;

    std::cout << "P2: ";
    operator<<(std::cout, p2);
    std::cout << std::endl;

    std::cout << "P3: ";
    operator<<(std::cout, p3);
    std::cout << std::endl;

    // Demonstrate the chaining issue:
    // This line would cause a compile error:
    // std::cout << "Chaining test: " << p1 << " " << p2 << std::endl;
    // Because operator<< returns void, the result of (std::cout << p1) cannot be used as the left operand for the next <<.

    return 0;
}