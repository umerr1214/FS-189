#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    // Semantic Error: The question requires the operator+ to be a member function.
    // It is implemented here as a non-member function.
};

// Overload binary + operator as a non-member function, violating the requirement
// to be a member function.
Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY());
}

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2;
    std::cout << p3.getX() << "," << p3.getY() << std::endl;

    Point p4(10, -5);
    Point p5(-3, 8);
    Point p6 = p4 + p5;
    std::cout << p6.getX() << "," << p6.getY() << std::endl;

    Point p7(0, 0);
    Point p8(5, 5);
    Point p9 = p7 + p8;
    std::cout << p9.getX() << "," << p9.getY() << std::endl;

    return 0;
}