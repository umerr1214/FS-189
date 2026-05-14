#include <iostream>

class Point {
public:
    int x;
    int y;

    Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    // Logical error: Only compares x coordinates, ignoring y
    bool operator==(const Point& other) const {
        return (x == other.x); // Should be (x == other.x && y == other.y)
    }
};

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(1, 4); // p1.x == p3.x, but p1.y != p3.y
    Point p4(3, 4);

    std::cout << "Testing p1(1,2) == p2(1,2): ";
    if (p1 == p2) {
        std::cout << "True (Correct)" << std::endl; // Expected: True, Actual: True
    } else {
        std::cout << "False (Incorrect)" << std::endl;
    }

    std::cout << "Testing p1(1,2) == p3(1,4): ";
    if (p1 == p3) {
        std::cout << "True (Incorrect, expected False)" << std::endl; // Expected: False, Actual: True
    } else {
        std::cout << "False (Correct)" << std::endl;
    }

    std::cout << "Testing p1(1,2) == p4(3,4): ";
    if (p1 == p4) {
        std::cout << "True (Incorrect)" << std::endl;
    } else {
        std::cout << "False (Correct)" << std::endl; // Expected: False, Actual: False
    }

    return 0;
}