#include <iostream>

class Point {
public:
    int x;
    int y;
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}
};

// Logical Error: Prints in an incorrect format (e.g., "x, y" instead of "(x, y)")
// or swaps x and y. Here, it prints "x_val: y_val"
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "x_val: " << p.x << ", y_val: " << p.y; // Incorrect format
    return os;
}

int main() {
    Point p1(10, 20);
    std::cout << p1 << std::endl;
    return 0;
}