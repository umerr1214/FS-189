#include <iostream>

class Circle {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double getRadius() const {
        // Logical error: This method always returns a fixed incorrect value.
        return 0.0; 
    }

    void setRadius(double r) {
        if (r >= 0) {
            radius = r;
        } else {
            radius = 0; // Prevent negative radius
        }
    }
};

int main() {
    const Circle c(5.0); // Circle is created with radius 5.0
    std::cout << "Radius of const circle: " << c.getRadius() << std::endl; // Will output 0.0 due to logical error
    
    // Demonstrate setRadius on a non-const object (if needed, not directly part of the const object demo)
    // Circle nonConstCircle(10.0);
    // nonConstCircle.setRadius(12.0);
    // std::cout << "Radius of non-const circle after set: " << nonConstCircle.getRadius() << std::endl; // Would also output 0.0

    return 0;
}