#include <iostream>

class Point {
public:
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
}; // Missing semicolon here, but C++ often tolerates this.
   // A more robust syntax error is a missing brace.

// Overload == operator
bool operator==(const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);

    if (p1 == p2) {
        std::cout << "P1 == P2 is true" << std::endl;
    } else {
        std::cout << "P1 == P2 is false" << std::endl;
    }

    if (p1 == p3) {
        std::cout << "P1 == P3 is true" << std::endl;
    } else {
        std::cout << "P1 == P3 is false" << std::endl;
    }
    return 0;
    // MISSING CLOSING BRACE FOR main FUNCTION
}