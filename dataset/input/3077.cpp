#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    // Logical Error: The y-coordinate is subtracted instead of added.
    Point operator+(const Point& other) const {
        return Point(x + other.x, y - other.y); // Should be y + other.y
    }
};

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2;
    std::cout << p3.getX() << "," << p3.getY() << std::endl; // Expected: 4,6. Actual: 4,-2

    Point p4(10, -5);
    Point p5(-3, 8);
    Point p6 = p4 + p5;
    std::cout << p6.getX() << "," << p6.getY() << std::endl; // Expected: 7,3. Actual: 7,-13

    Point p7(0, 0);
    Point p8(5, 5);
    Point p9 = p7 + p8;
    std::cout << p9.getX() << "," << p9.getY() << std::endl; // Expected: 5,5. Actual: 5,-5

    return 0;
}