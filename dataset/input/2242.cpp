#include <iostream>
#include <cmath>
#include <iomanip>

class Shape {
public:
    virtual double calculateArea() const {
        return 0.0;
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
} // Syntax Error: Missing semicolon here

int main() {
    Circle myCircle(5.0);
    Shape* sPtr = &myCircle;

    std::cout << "Area of circle (through Shape pointer): "
              << std::fixed << std::setprecision(2)
              << sPtr->calculateArea() << std::endl;

    return 0;
}