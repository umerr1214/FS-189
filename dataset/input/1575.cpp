#include <iostream>
// No other includes needed for this simple case

// Definition of the Point class (from Question 15)
class Point {
public:
    int x;
    int y;

    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}
};

// Correct Version:
// Takes 'const Point&' as parameter for efficiency and correctness with const objects.
// Returns 'std::ostream&' to allow operator chaining.
// Directly inserts components into the stream for efficiency and idiomatic C++.
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point p1(10, 20);
    Point p2(-5, 15);
    Point p3(0, 0);
    Point p4(100, 200);
    const Point p5(1, 1); // Test with a const Point

    std::cout << "P1: " << p1 << std::endl;
    std::cout << "P2: " << p2 << std::endl;
    std::cout << "P3: " << p3 << std::endl;
    std::cout << "P5 (const): " << p5 << std::endl;
    std::cout << "Chaining test: " << p4 << " " << p1 << " " << p3 << std::endl;

    return 0;
}