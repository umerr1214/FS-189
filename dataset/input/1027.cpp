#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Syntax Error: Typo in 'friend' keyword
    frind double calculateArea(const Rectangle& r);
};

// The definition of the friend function
double calculateArea(const Rectangle& r) {
    return r.length * r.width;
}

int main() {
    // Test case 1
    Rectangle rect1(5.0, 4.0);
    std::cout << "Rectangle 1 (5.0x4.0) Area: " << calculateArea(rect1) << std::endl;

    // Test case 2
    Rectangle rect2(10.5, 2.0);
    std::cout << "Rectangle 2 (10.5x2.0) Area: " << calculateArea(rect2) << std::endl;

    return 0;
}