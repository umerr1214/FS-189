#include <iostream>
#include <string> // Not strictly needed but often included

class Point {
public:
    int x;
    int y;
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}
};

// Syntax Error: Missing semicolon after class declaration, or incorrect operator signature
// Let's make a syntax error in the operator definition itself, e.g., missing '<<'
std::ostream& operator (std::ostream& os, const Point& p) { // <-- Syntax error here, should be 'operator<<'
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point p1(10, 20);
    std::cout << p1 << std::endl; // This line will cause a compilation error due to the malformed operator
    return 0;
}