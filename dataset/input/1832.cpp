#include <iostream>
#include <string>

// Base class definition
class Shape {
protected:
    std::string color; // Protected member

public:
    // Constructor for Shape - takes color by value (inefficient copy)
    Shape(std::string c) : color(c) { // c is copied here
        // Potentially another copy/move if c is an rvalue
    }

    // Public method to display the color - not const, inefficient string concatenation
    void displayColor() { // Not marked const
        // Creates a temporary std::string by concatenation, then prints it (inefficient)
        std::cout << (std::string("Color: ") + color) << std::endl;
    }
};

// Derived class definition
class ColoredCircle : public Shape {
private:
    double radius;

public:
    // Constructor for ColoredCircle - takes color by value (inefficient copy)
    // Passes 'c' by value to Shape's constructor, potentially leading to two copies/moves
    ColoredCircle(double r, std::string c) : Shape(c), radius(r) { // 'c' is copied here, then passed by value to Shape's constructor
    }

    // Method to directly access and modify the protected color member - takes newColor by value
    void changeColor(std::string newColor) { // newColor is copied here
        color = newColor; // Direct access to protected member
    }

    // Other methods specific to ColoredCircle
    double getRadius() {
        return radius;
    }
};

int main() {
    // Create a ColoredCircle object, passing color by value
    ColoredCircle myCircle(5.0, "Red");
    std::cout << "Initial color:" << std::endl;
    myCircle.displayColor(); // Output: Color: Red

    // Change the protected color member directly from the derived class, passing by value
    myCircle.changeColor("Green");
    std::cout << "After changing color to Green:" << std::endl;
    myCircle.displayColor(); // Output: Color: Green

    return 0;
}