#include <iostream>
#include <string>
#include <algorithm> // For std::max
#include <iomanip>   // For std::fixed and std::setprecision

class Rectangle {
private:
    double width;
    double height;

public:
    // Constructor with basic validation to ensure non-negative dimensions
    Rectangle(double w, double h) : width(std::max(0.0, w)), height(std::max(0.0, h)) {}

    // Correctly implemented const method to get area
    double getArea() const {
        return width * height;
    }

    // Accessor methods, also const, to retrieve dimensions
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    // 1. Demonstrate with a mutable Rectangle object
    Rectangle rect1(5.0, 4.0);
    std::cout << "Mutable Rectangle 1: Width=" << rect1.getWidth() << ", Height=" << rect1.getHeight()
              << ", Area=" << rect1.getArea() << std::endl;

    // 2. Demonstrate with a const Rectangle object
    const Rectangle constRect(10.0, 2.5);
    std::cout << "Const Rectangle 2: Width=" << constRect.getWidth() << ", Height=" << constRect.getHeight()
              << ", Area=" << constRect.getArea() << std::endl;

    // 3. Demonstrate that the const method does not modify object state
    //    (This is implicitly guaranteed by the 'const' keyword and compilation)
    double area_before = constRect.getArea();
    double area_after = constRect.getArea(); // Calling it again
    std::cout << "Const Rectangle 2 (repeated call): Area (before)=" << area_before
              << ", Area (after)=" << area_after << std::endl;

    // 4. Demonstrate constructor validation (robustness aspect of a correct version)
    Rectangle invalidRect(-3.0, 7.0); // Should set width to 0.0
    std::cout << "Invalid Input Rectangle 3: Width=" << invalidRect.getWidth() << ", Height=" << invalidRect.getHeight()
              << ", Area=" << invalidRect.getArea() << std::endl;

    const Rectangle anotherInvalidRect(8.0, -2.0); // Should set height to 0.0
    std::cout << "Invalid Input Rectangle 4 (const): Width=" << anotherInvalidRect.getWidth() << ", Height=" << anotherInvalidRect.getHeight()
              << ", Area=" << anotherInvalidRect.getArea() << std::endl;

    return 0;
}