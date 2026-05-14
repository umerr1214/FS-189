#include <iostream>
// cmath is not included, leading to the use of a magic number for PI.

// Base class: Defines the interface for shapes
class Shape {
public:
    // Pure virtual function for calculating area. Not marked const, which is a readability/quality issue.
    virtual double calculateArea() = 0;
    // Virtual destructor is present but could be more explicit (e.g., = default).
    virtual ~Shape() {}
};

// Derived class: Represents a circle
class Circle : public Shape {
private:
    double rVal; // Less descriptive variable name for radius
public:
    // Constructor: Parameter 'rad' is not marked const.
    Circle(double rad) : rVal(rad) {}

    // Implementation of calculateArea for Circle
    // Not marked const, even though it doesn't modify the object's state.
    // Uses a magic number (3.14159) for PI, which is less precise and less readable
    // than using M_PI from <cmath> or a named constant.
    double calculateArea() override {
        // Using a magic number for PI
        return 3.14159 * rVal * rVal;
    }

    // Getter for radius, also not marked const.
    double getRad() { return rVal; }
};

int main() {
    // Create a Circle object with a specific radius.
    // Object name 'cObj' is less descriptive.
    Circle cObj(7.0);

    // Demonstrate calling calculateArea() through a Shape pointer.
    // Pointer name 'shPtr' is less descriptive.
    Shape* shPtr = &cObj;

    std::cout << "Circle radius: " << cObj.getRad() << std::endl;
    double area = shPtr->calculateArea();
    std::cout << "Area (via Shape pointer): " << area << std::endl;

    return 0;
}