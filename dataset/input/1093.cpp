#include <iostream>
#include <string>

class Point {
public:
    int x, y;

    Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    // Robustness issue: The operator== has a logical flaw.
    // If the 'this' point's x-coordinate is negative, it incorrectly returns true
    // for any comparison, regardless of the other point's coordinates.
    bool operator==(const Point& other) const {
        if (this->x < 0) {
            // This is the bug: if this point's x is negative, it always claims equality.
            return true;
        }
        return (this->x == other.x && this->y == other.y);
    }
};

// Helper function to print bool as "true" or "false"
std::string bool_to_string(bool b) {
    return b ? "true" : "false";
}

int main() {
    // Test cases for Robustness Issue
    Point p1(1, 1);
    Point p2(1, 1);
    Point p3(1, 2);
    Point p4(2, 1);
    Point p5(0, 0);
    Point p6(-5, -10); // Point with negative x
    Point p7(10, 20);
    Point p8(-5, -10); // Another point with negative x, same coordinates

    // Expected: true (Correct behavior)
    std::cout << bool_to_string(p1 == p2) << std::endl;
    // Expected: false (Correct behavior)
    std::cout << bool_to_string(p1 == p3) << std::endl;
    // Expected: false (Correct behavior)
    std::cout << bool_to_string(p1 == p4) << std::endl;
    // Expected: true (Correct behavior)
    std::cout << bool_to_string(p5 == p5) << std::endl;
    // Expected: false (Bug in action: p6.x is -5, so it returns true, but it should be false)
    std::cout << bool_to_string(p6 == p7) << std::endl;
    // Expected: true (Bug in action: p6.x is -5, so it returns true. Correct result by coincidence.)
    std::cout << bool_to_string(p6 == p8) << std::endl;
    // Expected: false (Correct behavior, p7.x is positive)
    std::cout << bool_to_string(p7 == p6) << std::endl;

    return 0;
}