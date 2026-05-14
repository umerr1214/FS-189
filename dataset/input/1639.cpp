#include <iostream>

class Rectangle {
private:
    double width;
    double height;

public:
    // Parameterized constructor - Robustness issue: does not validate dimensions
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    // Public method to get the area
    double getArea() const {
        return width * height;
    }
};

int main() {
    // Test cases for Robustness Issue
    Rectangle r1(10.0, 5.0);
    std::cout << "Area for (10.0, 5.0): " << r1.getArea() << std::endl;

    Rectangle r2(-10.0, 5.0); // Robustness issue: negative width accepted, leading to negative area
    std::cout << "Area for (-10.0, 5.0): " << r2.getArea() << std::endl;

    Rectangle r3(0.0, 5.0); // Edge case, valid
    std::cout << "Area for (0.0, 5.0): " << r3.getArea() << std::endl;

    Rectangle r4(-7.0, -3.0); // Robustness issue: two negative dimensions yield a positive area, still conceptually wrong
    std::cout << "Area for (-7.0, -3.0): " << r4.getArea() << std::endl;

    return 0;
}