#include <iostream>
#include <string>

class Point {
public:
    int x, y;

    Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    // Readability / Efficiency issue: Overly verbose and less concise implementation.
    // Uses unnecessary temporary boolean variables and multiple if-else statements
    // instead of a direct logical expression.
    bool operator==(const Point& other) const {
        bool x_are_equal;
        bool y_are_equal;

        // Check x-coordinates
        if (this->x == other.x) {
            x_are_equal = true;
        } else {
            x_are_equal = false;
        }

        // Check y-coordinates
        if (this->y == other.y) {
            y_are_equal = true;
        } else {
            y_are_equal = false;
        }

        // Combine results
        if (x_are_equal && y_are_equal) {
            return true;
        } else {
            return false;
        }
    }
};

// Helper function to print bool as "true" or "false"
std::string bool_to_string(bool b) {
    return b ? "true" : "false";
}

int main() {
    // Test cases for Readability / Efficiency Issue
    Point p1(1, 1);
    Point p2(1, 1);
    Point p3(1, 2);
    Point p4(2, 1);
    Point p5(0, 0);
    Point p6(-5, -10);
    Point p7(-5, 0);

    // Expected: true
    std::cout << bool_to_string(p1 == p2) << std::endl;
    // Expected: false
    std::cout << bool_to_string(p1 == p3) << std::endl;
    // Expected: false
    std::cout << bool_to_string(p1 == p4) << std::endl;
    // Expected: true
    std::cout << bool_to_string(p5 == p5) << std::endl;
    // Expected: true
    std::cout << bool_to_string(p6 == p6) << std::endl;
    // Expected: false
    std::cout << bool_to_string(p6 == p7) << std::endl;

    return 0;
}