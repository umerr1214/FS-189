#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
} // SYNTAX ERROR: Missing semicolon here

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point p1(1, 2);
    std::cout << p1 << std::endl;
    Point p2(0, 0);
    std::cout << p2 << std::endl;
    Point p3(-5, 10);
    std::cout << p3 << std::endl;
    return 0;
}