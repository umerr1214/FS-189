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
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    std::vector<double> testRadii = {1.0, 2.5, 0.0, 10.0};
    for (double r : testRadii) {
        // This line will likely cause a compilation error due to the missing semicolon above
        Circle c(r); 
        std::cout << "Circle with radius: " << std::fixed << std::setprecision(2) << c.getRadius() << std::endl;
        std::cout << "Area: " << std::fixed << std::setprecision(5) << c.calculateArea() << std::endl;
        std::cout << "---" << std::endl;
    }
    return 0;
}