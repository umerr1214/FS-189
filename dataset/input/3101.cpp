#include <iostream>
#include <cmath> // For M_PI

// Define M_PI if not already defined (common on some compilers/platforms)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Logical error: This method calculates circumference instead of area.
    double getArea() const {
        return 2 * M_PI * radius; // Should be M_PI * radius * radius
    }

    void resize(double newRadius) {
        if (newRadius >= 0) {
            radius = newRadius;
        }
    }

    double getRadius() const {
        return radius;
    }
};

int main() {
    Circle c1(5.0);
    std::cout << "Initial Circle (c1): Radius = " << c1.getRadius() << ", Area = " << c1.getArea() << std::endl;

    c1.resize(7.0);
    std::cout << "Resized Circle (c1): Radius = " << c1.getRadius() << ", Area = " << c1.getArea() << std::endl;

    const Circle c2(10.0);
    std::cout << "Const Circle (c2): Radius = " << c2.getRadius() << ", Area = " << c2.getArea() << std::endl;

    return 0;
}