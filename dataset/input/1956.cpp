#include <iostream>

class Point {
private: // SEMANTIC ERROR: x and y are private
    int x, y;

public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
    // No public getters for x, y, and operator+ is not a friend function
};

// Overload binary + operator as a non-member function
// SEMANTIC ERROR: Attempts to access private members x and y of Point objects
// without being a friend function or using public getters.
Point operator+(const Point& p1, const Point& p2) {
    // This line will cause a compilation error due to private member access
    return Point(p1.x + p2.x, p1.y + p2.y);
}

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2;
    p3.print();

    Point p4(10, 20);
    Point p5(5, 5);
    Point p6 = p4 + p5;
    p6.print();

    return 0;
}