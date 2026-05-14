#include <iostream>

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const {
        // Logical error: Area calculation is incorrect (addition instead of multiplication)
        return width + height;
    }

    void printInfo() const {
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }
};

int main() {
    Rectangle r1(10.0, 5.0);
    const Rectangle const_r1(7.0, 3.0);

    std::cout << "Area of r1 (expected 50.0): " << r1.getArea() << std::endl;
    std::cout << "Area of const_r1 (expected 21.0): " << const_r1.getArea() << std::endl;

    // The getArea() method is correctly declared const and does not modify state,
    // but the calculated area itself is logically flawed.

    return 0;
}