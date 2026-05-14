#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Semantic error: getArea() returns an int, causing loss of precision
    // for the double area calculation, which is semantically incorrect for floating-point dimensions.
    int getArea() { // Should be 'double getArea()'
        return static_cast<int>(width * height); // Explicit cast demonstrates the precision loss
    }
};

int main() {
    Rectangle r1(5.0, 3.0);
    std::cout << "Area: " << r1.getArea() << std::endl; // Expected 15.0, outputs 15

    Rectangle r2(7.5, 2.0);
    std::cout << "Area: " << r2.getArea() << std::endl; // Expected 15.0, outputs 15

    Rectangle r3(4.5, 2.5); // Actual area is 11.25
    std::cout << std::fixed << std::setprecision(2); // For consistent output formatting
    std::cout << "Area: " << r3.getArea() << std::endl; // Expected 11.25, outputs 11.00 (due to truncation)

    return 0;
}