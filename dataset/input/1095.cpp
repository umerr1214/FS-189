#include <iostream>
#include <string>

class Point {
public:
    int x, y;

    Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}
};

// Correct Version: Overload the == operator as a non-member, non-friend function
// for symmetry and idiomatic C++.
bool operator==(const Point& p1, const Point& p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}

// Helper function to print bool as "true" or "false"
std::string bool_to_string(bool b) {
    return b ? "true" : "false";
}

int main() {
    // Test cases for Correct Version
    Point p1(1, 1);
    Point p2(1, 1);
    Point p3(1, 2);
    Point p4(2, 1);
    Point p5(0, 0);
    Point p6(-5, -10);
    Point p7(-5, -10);
    Point p8(100, 200);
    Point p9(200, 100);

    // Expected: true
    std::cout << bool_to_string(p1 == p2) << std::endl;
    // Expected: false
    std::cout << bool_to_string(p1 == p3) << std::endl;
    // Expected: false
    std::cout << bool_to_string(p1 == p4) << std::endl;
    // Expected: true
    std::cout << bool_to_string(p5 == p5) << std::endl;
    // Expected: true
    std::cout << bool_to_string(p6 == p7) << std::endl;
    // Expected: false
    std::cout << bool_to_string(p6 == p3) << std::endl;
    // Expected: true
    std::cout << bool_to_string(p8 == p8) << std::endl;
    // Expected: false
    std::cout << bool_to_string(p8 == p9) << std::endl;
    // Expected: true (Symmetry check)
    std::cout << bool_to_string(p2 == p1) << std::endl;

    return 0;
}