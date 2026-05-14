#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class Rectangle {
private:
    double width;
    double height;

public:
    // Constructor allows negative dimensions, which is a robustness issue
    Rectangle(double w, double h) : width(w), height(h) {}

    // Const method to get area
    double getArea() const {
        return width * height;
    }

    // Accessors for demonstration
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    // Demonstrate with a mutable object
    Rectangle rect1(5.0, 4.0);
    std::cout << "Rectangle 1 (mutable): width=" << rect1.getWidth() << ", height=" << rect1.getHeight() << ", Area=" << rect1.getArea() << std::endl;

    // Demonstrate with a const object
    const Rectangle constRect(10.0, 2.5);
    std::cout << "Rectangle 2 (const): width=" << constRect.getWidth() << ", height=" << constRect.getHeight() << ", Area=" << constRect.getArea() << std::endl;

    // Demonstrate robustness issue: negative dimensions are allowed
    Rectangle rect3(-5.0, 4.0);
    std::cout << "Rectangle 3 (negative width): width=" << rect3.getWidth() << ", height=" << rect3.getHeight() << ", Area=" << rect3.getArea() << std::endl;

    const Rectangle constRect4(6.0, -3.0);
    std::cout << "Rectangle 4 (const, negative height): width=" << constRect4.getWidth() << ", height=" << constRect4.getHeight() << ", Area=" << constRect4.getArea() << std::endl;

    return 0;
}