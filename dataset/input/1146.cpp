#include <iostream>
#include <vector>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed and std::setprecision

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getRadius() {
        return radius;
    }

    double calculateArea() {
        return M_PI * radius * radius;
    }
};

int main() {
    std::vector<double> testRadii = {1.0, 2.5, 0.0, 10.0};
    for (double r : testRadii) {
        Circle c(r);
        // SEMANTIC ERROR: Attempting to directly access private member 'radius'
        // This will result in a compilation error related to access control.
        std::cout << "Circle with radius: " << std::fixed << std::setprecision(2) << c.radius << std::endl; // Should use c.getRadius()
        std::cout << "Area: " << std::fixed << std::setprecision(5) << c.calculateArea() << std::endl;
        std::cout << "---" << std::endl;
    }
    return 0;
}