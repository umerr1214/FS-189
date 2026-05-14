#include <iostream>
#include <vector>
#include <string>
#include <cmath> // For M_PI in Circle area

// Base class
class Shape {
public:
    virtual ~Shape() {
        std::cout << "Shape destructor called." << std::endl;
    }
    virtual double area() const = 0;
    virtual void print() const = 0;
};

// Derived class 1
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {
        std::cout << "Rectangle constructor called." << std::endl;
    }
    ~Rectangle() override {
        std::cout << "Rectangle destructor called." << std::endl;
    }
    double area() const override {
        return width * height;
    }
    void print() const override {
        std::cout << "Rectangle: Width=" << width << ", Height=" << height << ", Area=" << area() << std::endl;
    }
};

// Derived class 2
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {
        std::cout << "Circle constructor called." << std::endl;
    }
    ~Circle() override {
        std::cout << "Circle destructor called." << std::endl;
    }
    double area() const override {
        return M_PI * radius * radius;
    }
    void print() const override {
        std::cout << "Circle: Radius=" << radius << ", Area=" << area() << std::endl;
    }
};

// Main demonstration function
void demonstratePolymorphism() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Rectangle(10, 5));
    shapes.push_back(new Circle(7));
    shapes.push_back(new Rectangle(3, 8));

    for (const auto& shape : shapes) {
        shape->print();
    }

    std::cout << "\nDeleting shapes (first pass)...\n";
    for (Shape* shape : shapes) {
        delete shape; // First deletion frees the memory
    }

    std::cout << "\nAttempting to delete shapes again (second pass)...\n";
    // ERROR: Semantic error - attempting to delete already freed memory (double free)
    for (Shape* shape : shapes) {
        delete shape; // This is undefined behavior (double free)
    }
    
    // Clearing the vector of dangling pointers is good practice, but the error already occurred
    shapes.clear();
}

int main() {
    demonstratePolymorphism();
    return 0;
}