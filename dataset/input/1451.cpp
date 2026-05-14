#include <iostream>

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    friend double calculateArea(const Rectangle& rect);
};

// Logical Error: This function calculates the perimeter instead of the area.
double calculateArea(const Rectangle& rect) {
    return 2 * (rect.width + rect.height); // Should be rect.width * rect.height
}

int main() {
    Rectangle r1(5.0, 10.0);
    std::cout << "Area of r1: " << calculateArea(r1) << std::endl;

    Rectangle r2(3.0, 7.0);
    std::cout << "Area of r2: " << calculateArea(r2) << std::endl;
    return 0;
}