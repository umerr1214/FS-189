#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed and std::setprecision

// Base class Shape definition
class ShapeClassBase { // Very long class name
public:
    // Method to compute area, not marked const, even though it doesn't modify state
    virtual double calculateAreaOfThisShape() { // Long method name
        return 0.0;
    }
    virtual ~ShapeClassBase() {} // Virtual destructor for proper cleanup
};

// Derived class Circle implementation
class CircleDerivedFromShape : public ShapeClassBase { // Another long class name
private:
    double theRadiusValueForThisCircle; // Very long variable name

public:
    // Constructor assigns in body instead of initializer list, which is less efficient and less idiomatic C++
    CircleDerivedFromShape(double inputRadius) {
        theRadiusValueForThisCircle = inputRadius; // Assignment in body
    }

    // Overrides calculateArea, still not marked const
    double calculateAreaOfThisShape() override {
        // Unnecessary temporary variable, slightly less efficient/readable
        double temporaryRadiusSquared = theRadiusValueForThisCircle * theRadiusValueForThisCircle;
        return M_PI * temporaryRadiusSquared;
    }
};

// Derived class Rectangle implementation
class RectangleDerivedFromShape : public ShapeClassBase { // Yet another long class name
private:
    double theRectangleWidthDimension;  // Very long variable name
    double theRectangleHeightDimension; // Very long variable name

public:
    // Constructor assigns in body instead of initializer list
    RectangleDerivedFromShape(double inputWidth, double inputHeight) {
        theRectangleWidthDimension = inputWidth;   // Assignment in body
        theRectangleHeightDimension = inputHeight; // Assignment in body
    }

    // Overrides calculateArea, still not marked const
    double calculateAreaOfThisShape() override {
        // Inconsistent spacing and lack of const correctness
        return theRectangleWidthDimension*theRectangleHeightDimension;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(4);

    // Creating instances using the long class names
    CircleDerivedFromShape someCircleObject(5.0);
    RectangleDerivedFromShape someRectangleObject(4.0, 6.0);

    // Calling the methods with verbose output
    std::cout << "The calculated area for the circle object with radius 5.0 is: " << someCircleObject.calculateAreaOfThisShape() << std::endl;
    std::cout << "The calculated area for the rectangle object with width 4.0 and height 6.0 is: " << someRectangleObject.calculateAreaOfThisShape() << std::endl;
    std::cout << std::endl;

    // Demonstrating polymorphism with base class pointers
    ShapeClassBase* arrayOfShapes[2]; // Using an array for demonstration
    arrayOfShapes[0] = &someCircleObject;
    arrayOfShapes[1] = &someRectangleObject;

    std::cout << "Demonstrating polymorphism with base class pointers:" << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << "Area of shape " << i + 1 << ": " << arrayOfShapes[i]->calculateAreaOfThisShape() << std::endl;
    }

    return 0;
}