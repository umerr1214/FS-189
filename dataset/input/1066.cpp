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
    // Syntax error: Missing semicolon after return statement
    double calculateArea() override {
        return M_PI * radius * radius
    } // <-- MISSING SEMICOLON HERE
};

int main() {
    std::cout << std::fixed << std::setprecision(15);

    // This code will not compile due to the syntax error in Circle::calculateArea()
    // If it were to compile, it would produce the area of a circle.
    Circle c("Red", 5.0);
    std::cout << "Circle (radius 5.0, color Red) area: " << c.calculateArea() << std::endl;

    Shape* s = new Circle("Blue", 10.0);
    std::cout << "Shape pointer to Circle (radius 10.0, color Blue) area: " << s->calculateArea() << std::endl;
    delete s;

    return 0;
}