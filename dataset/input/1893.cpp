#include <iostream> // Required for std::cout, std::ostream, std::endl

// Q7: Point2D class with private x and y coordinates
class Point2D {
private:
    int x;
    int y;

public:
    // Constructor to initialize x and y
    Point2D(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    // Declare the stream insertion operator as a friend function.
    // This allows it to access private members x and y directly,
    // which is a common and idiomatic pattern for overloaded stream operators.
    friend std::ostream& operator<<(std::ostream& os, const Point2D& p);
};

// Overload the stream insertion operator <<
// This is the correct, efficient, and readable implementation.
std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    // Directly access private members x and y because the operator is a friend.
    // This is efficient as it avoids intermediate steps and directly writes
    // to the output stream.
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    // Test cases
    Point2D p1(10, 20);
    Point2D p2(-5, 0);
    Point2D p3(100, -200);
    Point2D p4; // Default constructor (initializes to 0,0)

    std::cout << "Point p1: " << p1 << std::endl;
    std::cout << "Point p2: " << p2 << std::endl;
    std::cout << "Point p3: " << p3 << std::endl;
    std::cout << "Point p4 (default): " << p4 << std::endl;

    return 0;
}