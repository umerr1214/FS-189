#include <iostream>
#include <string>
#include <sstream> // Used for stringstream

// Definition of the Point class (from Question 15)
class Point {
public:
    int x;
    int y;

    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}
};

// Readability / Efficiency Issue:
// Constructs a temporary std::string using std::stringstream, then prints it.
// This is less efficient than directly inserting components into the stream,
// and less idiomatic for stream operations.
std::ostream& operator<<(std::ostream& os, const Point& p) {
    std::stringstream ss;
    ss << "(" << p.x << ", " << p.y << ")"; // Build string in stringstream
    os << ss.str(); // Extract string and insert into original stream
    return os;
}

int main() {
    Point p1(10, 20);
    Point p2(-5, 15);
    Point p3(0, 0);
    Point p4(100, 200);

    std::cout << "P1: " << p1 << std::endl;
    std::cout << "P2: " << p2 << std::endl;
    std::cout << "P3: " << p3 << std::endl;
    std::cout << "Chaining test: " << p4 << " " << p1 << std::endl;

    return 0;
}