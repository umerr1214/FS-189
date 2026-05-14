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
    double radius;
public:
    Circle(const std::string& c, double r) : Shape(c), radius(r) {}
    void displayInfo() {
        Shape::displayInfo(); // Call base class method
        // LOGICAL ERROR: This method does not display the radius,
        // violating the requirement to implement displayInfo for Circle.
        // std::cout << "Circle Radius: " << radius << std::endl; // This line is missing
    }
};

int main() {
    Shape s("Red");
    s.displayInfo();

    Circle c("Blue", 10.5);
    c.displayInfo();

    return 0;
}