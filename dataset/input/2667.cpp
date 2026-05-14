#include <iostream>
#include <string>
#include <vector> // Using vector for a clean demonstration of multiple objects

// Abstract base class Shape
class Shape {
public:
    Shape() {
        std::cout << "Shape constructor called.\n";
    }
    // Virtual destructor: Essential for proper polymorphic destruction
    virtual ~Shape() {
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
    ~Circle() override {
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
    ~Rectangle() override {
        std::cout << "Rectangle destructor called.\n";
    }

    void printInfo() const override {
        std::cout << "I am a Rectangle with width " << width << " and height " << height << ".\n";
    }
};

int main() {
    std::cout << "--- Demonstrating Correct Polymorphic Destruction (Virtual Destructor) ---\n";

    std::cout << "\n--- Case 1: Deleting a dynamically allocated Circle via Shape* ---\n";
    Shape* myCircle = new Circle(5.0); // Create a Circle object
    myCircle->printInfo();             // Use polymorphic behavior
    std::cout << "Deleting myCircle via Shape*...\n";
    delete myCircle;                   // Polymorphic destruction: ~Circle() then ~Shape()
    std::cout << "Circle object deleted.\n";

    std::cout << "\n--- Case 2: Deleting a dynamically allocated Rectangle via Shape* ---\n";
    Shape* myRectangle = new Rectangle(4.0, 6.0); // Create a Rectangle object
    myRectangle->printInfo();                     // Use polymorphic behavior
    std::cout << "Deleting myRectangle via Shape*...\n";
    delete myRectangle;                           // Polymorphic destruction: ~Rectangle() then ~Shape()
    std::cout << "Rectangle object deleted.\n";

    std::cout << "\n--- Case 3: Using a vector of Shape pointers for multiple objects ---\n";
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(2.5));
    shapes.push_back(new Rectangle(3.0, 7.0));
    shapes.push_back(new Circle(1.0));

    std::cout << "Displaying info for all shapes in the vector:\n";
    for (const auto& shape_ptr : shapes) {
        shape_ptr->printInfo();
    }

    std::cout << "\nDeleting all shapes in the vector:\n";
    // Iterate and delete each dynamically allocated object
    for (Shape* shape_ptr : shapes) {
        std::cout << "Deleting a shape...\n";
        delete shape_ptr; // Correctly calls derived destructor then base destructor
    }
    shapes.clear(); // Clear the vector after deleting contents

    std::cout << "\n--- Explanation of Consequences if Destructor were NOT Virtual ---\n";
    std::cout << "If the `Shape` base class destructor were not virtual, deleting a derived object\n";
    std::cout << "(e.g., `Circle` or `Rectangle`) through a base class pointer (`Shape*`) would lead to\n";
    std::cout << "undefined behavior. Specifically, only the `Shape` destructor would be called,\n";
    std::cout << "and the derived class's destructor (`~Circle()` or `~Rectangle()`) would be skipped.\n";
    std::cout << "This is problematic because derived classes often manage their own resources (e.g.,\n";
    std::cout << "dynamically allocated memory, file handles, network connections). Failing to call\n";
    std::cout << "the derived destructor would result in these resources not being properly released,\n";
    std::cout << "causing resource leaks (like memory leaks) and potentially program instability.\n";
    std::cout << "By making the base class destructor `virtual`, C++ ensures that the entire object\n";
    std::cout << "hierarchy is correctly unwound and all resources are deallocated, preserving resource integrity.\n";

    return 0;
}