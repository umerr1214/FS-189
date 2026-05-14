#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Default constructor using initializer list
    Point() : x(0), y(0) {}

    // Parameterized constructor using initializer list
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}

    // Getter methods for x and y, correctly const-qualified
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

int main() {
    // Test default constructor
    Point p1;
    std::cout << p1.getX() << " " << p1.getY() << std::endl;

    // Test parameterized constructor
    Point p2(5, 10);
    std::cout << p2.getX() << " " << p2.getY() << std::endl;

    // Test with negative coordinates
    Point p3(-3, 7);
    std::cout << p3.getX() << " " << p3.getY() << std::endl;

    return 0;
}