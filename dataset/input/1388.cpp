#include <iostream>
#include <cmath> // Included but not used for M_PI, demonstrating a readability/efficiency issue (using magic number)

// Abstract base class Shape
class Shape {
public:
    virtual double getArea() = 0;
    virtual ~Shape() = default;
};

// Derived class Rectangle
class Rectangle : public Shape {
public: // Readability/Efficiency Issue: Public member variables, breaking encapsulation
    double wid; // Non-descriptive naming
    double hgt; // Non-descriptive naming

    Rectangle(double w, double h) : wid(w), hgt(h) {
    } // Constructor is okay but could be clearer with initialization list on same line

    double getArea() override {
        return wid * hgt;
    }
};

// Derived class Circle
class Circle : public Shape {
public: // Readability/Efficiency Issue: Public member variables, breaking encapsulation
    double rad; // Non-descriptive naming

    Circle(double r) { // Readability/Efficiency Issue: Not using initializer list, slightly less efficient/clear
        rad = r;
    }

    double getArea() override {
        const double PI_VAL = 3.14159; // Readability/Efficiency Issue: Using a magic number for PI instead of M_PI
        return PI_VAL * rad * rad;
    }
};

int main() {
    // Demonstrating usage with the less readable/efficient design
    Rectangle r1(5.0, 10.0);
    std::cout << "Rectangle (5x10) Area: " << r1.getArea() << std::endl;

    Circle c1(4.0);
    std::cout << "Circle (radius 4) Area: " << c1.getArea() << std::endl;

    // Direct modification of public members, showing lack of encapsulation
    r1.wid = 7.0;
    r1.hgt = 2.0;
    std::cout << "Modified Rectangle (7x2) Area: " << r1.getArea() << std::endl;

    c1.rad = 5.0;
    std::cout << "Modified Circle (radius 5) Area: " << c1.getArea() << std::endl;

    return 0;
}