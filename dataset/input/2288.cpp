#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class Rectangle {
private:
    double width_val; // Slightly less descriptive name
    double height_val; // Slightly less descriptive name

public:
    Rectangle(double w, double h) : width_val(w), height_val(h) {}

    // Const method to get area - verbose with unnecessary temp variable
    double getArea() const {
        double temp_result = width_val * height_val; // Unnecessary intermediate variable
        return temp_result;
    }

    // Accessors for demonstration
    double getWidth() const { return width_val; }
    double getHeight() const { return height_val; }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    // Mutable object demo
    Rectangle myRect(7.5, 3.0);
    std::cout << "Mutable Rect Dims: " << myRect.getWidth() << "x" << myRect.getHeight() << " Area: " << myRect.getArea() << std::endl;

    // Const object demo
    const Rectangle constMyRect(12.0, 5.0);
    std::cout << "Const Rect Dims: " << constMyRect.getWidth() << "x" << constMyRect.getHeight() << " Area: " << constMyRect.getArea() << std::endl;

    // Another const object with zero dimension
    const Rectangle zeroRect(0.0, 10.0);
    std::cout << "Zero Width Rect Dims: " << zeroRect.getWidth() << "x" << zeroRect.getHeight() << " Area: " << zeroRect.getArea() << std::endl;

    return 0;
}