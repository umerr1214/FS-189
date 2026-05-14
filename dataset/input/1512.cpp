#include <iostream>
#include <cmath> // For M_PI
#include <string>

// Base class
class Shape {
public:
    // Semantic error: Destructor is not virtual.
    // This can lead to undefined behavior/resource leaks when deleting derived objects via a base pointer.
    ~Shape() {}
    virtual double calculateArea() = 0; // Pure virtual function
    virtual std::string getType() const = 0;
};

// Derived class
class Circle : public Shape {
private:
    double radius;
    // For demonstration of potential memory leak, imagine Circle allocates dynamic memory
    int* data;
public:
    Circle(double r) : radius(r) {
        data = new int(100); // Allocate some memory
    }
    // Correctly implemented virtual destructor for Circle
    ~Circle() override {
        delete data; // Deallocate memory
        std::cout << "Circle destructor called." << std::endl;
    }
    double calculateArea() override {
        return M_PI * radius * radius;
    }
    std::string getType() const override {
        return "Circle";
    }
    double getRadius() const { return radius; }
};

// Driver code for demonstration and testing
int main() {
    // Demonstrate calling calculateArea() through a Shape pointer
    Shape* myShape = new Circle(5.0); // Circle object created, data allocated
    std::cout << "Shape type: " << myShape->getType() << std::endl;
    if (myShape->getType() == "Circle") {
        std::cout << "Radius: " << static_cast<Circle*>(myShape)->getRadius() << std::endl;
    }
    std::cout << "Calculated Area: " << myShape->calculateArea() << std::endl;

    // When delete is called on a base pointer to a derived object,
    // if the base destructor is not virtual, only the base destructor is called.
    // The derived class destructor (and its resource deallocation) is skipped.
    delete myShape; // This will only call Shape::~Shape(), leaking 'data' in Circle.
    std::cout << "---------------------------------" << std::endl;

    Shape* anotherShape = new Circle(10.0);
    std::cout << "Shape type: " << anotherShape->getType() << std::endl;
    if (anotherShape->getType() == "Circle") {
        std::cout << "Radius: " << static_cast<Circle*>(anotherShape)->getRadius() << std::endl;
    }
    std::cout << "Calculated Area: " << anotherShape->calculateArea() << std::endl;
    delete anotherShape; // Same issue here.

    return 0;
}