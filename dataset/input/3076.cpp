#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2;
    std::cout << p3.getX() << "," << p3.getY() << std::endl;

    Point p4(10, -5);
    Point p5(-3, 8);
    Point p6 = p4 + p5;
    std::cout << p6.getX() << "," << p6.getY() << std::endl;

    return 0;
}