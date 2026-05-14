#include <iostream>
#include <vector>
#include <string>

// Base class
class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a generic shape." << std::endl;
    }
    virtual ~Shape() {
        std::cout << "Shape destructor called." << std::endl;
    }
};

// Derived class Circle
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle with radius X." << std::endl; // Logical error: prints generic info
    }
    ~Circle() override {
        std::cout << "Circle destructor called." << std::endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Rectangle with width Y and height Z." << std::endl; // Logical error: prints generic info
    }
    ~Rectangle() override {
        std::cout << "Rectangle destructor called." << std::endl;
    }
};

int main() {
    // Array of Shape pointers
    std::vector<Shape*> shapes;

    shapes.push_back(new Circle());
    shapes.push_back(new Rectangle());
    shapes.push_back(new Circle());

    // Demonstrate polymorphism
    for (const auto& shape : shapes) {
        shape->draw();
    }

    // Logical error: Forgetting to clean up dynamically allocated memory
    // The objects created with 'new' are never 'delete'd, leading to a memory leak.
    // Correct cleanup would be:
    // for (const auto& shape : shapes) {
    //     delete shape;
    // }

    return 0;
}