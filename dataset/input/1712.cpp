#include <iostream>
#include <vector> // Still included, but not used for the main collection
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision
#include <string> // For basic type identification

// Define M_PI if not available
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class Shape
class Shape {
public:
    // READABILITY/EFFICIENCY ISSUE: calculateArea() is not marked 'const'.
    // It does not modify the object's state, so it should be a const method.
    virtual double calculateArea() = 0;
    virtual ~Shape() {} // Destructor is virtual, so no robustness issue here.
};

// Derived class Circle
class Circle : public Shape {
private:
    double rad; // READABILITY/EFFICIENCY ISSUE: Less descriptive variable name 'rad' instead of 'radius'.
public:
    Circle(double r) : rad(r) {}
    double calculateArea() override { // Not marked const
        return M_PI * rad * rad;
    }
};

// Derived class Square
class Square : public Shape {
private:
    double sde; // READABILITY/EFFICIENCY ISSUE: Less descriptive variable name 'sde' instead of 'side'.
public:
    Square(double s) : sde(s) {}
    double calculateArea() override { // Not marked const
        return sde * sde;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(4);

    // READABILITY/EFFICIENCY ISSUE: Using raw array and manual memory management instead of std::vector<Shape*>
    // and range-based for loops, which is more error-prone, verbose, and less idiomatic C++.
    const int numShapes = 3;
    Shape** shapeCollection = new Shape*[numShapes]; // Raw array of pointers

    shapeCollection[0] = new Circle(5.0);
    shapeCollection[1] = new Square(4.0);
    shapeCollection[2] = new Circle(2.5);

    std::cout << "Computing shape areas:\n";
    // READABILITY/EFFICIENCY ISSUE: Using traditional indexed loop instead of range-based for loop.
    for (int i = 0; i < numShapes; ++i) {
        Shape* currentShape = shapeCollection[i];
        std::string type;
        if (dynamic_cast<Circle*>(currentShape)) { // Verbose type checking
            type = "Circle";
        } else if (dynamic_cast<Square*>(currentShape)) {
            type = "Square";
        } else {
            type = "Unknown";
        }
        // READABILITY/EFFICIENCY ISSUE: Slightly more verbose output string construction.
        std::cout << type << " has an area of: " << currentShape->calculateArea() << "\n";
    }

    // Manual cleanup for raw array
    for (int i = 0; i < numShapes; ++i) {
        delete shapeCollection[i];
    }
    delete[] shapeCollection; // Don't forget to delete the array itself

    return 0;
}