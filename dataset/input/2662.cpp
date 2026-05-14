#include <iostream>
#include <string>

// Abstract base class
class Shape {
public:
    Shape() { std::cout << "Shape constructor\n"; }
    virtual ~Shape() { std::cout << "Shape destructor\n"; }
    virtual void draw() const = 0;
}; // SYNTAX ERROR: Missing semicolon after class definition

// Derived class Circle
class Circle : public Shape {
public:
    Circle() { std::cout << "Circle constructor\n"; }
    ~Circle() override { std::cout << "Circle destructor\n"; }
    void draw() const override {
        std::cout << "Drawing a Circle\n";
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
    std::cout << "Demonstrating virtual destructor:\n";

    Shape* s1 = new Circle();
    s1->draw();
    delete s1; // Should call Circle destructor then Shape destructor

    std::cout << "\n";

    Shape* s2 = new Rectangle();
    s2->draw();
    delete s2; // Should call Rectangle destructor then Shape destructor

    return 0;
}