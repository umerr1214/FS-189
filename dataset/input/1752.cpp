#include <iostream>

class Point {
private: // Members are private
    int x;
    int y;

public:
    Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    // Public getters would be needed for a non-friend non-member operator==
    // int getX() const { return x; }
    // int getY() const { return y; }
};

// Semantic error: Tries to access private members x and y without being a friend function
// or without using public getters. This will result in a compilation error due to access control.
bool operator==(const Point& p1, const Point& p2) {
    // Attempting to access p1.x and p1.y will cause a compile-time error
    return (p1.x == p2.x && p1.y == p2.y);
}

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);

    // This code will not compile due to the semantic error (private member access).
    // If it compiled (e.g., if x and y were public or operator== was a friend),
    // it would produce:
    // p1 == p2 is true (expected true)
    // p1 == p3 is false (expected false)

    /*
    if (p1 == p2) {
        std::cout << "p1 == p2 is true (expected true)" << std::endl;
    } else {
        std::cout << "p1 == p2 is false (expected true)" << std::endl;
    }

    if (p1 == p3) {
        std::cout << "p1 == p3 is true (expected false)" << std::endl;
    } else {
        std::cout << "p1 == p3 is false (expected false)" << std::endl;
    }
    */

    return 0;
}