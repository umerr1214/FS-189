#include <iostream>
#include <vector>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Abstract Base Class
class Shape {
public:
    virtual double calculateArea() = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor
};

// Derived Concrete Class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() override {
        return M_PI * radius * radius;
    }
};

// Derived Concrete Class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() override {
        return width * height;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    // This program will not compile due to the missing semicolon above.
    // If it did compile, it would instantiate and calculate areas.
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    std::vector<Shape*> shapes;
    shapes.push_back(&circle);
    shapes.push_back(&rectangle);

    std::cout << "--- Shape Areas ---" << std::endl;
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->calculateArea() << std::endl;
    }

    return 0;
}