#include <iostream>
#include <string>

// Base class Shape
class Shape {
protected:
    std::string color;
public:
    Shape(const std::string& c) : color(c) {}
    void displayInfo() {
        std::cout << "Shape Color: " << color << std::endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius // SYNTAX ERROR: Missing semicolon here
public:
    Circle(const std::string& c, double r) : Shape(c), radius(r) {}
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