#include <iostream>

class Point {
public:
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "Point(" << p.x << "," << p.y << ")";
        return os;
    }
};

// Logical error: y coordinates are multiplied instead of added
Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.x + p2.x, p1.y * p2.y); // Should be p1.y + p2.y
}

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2;
    std::cout << p3 << std::endl;

    Point p4(0, 0);
    Point p5(-1, 5);
    Point p6 = p4 + p5;
    std::cout << p6 << std::endl;

    return 0;
}