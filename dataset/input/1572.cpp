#include <iostream>

class Point {
private: // <-- Members are private
    int x;
    int y;
public:
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}
    // Missing friend declaration for operator<<
};

// Semantic Error: Attempting to access private members (p.x, p.y) from a non-friend, non-member function.
// This is syntactically correct for public members, but semantically incorrect for private members.
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")"; // Error: 'int Point::x' is private
    return os;
}

int main() {
    Point p1(10, 20);
    std::cout << p1 << std::endl;
    return 0;
}