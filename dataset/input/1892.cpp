#include <iostream>
#include <sstream> // Required for std::ostringstream
#include <string>  // Required for std::string

// Q7: Point2D class with private x and y coordinates
class Point2D {
private:
    int x;
    int y;

public:
    // Constructor to initialize x and y
    Point2D(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    // Getters for private members
    int getX() const { return x; }
    int getY() const { return y; }
};

// Overload the stream insertion operator <<
// Readability/Efficiency Issue: Uses std::ostringstream unnecessarily.
std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    // This approach creates a temporary string stream, formats the point into it,
    // converts the string stream content to a std::string, and then writes that
    // string to the output stream.
    // For simple formatting like this, it's less efficient and more verbose
    // than directly writing to `os`.
    std::ostringstream oss;
    oss << "(" << p.getX() << ", " << p.getY() << ")";
    os << oss.str();
    return os;
}

int main() {
    // Test cases
    Point2D p1(10, 20);
    Point2D p2(-5, 0);
    Point2D p3(100, -200);

    std::cout << "Point p1: " << p1 << std::endl;
    std::cout << "Point p2: " << p2 << std::endl;
    std::cout << "Point p3: " << p3 << std::endl;

    return 0;
}