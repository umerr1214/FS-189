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
        // Logical Error: Incorrectly calculates sum instead of product
        return width + height;
    }
};

int main() {
    Rectangle rect;
    rect.setDimensions(10, 5);
    // Expected Area: 50 (10 * 5)
    // Actual Area:   15 (10 + 5)
    std::cout << "Area: " << rect.calculateArea() << std::endl;

    Rectangle rect2;
    double area = rect2.setDimensions(7, 3).calculateArea();
    // Expected Chained Area: 21 (7 * 3)
    // Actual Chained Area:   10 (7 + 3)
    std::cout << "Chained Area: " << area << std::endl;

    return 0;
}