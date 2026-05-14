#include <iostream>
#include <string>

// Abstract base class
class Shape {
public:
    Shape() { std::cout << "Shape constructor\n"; }
    // LOGICAL ERROR: Destructor is NOT virtual.
    // This means when deleting a derived object via a base pointer,
    // only the base destructor will be called, leading to partial destruction.
    ~Shape() { std::cout << "Shape destructor\n"; }
    virtual void draw() const = 0;
};

// Derived class Circle
class Circle : public Shape {
private:
    std::string color;
public:
    Circle() : color("red") { std::cout << "Circle constructor\n"; }
    // This destructor is marked override, but it won't be called polymorphically
    // if the base class destructor is not virtual when deleting via a base pointer.
    ~Circle() override {
        std::cout << "Circle destructor (color: " << color << ")\n";
    }
    void draw() const override {
        std::cout << "Drawing a Circle with color: " << color << "\n";
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    Rectangle() { std::cout << "Rectangle constructor\n"; }
    ~Rectangle() override { std::cout << "Rectangle destructor\n"; }
    void draw() const override {
        std::cout << "Drawing a Rectangle\n";
    }
};

int main() {
    std::cout << "Demonstrating consequences of NON-VIRTUAL destructor:\n";

    std::cout << "--- Deleting Circle via Shape pointer ---\n";
    Shape* s1 = new Circle();
    s1->draw();
    delete s1; // PROBLEM: Only Shape destructor will be called, Circle's will be skipped.

    std::cout << "\n--- Deleting Rectangle via Shape pointer ---\n";
    Shape* s2 = new Rectangle();
    s2->draw();
    delete s2; // PROBLEM: Only Shape destructor will be called, Rectangle's will be skipped.

    return 0;
}