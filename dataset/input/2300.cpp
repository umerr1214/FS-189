#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    // Friend declaration for the stream insertion operator
    // This declaration passes Point by value, which is an efficiency issue.
    friend std::ostream& operator<<(std::ostream& os, Point p);
};

// Overload the stream insertion operator as an external friend function
// This version passes `Point` by value and uses `std::endl`, affecting efficiency.
std::ostream& operator<<(std::ostream& os, Point p) { // Efficiency issue: Point passed by value
    os << "(" << p.x << ", " << p.y << ")" << std::endl; // Efficiency issue: uses std::endl
    return os;
}

int main() {
    Point p1(10, 20);
    Point p2(-5, 0);
    Point p3(1000, -2000);

    std::cout << "Point 1: " << p1; // operator<< adds its own std::endl
    std::cout << "Point 2: " << p2;
    std::cout << "Point 3: " << p3;

    return 0;
}