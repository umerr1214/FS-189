#include <iostream>

class Point {
private:
    int x;
    int y // Missing semicolon here, causing a syntax error
public:
    // Default constructor
    Point() : x(0), y(0) {}

    // Parameterized constructor
    Point(int valX, int valY) : x(valX), y(valY) {}

    // Method to print the point coordinates
    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point p1;
    std::cout << "p1: ";
    p1.print();

    Point p2(10, 20);
    std::cout << "p2: ";
    p2.print();

    return 0;
}