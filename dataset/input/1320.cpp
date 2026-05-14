#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Default constructor - SEMANTIC ERROR: Does not initialize x and y
    Point() {
        // x and y are left uninitialized, will contain garbage values
    }

    // Parameterized constructor
    Point(int _x, int _y) : x(_x), y(_y) {
    }

    // Public method to display coordinates
    void displayPoint() {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point p1; // Default point - x and y are uninitialized
    p1.displayPoint(); // Expected: Point(0, 0), Actual: Point(garbage, garbage)

    Point p2(5, 10); // Parameterized point
    p2.displayPoint(); // Expected: Point(5, 10)

    Point p3(-3, 7);
    p3.displayPoint(); // Expected: Point(-3, 7)

    return 0;
}