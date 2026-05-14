#include <iostream>
#include <vector>
#include <string>
#include <cmath> // For M_PI if needed, or define PI

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual function
    virtual ~Shape() {
        // std::cout << "Shape destructor called." << std::endl;
    } // Virtual destructor for proper cleanup
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return M_PI * radius * radius; // Using M_PI from cmath
    }
    ~Circle() override {
        // std::cout << "Circle destructor called." << std::endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const override {
        return width * height;
    }
    ~Rectangle() override {
        // std::cout << "Rectangle destructor called." << std::endl;
    }
};

int main() {
    std::vector<Shape*> shapes;

    // Populate the collection with a mix of Circle and Rectangle objects
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Circle(2.5));
    shapes.push_back(new Rectangle(7.0, 3.0));
    shapes.push_back(new Circle(10.0));

    std::cout << "Calculating areas:" << std::endl;

    // Iterate and call calculateArea() on each using base class pointers
    for (const Shape* shape : shapes) {
        std::cout << "Area: " << shape->calculateArea() << std::endl;
    }

    // ERROR: Memory leak - objects allocated with 'new' are not deleted.
    // The program will exit, but the dynamically allocated memory will not be freed.

    return 0;
}