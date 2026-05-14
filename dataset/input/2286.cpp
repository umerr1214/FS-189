#include <iostream>

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const {
        // SEMANTIC ERROR: Attempting to modify a member variable ('width')
        // within a const member function (`getArea() const`).
        // This violates const-correctness and will result in a compilation error.
        width = width + 1.0; 
        return width * height;
    }

    void printInfo() const {
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }
};

int main() {
    Rectangle r1(10.0, 5.0);
    const Rectangle const_r1(7.0, 3.0);

    std::cout << "Area of r1: " << r1.getArea() << std::endl;
    std::cout << "Area of const_r1: " << const_r1.getArea() << std::endl;

    return 0;
}