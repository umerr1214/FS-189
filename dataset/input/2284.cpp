#include <iostream>

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const {
        return width * height;
    }

    void printInfo() const {
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Rectangle r1(10.0, 5.0);
    const Rectangle const_r1(7.0, 3.0);

    std::cout << "Area of r1: " << r1.getArea() << std::endl;
    std::cout << "Area of const_r1: " << const_r1.getArea() << std::endl;

    // Demonstrate that getArea() can be called on a const object
    // and does not modify its state.
    // The const_r1.getArea() call would not compile if getArea() was not const
    // or if it attempted to modify state.

    return 0;
}