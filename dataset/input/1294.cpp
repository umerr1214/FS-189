#include <iostream>

class Rectangle {
public:
    double width;
    double height;

    Rectangle(double w = 0, double h = 0) : width(w), height(h) {}

    Rectangle& setDimensions(double w, double h) {
        width = w;
        height = h;
        return *this;
    }

    double calculateArea() const {
        return width * height;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    Rectangle rect;
    rect.setDimensions(10, 5);
    std::cout << "Area: " << rect.calculateArea() << std::endl;

    Rectangle rect2;
    double area = rect2.setDimensions(7, 3).calculateArea();
    std::cout << "Chained Area: " << area << std::endl;

    return 0;
}