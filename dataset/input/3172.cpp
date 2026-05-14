#include <iostream>
#include <vector>
#include <string>

// Base class
class Shape {
public:
    // Missing parenthesis for draw method, causing a syntax error
    virtual void draw
    {
        std::cout << "Drawing a generic shape." << std::endl;
    }
    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle." << std::endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Rectangle." << std::endl;
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

    // Clean up memory
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}