#include <iostream>

class Point {
public:
    int x;
    int y;

    Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    // Syntax error: Missing return type 'bool'
    operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }
};

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);

    // This code will not compile due to the syntax error in operator==
    // If it compiled, it would produce:
    // p1 == p2 is true (expected true)
    // p1 == p3 is false (expected false)

    /*
    if (p1 == p2) {
        std::cout << "p1 == p2 is true (expected true)" << std::endl;
    } else {
        std::cout << "p1 == p2 is false (expected true)" << std::endl;
    }

    if (p1 == p3) {
        std::cout << "p1 == p3 is true (expected false)" << std::endl;
    } else {
        std::cout << "p1 == p3 is false (expected false)" << std::endl;
    }
    */

    return 0;
}