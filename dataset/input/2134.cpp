#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    int getX() const { return x; }
    int getY() const { return y; }

    // Overload the binary + operator as a friend function
    friend Point operator+(const Point& p1, const Point& p2);
} // SYNTAX ERROR: Missing semicolon here

Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2;

    std::cout << "p1(" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    std::cout << "p2(" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
    std::cout << "p1 + p2 = p3(" << p3.getX() << ", " << p3.getY() << ")" << std::endl;

    Point p4(-5, 10);
    Point p5(2, -3);
    Point p6 = p4 + p5;
    std::cout << "p4(" << p4.getX() << ", " << p4.getY() << ")" << std::endl;
    std::cout << "p5(" << p5.getX() << ", " << p5.getY() << ")" << std::endl;
    std::cout << "p4 + p5 = p6(" << p6.getX() << ", " << p6.getY() << ")" << std::endl;

    return 0;
}