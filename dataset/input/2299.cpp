#include <iostream>

class Point {
private:
    int x; // Uninitialized by default constructor
    int y; // Uninitialized by default constructor
public:
    // Explicit constructor
    Point(int _x, int _y) : x(_x), y(_y) {}

    // Default constructor that *doesn't* initialize members
    // This leads to uninitialized x and y, causing Undefined Behavior when accessed.
    Point() {} 

    // Friend declaration for the stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

// Overload the stream insertion operator as an external friend function
// The operator itself is correctly implemented, but the Point class's default
// constructor has a robustness issue.
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point p1(10, 20);
    Point p_default; // Robustness issue: x and y are uninitialized
    Point p2(-5, 0);

    std::cout << "Point 1: " << p1 << std::endl;
    std::cout << "Default Point: " << p_default << std::endl; // Will print garbage due to UB
    std::cout << "Point 2: " << p2 << std::endl;

    return 0;
}