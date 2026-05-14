#include <iostream>

class Point {
private: // Semantic Error: x and y are private
    int x;
    int y;

public:
    Point(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}
};

// Overload the == operator as a non-member function
// Semantic Error: Attempts to access private members of Point without being a friend function.
bool operator==(const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y; // This will cause a compilation error due to private member access
}

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);
    Point p4(1, 5);

    // This part of the code will not compile due to the semantic error in operator==
    // std::cout << "p1(1,2) == p2(1,2): " << (p1 == p2 ? "true" : "false") << std::endl;
    // std::cout << "p1(1,2) == p3(3,4): " << (p1 == p3 ? "true" : "false") << std::endl;
    // std::cout << "p1(1,2) == p4(1,5): " << (p1 == p4 ? "true" : "false") << std::endl;
    // std::cout << "p3(3,4) == p3(3,4): " << (p3 == p3 ? "true" : "false") << std::endl;

    return 0;
}