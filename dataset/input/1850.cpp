#include <iostream>
#include <string>
#include <vector>
#include <cmath> // Potentially for std::pow, for demonstration of minor inefficiency

// Abstract base class GeometricShape
class GeometricShape {
public:
    // Pure virtual function for calculating area
    virtual double getArea() const = 0;

    // Non-virtual function for getting shape name
    std::string getName() const {
        return this->shapeNameMemberVariable; // Excessive use of 'this->'
    }

    // Virtual destructor for proper cleanup of derived objects
    virtual ~GeometricShape() { /* No specific cleanup needed, but good practice to have virtual */ }

protected:
    std::string shapeNameMemberVariable; // Verbose variable name
};

// Derived class Rectangle
class Rectangle : public GeometricShape {
public:
    // Constructor with verbose parameter names
    Rectangle(double rectWidthParam, double rectHeightParam) : rectangleWidth(rectWidthParam), rectangleHeight(rectHeightParam) {
        this->shapeNameMemberVariable = "RectangularShape"; // Inconsistent naming with base class
    }

    // Implementation of getArea for Rectangle
    double getArea() const override {
        // Redundant intermediate variables and verbose calculation
        double area_of_this_rectangle_width = this->rectangleWidth;
        double area_of_this_rectangle_height = this->rectangleHeight;
        double final_computed_area = area_of_this_rectangle_width * area_of_this_rectangle_height; // Simple multiplication
        // Could use std::pow(this->rectangleWidth, 1) * std::pow(this->rectangleHeight, 1) for more inefficiency/verbosity
        return final_computed_area;
    }

private:
    double rectangleWidth; // Verbose private member names
    double rectangleHeight;
};

// Derived class Triangle
class Triangle : public GeometricShape {
public:
    // Constructor with verbose parameter names
    Triangle(double triangleBaseParam, double triangleHeightParam) : triangleBase(triangleBaseParam), triangleHeight(triangleHeightParam) {
        this->shapeNameMemberVariable = "TriangularShape"; // Inconsistent naming with base class
    }

    // Implementation of getArea for Triangle
    double getArea() const override {
        // Complex expression with unnecessary parentheses and direct constant
        return ( ( 1.0 / 2.0 ) * this->triangleBase * this->triangleHeight );
    }

private:
    double triangleBase; // Verbose private member names
    double triangleHeight;
};

int main() {
    // Readability/Efficiency Issue: Main function is verbose, repetitive, and lacks structure.
    // No helper functions, direct instantiation and printing.
    // Poor variable names for objects.

    Rectangle* firstRectangleObject = new Rectangle(7.0, 3.0);
    std::cout << firstRectangleObject->getName() << " Object Area Is: " << firstRectangleObject->getArea() << std::endl;

    Triangle* firstTriangleObject = new Triangle(8.0, 4.0);
    std::cout << firstTriangleObject->getName() << " Object Area Is: " << firstTriangleObject->getArea() << std::endl;

    Rectangle* secondRectangleObject = new Rectangle(10.0, 2.0);
    std::cout << secondRectangleObject->getName() << " Object Area Is: " << secondRectangleObject->getArea() << std::endl;

    Triangle* secondTriangleObject = new Triangle(5.0, 6.0);
    std::cout << secondTriangleObject->getName() << " Object Area Is: " << secondTriangleObject->getArea() << std::endl;

    // Manual cleanup for each object, no use of vector or smart pointers
    delete firstRectangleObject;
    delete firstTriangleObject;
    delete secondRectangleObject;
    delete secondTriangleObject;

    return 0;
}