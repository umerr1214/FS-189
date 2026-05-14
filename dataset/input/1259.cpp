#include <iostream>
#include <sstream>

class Point {
public:
    int x;
    int y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Logical Error: Only increments x, not y
    Point& operator++() {
        ++x;
        // ++y; // Missing increment for y, leading to incorrect state
        return *this;
    }
};

int main() {
    std::stringstream ss;
    // Test case 1
    Point p1(1, 2);
    ++p1;
    ss << "(" << p1.x << ", " << p1.y << ")"; // Expected (2,3), Actual (2,2)
    // Test case 2
    Point p2(5, 10);
    ++p2; // p2 becomes (6,10)
    ++p2; // p2 becomes (7,10)
    ss << ";" << "(" << p2.x << ", " << p2.y << ")"; // Expected (7,12), Actual (7,10)
    std::cout << ss.str();
    return 0;
}