#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Default constructor
    Point() : x(0), y(0) {
    }

    // Parameterized constructor - LOGICAL ERROR: Swaps x and y
    Point(int _x, int _y) : x(_y), y(_x) { // x is initialized with _y, y with _x
    }

    // Public method to display coordinates
    void displayPoint() {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point p1; // Default point
    p1.displayPoint(); // Expected: Point(0, 0)

    Point p2(5, 10); // Parameterized point
    p2.displayPoint(); // Expected: Point(5, 10), Actual: Point(10, 5)

    Point p3(-3, 7);
    p3.displayPoint(); // Expected: Point(-3, 7), Actual: Point(7, -3)

    return 0;
}