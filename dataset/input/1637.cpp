#include <iostream>

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Logical error: returns the sum of width and height instead of the product.
    double getArea() {
        return width + height; // Should be width * height
    }
};

int main() {
    Rectangle r1(5.0, 3.0);
    std::cout << "Area: " << r1.getArea() << std::endl; // Expected 15.0, outputs 8.0

    Rectangle r2(7.5, 2.0);
    std::cout << "Area: " << r2.getArea() << std::endl; // Expected 15.0, outputs 9.5

    Rectangle r3(4.5, 2.5);
    std::cout << "Area: " << r3.getArea() << std::endl; // Expected 11.25, outputs 7.0

    return 0;
}