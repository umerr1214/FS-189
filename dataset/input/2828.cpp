#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision

// Using a global non-const float variable for PI, which is less precise than double
// and generally considered poor practice for constants.
float PI_VALUE = 3.14159f; 

class Circle {
private:
    double r; // Using a less descriptive variable name ('r' instead of 'radius')
public:
    // Default constructor: sets radius to 1.0
    // Uses assignment in the constructor body instead of an initializer list,
    // which is less efficient for complex types (though negligible for double) and less idiomatic C++.
    Circle() {
        r = 1.0;
    }

    // Overloaded constructor: takes a double argument for the radius
    // Uses a less descriptive parameter name ('val' instead of 'radius' or 'r').
    // Uses assignment in the constructor body.
    Circle(double val) {
        r = val;
    }

    // Method to calculate area
    // Lacks the 'const' qualifier, which means it cannot be called on const Circle objects
    // and incorrectly suggests it might modify the object's state (even though it doesn't).
    double calculateArea() { // Missing const
        // Casting PI_VALUE to double here is a minor inefficiency and reduces readability
        return static_cast<double>(PI_VALUE) * r * r;
    }

    // Getter for radius for testing
    double getRadius() const {
        return r;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(5);

    // Test Case 1: Default circle
    Circle c1;
    std::cout << "Circle 1 (default, radius=" << c1.getRadius() << "): Area = " << c1.calculateArea() << std::endl;

    // Test Case 2: Positive radius
    Circle c2(5.0);
    std::cout << "Circle 2 (radius=" << c2.getRadius() << "): Area = " << c2.calculateArea() << std::endl;

    // Test Case 3: Zero radius
    Circle c3(0.0);
    std::cout << "Circle 3 (radius=" << c3.getRadius() << "): Area = " << c3.calculateArea() << std::endl;

    // Test Case 4: Another positive radius
    Circle c4(2.5);
    std::cout << "Circle 4 (radius=" << c4.getRadius() << "): Area = " << c4.calculateArea() << std::endl;

    // Test Case 5: Negative radius (functionally works, but not the focus of this error type)
    Circle c5(-3.0);
    std::cout << "Circle 5 (radius=" << c5.getRadius() << "): Area = " << c5.calculateArea() << std::endl;

    return 0;
}