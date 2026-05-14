#include <iostream>
#include <string>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision

// Base class Shape
class Shape {
protected:
    std::string color;
public:
    Shape(const std::string& c) : color(c) {}
    virtual double calculateArea() { // Base class method is virtual
        return 0;
    }
    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(const std::string& c, double r) : Shape(c), radius(r) {}
    // Semantic error: Signature mismatch for intended override.
    // This creates a new function (overload), hiding Shape::calculateArea, instead of overriding it.
    // The 'override' keyword would catch this, but without it, it compiles fine.
    // When called polymorphically through a Shape* pointer, Shape::calculateArea will be invoked.
    double calculateArea(int dummy = 0) { // Added a default parameter, breaking the override signature
        return M_PI * radius * radius;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(15);

    Circle c("Red", 5.0);
    // Calling directly on Circle object will use Circle::calculateArea(int), which calculates area correctly
    std::cout << "Circle direct call (radius 5.0, color Red) area: " << c.calculateArea() << std::endl;

    Shape* s = &c;
    // Semantic error: Calling via Shape* will invoke Shape::calculateArea() (returns 0)
    // because Circle::calculateArea(int) does not override Shape::calculateArea().
    std::cout << "Shape pointer call (radius 5.0, color Red) area: " << s->calculateArea() << std::endl;

    delete s; // s is a pointer to stack allocated object c, no delete needed.
              // This is another small semantic error, but the primary is the override issue.
              // Let's make it a heap allocated object for correct delete.
    Shape* s_heap = new Circle("Blue", 10.0);
    std::cout << "Shape pointer to heap Circle (radius 10.0, color Blue) area: " << s_heap->calculateArea() << std::endl;
    delete s_heap;


    return 0;
}