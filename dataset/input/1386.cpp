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
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // SEMANTIC ERROR: getArea() is not implemented here.
    // This makes 'Circle' an abstract class, even though it's derived.
    // An attempt to instantiate 'Circle' will result in a compile-time error.
    // double getArea() override {
    //     return M_PI * radius * radius;
    // }
};

int main() {
    Rectangle rect(5.0, 10.0);
    std::cout << "Rectangle area: " << rect.getArea() << std::endl;

    // This line will cause a compile-time error:
    // "cannot declare variable 'circ' to be of abstract type 'Circle'"
    // because Circle does not implement the pure virtual function getArea().
    // Circle circ(7.0);
    // std::cout << "Circle area: " << circ.getArea() << std::endl;

    return 0;
}