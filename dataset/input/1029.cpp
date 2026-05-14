#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Public getters added
    double getLength() const { return length; }
    double getWidth() const { return width; }

    // Friend declaration is present
    friend double calculateArea(const Rectangle& r);
};

// The definition of the friend function
double calculateArea(const Rectangle& r) {
    // Semantic Error: The friend function accesses private members indirectly via public getters,
    // instead of directly using 'r.length' and 'r.width', which bypasses the explicit purpose of 'friend' in this context.
    return r.getLength() * r.getWidth();
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