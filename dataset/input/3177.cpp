#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr

// Base class Shape
class Shape {
public:
    // Pure virtual draw method, making Shape an abstract class.
    // `const` correctness applied as draw does not modify the object state.
    virtual void draw() const = 0;

    // Virtual destructor is crucial for correct polymorphic deletion.
    // Using `= default` for a simple destructor is good practice.
    virtual ~Shape() = default;
};

// Derived class Circle
class Circle : public Shape {
public:
    // `override` keyword ensures that the method correctly overrides a base class method.
    // `const` correctness matches the base class declaration.
    void draw() const override {
        std::cout << "Drawing a Circle.\n"; // Efficient use of '\n'
    }
    // Explicit destructor (optional if default is sufficient, but good for demonstration)
    ~Circle() override {
        // No specific resources to clean up beyond base class
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    // `override` keyword and `const` correctness.
    void draw() const override {
        std::cout << "Drawing a Rectangle.\n"; // Efficient use of '\n'
    }
    // Explicit destructor
    ~Rectangle() override {
        // No specific resources to clean up beyond base class
    }
};

// Function to demonstrate polymorphism
void run_demo() {
    // Use std::vector of std::unique_ptr for robust, automatic memory management.
    // This adheres to RAII (Resource Acquisition Is Initialization) principle.
    std::vector<std::unique_ptr<Shape>> shapes_collection;

    // Add Circle and Rectangle objects to the collection.
    // std::make_unique is the preferred way to create unique_ptr.
    shapes_collection.push_back(std::make_unique<Circle>());
    shapes_collection.push_back(std::make_unique<Rectangle>());

    // Demonstrate polymorphism by iterating and calling draw() on each Shape.
    // Use a range-based for loop for clear and concise iteration.
    for (const auto& shape_ptr : shapes_collection) {
        shape_ptr->draw(); // Polymorphic call
    }

    // Memory is automatically managed by std::unique_ptr when shapes_collection goes out of scope.
    // No explicit delete calls are needed, preventing memory leaks and simplifying code.
}

int main() {
    run_demo();
    return 0;
}