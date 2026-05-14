#include <iostream>

class Point {
public:
    int x;
    int y;

    Point(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}
};

// Overload the == operator as a non-member function with a logical error
bool operator==(const Point& p1, const Point& p2) {
    // Logical Error: Comparing x with other.y and y with other.x
    return p1.x == p2.y && p1.y == p2.x;
}

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);
    Point p4(2, 1); // p4 is (2,1)

    std::cout << "p1(1,2) == p2(1,2): " << (p1 == p2 ? "true" : "false") << std::endl; // Expected: true, Actual: false (1==2 && 2==1)
    std::cout << "p1(1,2) == p3(3,4): " << (p1 == p3 ? "true" : "false") << std::endl; // Expected: false, Actual: false (1==4 && 2==3)
    std::cout << "p1(1,2) == p4(2,1): " << (p1 == p4 ? "true" : "false") << std::endl; // Expected: false, Actual: true (1==1 && 2==2)
    std::cout << "p3(3,4) == p3(3,4): " << (p3 == p3 ? "true" : "false") << std::endl; // Expected: true, Actual: false (3==4 && 4==3)

    return 0;
}