#include <iostream>
#include <cmath> // For M_PI

// Syntax Error: Typo in 'class' keyword
clas Circle {
private:
    double radius;

public:
    Circle(double r = 0.0) {
        setRadius(r);
    }

    double getRadius() const {
        return radius;
    }

    void setRadius(double r) {
        if (r >= 0) {
            radius = r;
        } else {
            std::cout << "Radius cannot be negative. Setting to 0." << std::endl;
            radius = 0.0;
        }
    }

    double calculateArea() const {
        return M_PI * radius * radius;
    }
};

int main() {
    Circle c1;
    std::cout << "Initial radius: " << c1.getRadius() << ", Area: " << c1.calculateArea() << std::endl;

    c1.setRadius(5.0);
    std::cout << "Radius after set(5.0): " << c1.getRadius() << ", Area: " << c1.calculateArea() << std::endl;

    c1.setRadius(-2.0); // Test negative input
    std::cout << "Radius after set(-2.0): " << c1.getRadius() << ", Area: " << c1.calculateArea() << std::endl;

    Circle c2(10.0);
    std::cout << "Circle c2 radius: " << c2.getRadius() << ", Area: " << c2.calculateArea() << std::endl;

    return 0;
}