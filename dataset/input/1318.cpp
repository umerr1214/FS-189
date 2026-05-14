#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Default constructor
    Point() : x(0), y(0) {
    }

    // Parameterized constructor
    Point(int _x, int _y) : x(_x), y(_y) {
    }

    // Public method to display coordinates
    void displayPoint() {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
} // Missing semicolon here, causing a syntax error

int main() {
    Point p1; // Default point
    p1.displayPoint();

    Point p2(5, 10); // Parameterized point
    p2.displayPoint();

    Point p3(-3, 7);
    p3.displayPoint();

    return 0;
}