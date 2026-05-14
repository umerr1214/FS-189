#include <iostream>
#include <string>

// Base class definition
class Shape {
protected:
    std::string color; // Protected member

public:
    // Default constructor for Shape - does not initialize color
    Shape() {}

    // Public method to display the color
    void displayColor() {
        if (color.empty()) {
            std::cout << "Color: [Not Set]" << std::endl; // Robustness issue: handles empty color explicitly
        } else {
            std::cout << "Color: " << color << std::endl;
        }
    }
};

// Derived class definition
class ColoredCircle : public Shape {
private:
    double radius;

public:
    // Constructor for ColoredCircle - relies on default Shape constructor
    // and then uses direct access to modify the protected color.
    ColoredCircle(double r) : radius(r) {
        // `color` is default-constructed by Shape's default constructor here.
        // We could set a default color here, but for robustness demo, we won't.
    }

    // Method to directly access and modify the protected color member
    void setColor(const std::string& newColor) {
        color = newColor; // Direct access to protected member
    }

    // Other methods specific to ColoredCircle could go here
    double getRadius() const {
        return radius;
    }
};

int main() {
    // Demonstrate robustness issue: calling displayColor when color is not explicitly set
    ColoredCircle myCircle(5.0);
    std::cout << "Initial state:" << std::endl;
    myCircle.displayColor(); // Output: Color: [Not Set]

    // Modify the protected color member directly from the derived class
    myCircle.setColor("Blue");
    std::cout << "After setting color to Blue:" << std::endl;
    myCircle.displayColor(); // Output: Color: Blue

    // Demonstrate another robustness scenario: setting color to an empty string
    myCircle.setColor("");
    std::cout << "After setting color to an empty string:" << std::endl;
    myCircle.displayColor(); // Output: Color: [Not Set]

    return 0;
}