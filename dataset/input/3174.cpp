#include <iostream>
#include <vector>
#include <string>

// Base class
class Shape {
public:
    // Semantic error: 'draw' method is not declared virtual.
    // This means dynamic dispatch (polymorphism) will not occur as expected.
    // When called through a base class pointer, Shape::draw() will always be invoked.
    void draw() {
        std::cout << "Drawing a generic shape (Base)." << std::endl;
    }
    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
public:
    void draw() override { // The 'override' keyword will cause a compile-time error here
                           // if the base class method isn't virtual.
                           // For this example, let's remove 'override' to allow compilation
                           // and demonstrate the semantic error at runtime.
        std::cout << "Drawing a Circle (Derived)." << std::endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    void draw() override { // Same as above, removing 'override' for semantic error illustration
        std::cout << "Drawing a Rectangle (Derived)." << std::endl;
    }
};

int main() {
    // Array of Shape pointers
    std::vector<Shape*> shapes;

    shapes.push_back(new Circle());
    shapes.push_back(new Rectangle());
    shapes.push_back(new Circle());

    // Demonstrate polymorphism (will not work correctly due to semantic error)
    for (const auto& shape : shapes) {
        shape->draw(); // This will always call Shape::draw() due to static binding
    }

    // Clean up memory
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}