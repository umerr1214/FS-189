#include <iostream>
#include <string>

// Base class definition
class Shape {
protected:
    std::string color; // Protected member

public:
    // Constructor for Shape - takes color by const reference for efficiency
    Shape(const std::string& c) : color(c) {}

    // Public method to display the color - marked const as it doesn't modify the object
    void displayColor() const {
        std::cout << "Color: " << color << std::endl;
    }
};

// Derived class definition
class ColoredCircle : public Shape {
private:
    double radius;

public:
    // Constructor for ColoredCircle - explicitly calls base class constructor
    // and takes color by const reference for efficiency
    ColoredCircle(double r, const std::string& c) : Shape(c), radius(r) {
        // The base class constructor handles the initialization of 'color'
    }

    // Method to directly access and modify the protected color member
    // Takes newColor by const reference for efficiency
    void updateColor(const std::string& newColor) {
        color = newColor; // Direct access to protected member
    }

    // Other methods specific to ColoredCircle
    double getRadius() const {
        return radius;
    }
};

int main() {
    // Create a ColoredCircle object, initializing with a color
    ColoredCircle myCircle(5.0, "Red");
    std::cout << "Initial color:" << std::endl;
    myCircle.displayColor(); // Output: Color: Red

    // Modify the protected color member directly from the derived class
    myCircle.updateColor("Green");
    std::cout << "After updating color to Green:" << std::endl;
    myCircle.displayColor(); // Output: Color: Green

    // Confirm that a const ColoredCircle can still display its color
    const ColoredCircle anotherCircle(10.0, "Yellow");
    std::cout << "Another circle's color:" << std::endl;
    anotherCircle.displayColor(); // Output: Color: Yellow

    return 0;
}