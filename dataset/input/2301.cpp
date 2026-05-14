#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    // Constructor with default arguments for convenience
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Friend declaration for the stream insertion operator
    // This allows the operator to access private members x and y.
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

// Overload the stream insertion operator `<<` as an external friend function.
// It takes a `std::ostream` reference and a `const Point&` reference.
// It returns the `std::ostream` reference to allow chaining of output operations.
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point p1(10, 20);
    Point p2(-5, 0);
    Point p3(1000, -2000);
    Point p4; // Default constructed Point (0,0)

    std::cout << "Point 1: " << p1 << std::endl;
    std::cout << "Point 2: " << p2 << std::endl;
    std::cout << "Point 3: " << p3 << std::endl;
    std::cout << "Point 4 (default): " << p4 << std::endl;

    // Test chaining of the overloaded operator
    std::cout << "Chained output: " << p1 << ", " << p2 << ", " << p3 << std::endl;

    return 0;
}