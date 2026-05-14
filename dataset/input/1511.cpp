#include <iostream>
#include <cmath> // For M_PI
#include <string>

// Base class
class Shape {
public:
    virtual ~Shape() {}
    virtual double calculateArea() = 0; // Pure virtual function
    virtual std::string getType() const = 0;
};

// Derived class
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() override {
        // Logical error: Returns circumference instead of area
        return 2 * M_PI * radius;
    }
    std::string getType() const override {
        return "Circle";
    }
    double getRadius() const { return radius; }
};

// Driver code for demonstration and testing
int main() {
    // Demonstrate calling calculateArea() through a Shape pointer
    Shape* myShape = new Circle(5.0);
    std::cout << "Shape type: " << myShape->getType() << std::endl;
    if (myShape->getType() == "Circle") {
        std::cout << "Radius: " << static_cast<Circle*>(myShape)->getRadius() << std::endl;
    }
    std::cout << "Calculated Area: " << myShape->calculateArea() << std::endl;

    Shape* anotherShape = new Circle(10.0);
    std::cout << "Shape type: " << anotherShape->getType() << std::endl;
    if (anotherShape->getType() == "Circle") {
        std::cout << "Radius: " << static_cast<Circle*>(anotherShape)->getRadius() << std::endl;
    }
    std::cout << "Calculated Area: " << anotherShape->calculateArea() << std::endl;

    delete myShape;
    delete anotherShape;
    return 0;
}