#include <iostream>

class Point {
public:
    int x;
    int y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Friend declaration for the == operator
    // Robustness Issue: Parameters are not const references.
    // This signature prevents comparing temporary objects (rvalues) and
    // violates the principle that comparison operations should not modify their operands.
    friend bool operator==(Point& p1, Point& p2);
};

// Definition of the == operator
// Robustness Issue: Parameters are not const references.
// While this specific implementation does not modify p1 or p2,
// the non-const signature allows for accidental modification and restricts usage.
bool operator==(Point& p1, Point& p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);

    std::cout << "Test Case 1: p1 == p2 (Expected: true, Actual: " << (p1 == p2 ? "true" : "false") << ")" << std::endl; // Should be true
    std::cout << "Test Case 2: p1 == p3 (Expected: false, Actual: " << (p1 == p3 ? "true" : "false") << ")" << std::endl; // Should be false

    Point p4(5, 6);
    Point p5(5, 7);
    std::cout << "Test Case 3: p4 == p5 (Expected: false, Actual: " << (p4 == p5 ? "true" : "false") << ")" << std::endl; // Should be false

    Point p6(8, 8);
    Point p7(8, 8);
    std::cout << "Test Case 4: p6 == p7 (Expected: true, Actual: " << (p6 == p7 ? "true" : "false") << ")" << std::endl; // Should be true

    // Note: Calling with temporary objects like `Point(10, 20) == Point(10, 20)`
    // would result in a compile-time error due to the non-const reference parameters,
    // which is a manifestation of this robustness issue.
    // The driver avoids such calls to ensure compilation.

    return 0;
}