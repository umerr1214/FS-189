#include <iostream>

class Point {
public: // Semantic error: x and y should be private as per the question
    int x;
    int y;
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

    // This direct access would be possible due to the semantic error (public members)
    // p1.x = 5; 
    // p1.y = 5;
    // std::cout << "p1 after direct modification: ";
    // p1.print();

    return 0;
}