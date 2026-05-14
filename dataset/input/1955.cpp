#include <iostream>

class Point {
public:
    int x, y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

// Overload binary + operator as a non-member function
// LOGICAL ERROR: This function returns the first operand unchanged,
// instead of a new Point object with summed coordinates.
Point operator+(const Point& p1, const Point& p2) {
    // Correct implementation should be: return Point(p1.x + p2.x, p1.y + p2.y);
    return p1; // Returns p1 without adding p2's coordinates
}

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2;
    p3.print(); // Expected (4, 6), but will output (1, 2) due to logical error

    Point p4(10, 20);
    Point p5(5, 5);
    Point p6 = p4 + p5;
    p6.print(); // Expected (15, 25), but will output (10, 20) due to logical error

    return 0;
}