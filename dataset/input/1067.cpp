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
    virtual double calculateArea() {
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
    // Logical error: Calculates circumference instead of area
    double calculateArea() override {
        return 2 * M_PI * radius; // Should be M_PI * radius * radius
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(15);

    // Test cases
    Circle c1("Red", 5.0);
    Circle c2("Blue", 10.0);

    std::cout << "Circle 1 (radius 5.0, color Red) area: " << c1.calculateArea() << std::endl;
    std::cout << "Circle 2 (radius 10.0, color Blue) area: " << c2.calculateArea() << std::endl;

    // Using polymorphism
    Shape* s1 = &c1;
    Shape* s2 = new Circle("Green", 7.0);
    std::cout << "Shape pointer to Circle (radius 7.0, color Green) area: " << s2->calculateArea() << std::endl;
    delete s2;

    return 0;
}