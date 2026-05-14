#include <iostream>
#include <cmath> // For M_PI

// Base Shape class
class Shape {
public:
    // SEMANTIC ERROR: calculateArea is NOT virtual.
    // This prevents runtime polymorphism for this method.
    // It must have an implementation if not pure virtual.
    double calculateArea() const {
        std::cout << "(Shape's default area calculation) ";
        return 0.0; // Default implementation
    }
    virtual ~Shape() {} // Destructor should still be virtual for proper cleanup
};

// Circle class from Q7
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // This calculateArea() now *hides* Shape's calculateArea(), doesn't override it.
    // Removed 'override' keyword as it would cause a compilation error if used here.
    double calculateArea() const {
        return M_PI * radius * radius;
    }
};

// Rectangle class derived from Shape
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    // This calculateArea() now *hides* Shape's calculateArea(), doesn't override it.
    // Removed 'override' keyword as it would cause a compilation error if used here.
    double calculateArea() const {
        return length * width;
    }
};

// Function demonstrating (attempted) runtime polymorphism
void demonstratePolymorphism(Shape* shapePtr) {
    std::cout << "Calling calculateArea() via Shape pointer." << std::endl;
    // Due to non-virtual calculateArea() in Shape, this will always call Shape::calculateArea()
    // leading to a semantic error where polymorphism is expected but not achieved.
    std::cout << "Calculated Area: " << shapePtr->calculateArea() << std::endl;
}

int main() {
    Circle myCircle(5.0);
    Rectangle myRectangle(4.0, 6.0);

    std::cout << "Demonstrating with Circle (radius=5.0):" << std::endl;
    demonstratePolymorphism(&myCircle); // Will print 0.0 from Shape::calculateArea()

    std::cout << "\nDemonstrating with Rectangle (length=4.0, width=6.0):" << std::endl;
    demonstratePolymorphism(&myRectangle); // Will print 0.0 from Shape::calculateArea()

    return 0;
}