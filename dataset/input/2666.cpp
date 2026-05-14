#include <iostream>
#include <string>
#include <vector> // Using vector for a slightly more complex (and thus less efficient/readable) demonstration

// Abstract base class Shape
class Shape {
public:
    Shape() {
        std::cout << "Shape constructor called.\n";
    }
    // Virtual destructor - this correctly solves the core problem, but the demonstration is verbose.
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
        // This printInfo is a bit more verbose than necessary, adding to readability issues
        std::cout << "  Detailed Circle Info: I am a Circle object. My radius is " << radius << " units.\n";
        std::cout << "  Calculating circumference (2*PI*R): " << (2 * 3.14159 * radius) << " units.\n";
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
        // This printInfo is also more verbose than necessary
        std::cout << "  Detailed Rectangle Info: I am a Rectangle object. My dimensions are " << width << " by " << height << " units.\n";
        std::cout << "  Calculating area (W*H): " << (width * height) << " square units.\n";
    }
};

int main() {
    std::cout << "--- Demonstrating Readability/Efficiency Issue (Verbose/Repetitive Demo) ---\n";
    std::cout << "Starting the demonstration of polymorphic destruction with a virtual destructor.\n\n";

    // First example: A Circle
    std::cout << "Phase 1: Working with a dynamically allocated Circle.\n";
    std::cout << "Allocating memory for a new Circle object and assigning to Shape*.\n";
    Shape* currentShape1 = new Circle(7.5);
    std::cout << "Calling printInfo() on the Circle via Shape*:\n";
    currentShape1->printInfo();
    std::cout << "Now, preparing to delete the first shape. This should call both destructors.\n";
    delete currentShape1;
    std::cout << "Finished deleting the first shape (Circle).\n\n";

    // Second example: A Rectangle
    std::cout << "Phase 2: Working with a dynamically allocated Rectangle.\n";
    std::cout << "Allocating memory for a new Rectangle object and assigning to Shape*.\n";
    Shape* currentShape2 = new Rectangle(10.0, 4.0);
    std::cout << "Calling printInfo() on the Rectangle via Shape*:\n";
    currentShape2->printInfo();
    std::cout << "Now, preparing to delete the second shape. This should call both destructors.\n";
    delete currentShape2;
    std::cout << "Finished deleting the second shape (Rectangle).\n\n";

    // Third example: Another Circle, demonstrating redundancy
    std::cout << "Phase 3: Repeating the process with another Circle, for a thorough demonstration.\n";
    std::cout << "Allocating memory for yet another Circle object.\n";
    Shape* currentShape3 = new Circle(3.0);
    std::cout << "Calling printInfo() on this Circle:\n";
    currentShape3->printInfo();
    std::cout << "Time to delete the third shape. Expecting correct destructor calls.\n";
    delete currentShape3;
    std::cout << "Finished deleting the third shape (another Circle).\n\n";

    // Using a vector to show another way, but still with verbose output
    std::cout << "Phase 4: Using a vector of Shape pointers for more shapes, still verbose.\n";
    std::vector<Shape*> shapesCollection;
    shapesCollection.push_back(new Circle(2.0));
    shapesCollection.push_back(new Rectangle(2.0, 2.0));
    shapesCollection.push_back(new Circle(1.0));

    std::cout << "Iterating through the collection and printing info:\n";
    for (const auto& shape_ptr : shapesCollection) {
        shape_ptr->printInfo();
    }
    std::cout << "\nNow, deleting all shapes in the collection one by one, with individual messages.\n";
    for (size_t i = 0; i < shapesCollection.size(); ++i) {
        std::cout << "  Deleting shape at index " << i << "...\n";
        delete shapesCollection[i];
        shapesCollection[i] = nullptr; // Good practice, but adds verbosity to the demo
        std::cout << "  Shape at index " << i << " deleted.\n";
    }
    std::cout << "All shapes in the collection have been processed and deleted.\n\n";

    std::cout << "--- Explanation of Consequences (Verbosity persists) ---\n";
    std::cout << "The importance of a virtual destructor in the base class `Shape` is paramount for proper polymorphic destruction.\n";
    std::cout << "If the destructor were not virtual, as demonstrated in a previous example (or if we imagine it here),\n";
    std::cout << "then when `delete` is called on a `Shape*` that points to a `Circle` or `Rectangle` object,\n";
    std::cout << "only the `Shape` class's destructor would be invoked. This would bypass the derived class's destructor.\n";
    std::cout << "Derived classes often manage specific resources (e.g., dynamically allocated arrays, file handles, network connections).\n";
    std::cout << "Failing to call the derived destructor would lead to these resources not being properly released, resulting in\n";
    std::cout << "resource leaks (e.g., memory leaks) and potentially other forms of undefined behavior or program instability.\n";
    std::cout << "By making the base class destructor `virtual`, the C++ runtime ensures that the correct destructor for the actual\n";
    std::cout << "object type (e.g., `~Circle()` then `~Shape()`) is called, ensuring all resources are properly cleaned up.\n";
    std::cout << "This program correctly implements the virtual destructor, but the demonstration is quite verbose and repetitive.\n";

    return 0;
}