#include <iostream>
#include <string>
#include <sstream>

class Point2D {
private:
    int x;
    int y;
public:
    Point2D(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    
    // SEMANTIC ERROR: Missing friend declaration for operator<<.
    // This will lead to a compilation error when trying to access private members x and y.
};

// Overload the stream insertion operator
std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    // This line will cause a compilation error because operator<< is not a friend
    // and cannot access private members p.x and p.y
    os << "(" << p.x << ", " << p.y << ")"; 
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