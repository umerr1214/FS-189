#include <iostream>

class Point {
public:
    int x;
    int y;

    Point(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}
} // Syntax Error: Missing semicolon here

// Overload the == operator as a non-member function
bool operator==(const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);
    Point p4(1, 5);

    std::cout << "p1(1,2) == p2(1,2): " << (p1 == p2 ? "true" : "false") << std::endl;
    std::cout << "p1(1,2) == p3(3,4): " << (p1 == p3 ? "true" : "false") << std::endl;
    std::cout << "p1(1,2) == p4(1,5): " << (p1 == p4 ? "true" : "false") << std::endl;
    std::cout << "p3(3,4) == p3(3,4): " << (p3 == p3 ? "true" : "false") << std::endl;

    return 0;
}