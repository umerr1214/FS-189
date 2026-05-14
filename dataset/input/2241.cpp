#include <iostream>
#include <string>
#include <utility> // For std::move if needed, though const& makes it less critical for parameters

// Base class Shape
class Shape {
protected:
    std::string color;
public:
    // Correct and efficient constructor: takes const reference, initializes via initializer list.
    Shape(const std::string& c) : color(c) {
        std::cout << "Shape constructor called for color: " << color << std::endl;
    }

    // Virtual destructor: Essential for polymorphic base classes to ensure proper cleanup
    // of derived objects when deleted through a base class pointer.
    virtual ~Shape() {
        std::cout << "Shape destructor called for color: " << color << std::endl;
    }

    // Virtual function to demonstrate polymorphism and good practice.
    virtual void printInfo() const {
        std::cout << "This is a Shape with color: " << color << std::endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    // Correct and efficient constructor for Circle:
    // - Takes const reference for color to avoid unnecessary copies.
    // - Initializes base class `Shape` using initializer list.
    // - Initializes `radius` using initializer list.
    Circle(const std::string& c, double r) : Shape(c), radius(r) {
        std::cout << "Circle constructor called for radius: " << radius << std::endl;
    }

    // Override the virtual printInfo function for specific Circle behavior.
    void printInfo() const override {
        std::cout << "This is a Circle with color: " << color << " and radius: " << radius << std::endl;
    }

    // Destructor for Circle. Will be called correctly due to virtual base destructor.
    ~Circle() override { // `override` is good practice
        std::cout << "Circle destructor called for radius: " << radius << std::endl;
    }
};

int main() {
    std::cout << "--- Creating Circle object directly ---" << std::endl;
    Circle myCircle("Green", 7.5);
    myCircle.printInfo();

    std::cout << "--- Creating Circle object via base pointer (polymorphism) ---" << std::endl;
    // Using std::unique_ptr for safe memory management, which correctly handles
    // polymorphic deletion because Shape has a virtual destructor.
    std::unique_ptr<Shape> anotherShape = std::make_unique<Circle>("Yellow", 2.0);
    anotherShape->printInfo(); // Calls Circle's printInfo

    // anotherShape is automatically deleted when it goes out of scope,
    // and due to virtual destructor, both Circle and Shape destructors are called.

    std::cout << "--- End of program ---" << std::endl;

    return 0;
}