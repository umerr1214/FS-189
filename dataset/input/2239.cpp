#include <iostream>
#include <string>
#include <memory> // For std::unique_ptr demonstration, though raw pointers are used to highlight the issue

// Base class Shape
class Shape {
protected:
    std::string color;
public:
    Shape(std::string c) : color(std::move(c)) { // Using std::move for efficiency if passed by value
        std::cout << "Shape constructor called for color: " << color << std::endl;
    }

    // A virtual function makes Shape a polymorphic base class
    virtual void printInfo() const {
        std::cout << "This is a Shape with color: " << color << std::endl;
    }

    // ROBUSTNESS ISSUE: Missing virtual destructor.
    // If a derived class object is deleted through a base class pointer,
    // and the base class destructor is not virtual, the derived class destructor
    // might not be called, leading to resource leaks or undefined behavior.
    ~Shape() {
        std::cout << "Shape destructor called for color: " << color << std::endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    // Constructor for Circle, initializes color via base class constructor and radius
    Circle(std::string c, double r) : Shape(std::move(c)), radius(r) {
        std::cout << "Circle constructor called for radius: " << radius << std::endl;
    }

    // Override the virtual printInfo function
    void printInfo() const override {
        std::cout << "This is a Circle with color: " << color << " and radius: " << radius << std::endl;
    }

    ~Circle() {
        std::cout << "Circle destructor called for radius: " << radius << std::endl;
        // If Circle had dynamic resources, they would be cleaned up here.
        // However, if Shape's destructor is not virtual, this destructor
        // might not be called when deleting via a Shape* pointer.
    }
};

int main() {
    std::cout << "--- Creating Circle object via base pointer ---" << std::endl;
    // Create a Circle object and manage it with a Shape pointer
    Shape* myShape = new Circle("Blue", 5.0);
    myShape->printInfo(); // Calls Circle's printInfo due to polymorphism

    std::cout << "--- Deleting object via base pointer (Robustness Issue) ---" << std::endl;
    // When deleting myShape, only the Shape destructor will be called because
    // Shape's destructor is not virtual. The Circle destructor will be skipped,
    // leading to a potential memory leak or undefined behavior if Circle had
    // its own dynamically allocated resources.
    delete myShape;
    myShape = nullptr; // Good practice to nullify pointer after deletion

    std::cout << "--- End of program ---" << std::endl;

    return 0;
}