#include <iostream>
#include <cmath> // For std::pow, std::atan
#include <iomanip> // For std::fixed, std::setprecision

class Circle {
private:
    double radius;

public:
    // Constructor initializes the radius with basic validation
    Circle(double r) {
        if (r > 0) {
            radius = r;
        } else {
            radius = 1.0; // Default to a positive radius if invalid input
        }
    }

    // Public method to set radius, only accepts positive values
    void setRadius(double r) {
        if (r > 0) {
            radius = r;
        }
        // If r is not positive, radius remains unchanged
    }

    // Public method to get area with efficiency/readability issues
    double getArea() {
        // Inefficient: PI is re-calculated every time this method is called
        const double MY_PI = std::atan(1.0) * 4.0; 
        // Less efficient and less readable than radius * radius
        return MY_PI * std::pow(radius, 2);
    }

    // Public method to get circumference with efficiency/readability issues
    double getCircumference() {
        // Inefficient: PI is re-calculated every time this method is called
        const double MY_PI = std::atan(1.0) * 4.0;
        return 2 * MY_PI * radius;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(5);

    // Test Case 1: Initial valid radius
    Circle c1(5.0);
    std::cout << "Circle 1 (radius 5.0):" << std::endl;
    std::cout << "  Area: " << c1.getArea() << std::endl;
    std::cout << "  Circumference: " << c1.getCircumference() << std::endl;

    // Test Case 2: Set new valid radius
    c1.setRadius(10.0);
    std::cout << "Circle 1 (radius 10.0):" << std::endl;
    std::cout << "  Area: " << c1.getArea() << std::endl;
    std::cout << "  Circumference: " << c1.getCircumference() << std::endl;

    // Test Case 3: Try to set invalid radius (negative)
    c1.setRadius(-2.0); // Should not change radius, remains 10.0
    std::cout << "Circle 1 (radius after invalid set -2.0):" << std::endl;
    std::cout << "  Area: " << c1.getArea() << std::endl;
    std::cout << "  Circumference: " << c1.getCircumference() << std::endl;

    // Test Case 4: Try to set invalid radius (zero)
    c1.setRadius(0.0); // Should not change radius, remains 10.0
    std::cout << "Circle 1 (radius after invalid set 0.0):" << std::endl;
    std::cout << "  Area: " << c1.getArea() << std::endl;
    std::cout << "  Circumference: " << c1.getCircumference() << std::endl;
    
    // Test Case 5: Another Circle with a different valid initial radius
    Circle c2(0.5);
    std::cout << "Circle 2 (radius 0.5):" << std::endl;
    std::cout << "  Area: " << c2.getArea() << std::endl;
    std::cout << "  Circumference: " << c2.getCircumference() << std::endl;

    // Test Case 6: Circle with invalid initial radius (constructor handles)
    Circle c3(-7.0); 
    std::cout << "Circle 3 (radius -7.0 initial):" << std::endl;
    std::cout << "  Area: " << c3.getArea() << std::endl;
    std::cout << "  Circumference: " << c3.getCircumference() << std::endl;

    // Test Case 7: Set valid radius for c3
    c3.setRadius(7.0);
    std::cout << "Circle 3 (radius 7.0 after set):" << std::endl;
    std::cout << "  Area: " << c3.getArea() << std::endl;
    std::cout << "  Circumference: " << c3.getCircumference() << std::endl;

    return 0;
}