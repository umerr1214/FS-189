#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Method to display point coordinates
    void display() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

    // Overload the binary + operator
    // SEMANTIC ERROR: Operator takes arguments by value instead of const reference.
    // This leads to unnecessary copying and is less efficient, though it compiles.
    Point operator+(Point other) const { // 'other' is passed by value
        return Point(x + other.x, y + other.y);
    }
};

int main() {
    Point p1(10, 20);
    Point p2(3, 7);

    Point p3 = p1 + p2; 

    std::cout << "Point p1: ";
    p1.display();
    std::cout << "Point p2: ";
    p2.display();
    std::cout << "p1 + p2 = ";
    p3.display();

    Point p4(0, 0);
    Point p5(-5, 12);
    Point p6 = p4 + p5;
    std::cout << "p4 + p5 = ";
    p6.display();

    return 0;
}