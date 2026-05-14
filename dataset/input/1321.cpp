#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Default constructor
    Point() {
        x = 0;
        y = 0;
    }

    // Parameterized constructor
    Point(int initialX, int initialY) {
        x = initialX;
        y = initialY;
    }

    // Public method to display coordinates
    // Robustness Issue: This method should ideally be const as it doesn't modify the object.
    // Not being const prevents it from being called on const Point objects and
    // might lead to incorrect assumptions about object immutability.
    void displayPoint() {
        std::cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    // Test default constructor
    Point p1;
    std::cout << "Point p1 (default): ";
    p1.displayPoint();
    std::cout << std::endl;

    // Test parameterized constructor
    Point p2(10, 20);
    std::cout << "Point p2 (parameterized): ";
    p2.displayPoint();
    std::cout << std::endl;

    // Test with negative coordinates
    Point p3(-5, -8);
    std::cout << "Point p3 (negative): ";
    p3.displayPoint();
    std::cout << std::endl;

    // Example of how the lack of 'const' can be an issue:
    // const Point p_const(1, 1);
    // p_const.displayPoint(); // This would cause a compilation error if uncommented,
                              // highlighting the robustness issue.

    return 0;
}