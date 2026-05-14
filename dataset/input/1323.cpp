#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Default constructor using initializer list
    Point() : x(0), y(0) {}

    // Parameterized constructor using initializer list
    Point(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}

    // Public method to display coordinates, marked const as it does not modify the object
    void displayPoint() const {
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

    // Verify const correctness
    const Point p_const(100, 200);
    std::cout << "Point p_const (const object): ";
    p_const.displayPoint();
    std::cout << std::endl;

    return 0;
}