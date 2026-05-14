#include <iostream>
#include <string>
#include <sstream>

class Point2D {
private:
    int x;
    int y;
public:
    Point2D(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    
    // Friend declaration for the stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Point2D& p);
};

// Overload the stream insertion operator
std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    // LOGICAL ERROR: Prints with square brackets instead of parentheses
    os << "[" << p.x << ", " << p.y << "]"; 
    return os;
}

int main() {
    Point2D p1(1, 2);
    Point2D p2(10, 20);
    Point2D p3(-5, 0);

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;

    return 0;
}