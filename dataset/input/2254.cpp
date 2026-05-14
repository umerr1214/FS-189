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
    // SYNTAX ERROR: Missing return type for operator+
    operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
};

int main() {
    Point p1(10, 20);
    Point p2(3, 7);

    Point p3 = p1 + p2; // This line will cause a compilation error due to the syntax error

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