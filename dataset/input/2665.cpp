#include <iostream>
#include <string>

// Abstract base class Shape
class Shape {
public:
    Shape() {
        std::cout << "Shape constructor called.\n";
    }
    // Non-virtual destructor in the base class - this is the source of the robustness issue
    ~Shape() {
        std::cout << "Shape destructor called.\n";
    }

    virtual void printInfo() const = 0; // Pure virtual function
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {
        std::cout << "Circle constructor called with radius " << radius << ".\n";
    }
    ~Circle() override { // The 'override' keyword is good practice, but doesn't make it virtual if base is not
        std::cout << "Circle destructor called.\n";
    }

    void printInfo() const override {
        std::cout << "I am a Circle with radius " << radius << ".\n";
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {
        std::cout << "Rectangle constructor called with width " << width << " and height " << height << ".\n";
    }
    ~Rectangle() override { // The 'override' keyword is good practice, but doesn't make it virtual if base is not
        std::cout << "Rectangle destructor called.\n";
    }

    void printInfo() const override {
        std::cout << "I am a Rectangle with width " << width << " and height " << height << ".\n";
    }
};

int main() {
    std::cout << "--- Demonstrating Robustness Issue (Non-virtual base destructor) ---\n";
    std::cout << "Creating a Circle object via Shape*:\n";
    Shape* myCircle = new Circle(5.0);
    myCircle->printInfo();
    std::cout << "Deleting the Circle object via Shape*...\n";
    // When deleting through a base class pointer with a non-virtual destructor,
    // only the base class destructor is called. The derived class destructor is skipped.
    // This leads to a memory leak if the derived class manages resources, and undefined behavior.
    delete myCircle;
    std::cout << "Deletion attempted. Notice the Circle destructor was NOT called.\n\n";

    std::cout << "Creating a Rectangle object via Shape*:\n";
    Shape* myRectangle = new Rectangle(4.0, 6.0);
    myRectangle->printInfo();
    std::cout << "Deleting the Rectangle object via Shape*...\n";
    delete myRectangle;
    std::cout << "Deletion attempted. Notice the Rectangle destructor was NOT called.\n\n";

    std::cout << "--- Consequences Explained ---\n";
    std::cout << "If the base class `Shape`'s destructor is not virtual, deleting a derived object (like `Circle` or `Rectangle`)\n";
    std::cout << "through a base class pointer (`Shape*`) results in undefined behavior. Specifically, the derived class's destructor\n";
    std::cout << "(e.g., `~Circle()` or `~Rectangle()`) will NOT be called. This means any resources managed by the derived class\n";
    std::cout << "(e.g., dynamically allocated memory, file handles) will not be properly released, leading to resource leaks.\n";
    std::cout << "In this example, you can see that only the `Shape` destructor prints, but not the `Circle` or `Rectangle` destructors,\n";
    std::cout << "even though they were dynamically allocated as `Circle` and `Rectangle` objects.\n";

    return 0;
}