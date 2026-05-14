#include <iostream>
#include <cmath> // Required for M_PI on some systems

// Define M_PI if not available (e.g., some MSVC versions)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Shape {
public:
    virtual double getArea() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() override {
        // LOGICAL ERROR: Calculates perimeter instead of area
        return 2 * (width + height);
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() override {
        return M_PI * radius * radius;
    }
};

int main() {
    // Example usage
    Rectangle rect(5.0, 10.0);
    Circle circ(7.0);

    std::cout << "Rectangle area (expected 50.0, got perimeter): " << rect.getArea() << std::endl;
    std::cout << "Circle area: " << circ.getArea() << std::endl;

    return 0;
}