#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Constructor
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}

    // No default constructor provided, which can be a minor robustness issue

    // Getter methods for coordinates
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    // Overload the binary + operator as a member function
    // Robustness Issue: Missing 'const' qualifier at the end of the function signature.
    // This implies the 'this' object might be modified, which is not robust for an addition operation.
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }
};

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2; // Should be (4, 6)

    std::cout << "Point p1: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    std::cout << "Point p2: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
    std::cout << "p1 + p2: (" << p3.getX() << ", " << p3.getY() << ")" << std::endl; // Expected: (4, 6)

    Point p4(0, 0);
    Point p5(-1, -1);
    Point p6 = p4 + p5; // Should be (-1, -1)
    std::cout << "p4 + p5: (" << p6.getX() << ", " << p6.getY() << ")" << std::endl; // Expected: (-1, -1)

    Point p7(10, -5);
    Point p8(2, 7);
    Point p9 = p7 + p8; // Should be (12, 2)
    std::cout << "p7 + p8: (" << p9.getX() << ", " << p9.getY() << ")" << std::endl; // Expected: (12, 2)

    return 0;
}