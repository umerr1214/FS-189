#include <iostream>
#include <string>

// Base class Shape
class Shape {
protected:
    std::string color;
public:
    // Shape has only this constructor, no default constructor.
    Shape(const std::string& c) : color(c) {}
    void displayInfo() {
        std::cout << "Shape Color: " << color << std::endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    // SEMANTIC ERROR: Circle constructor does not explicitly call Shape's constructor.
    // Since Shape only has a user-defined constructor and no default one,
    // this will result in a compilation error because the compiler
    // cannot find a default constructor for Shape to implicitly call.
    Circle(const std::string& c, double r) : radius(r) {
        // Correct way would be: Circle(const std::string& c, double r) : Shape(c), radius(r) {}
    }
    void displayInfo() {
        Shape::displayInfo(); // Call base class method
        std::cout << "Circle Radius: " << radius << std::endl;
    }
};

int main() {
    Shape s("Red");
    s.displayInfo();

    Circle c("Blue", 10.5);
    c.displayInfo();

    return 0;
}