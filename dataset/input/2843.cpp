#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Shape {
public:
    virtual double calculateArea() = 0;
    virtual ~Shape() {} // Good practice for base classes with virtual functions
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() override {
        return length + width; // Logical error: should be length * width
    }
};

int main() {
    Rectangle rect1(10.0, 5.0); // Expected area: 50.0, Actual: 15.0
    Rectangle rect2(2.5, 4.0);  // Expected area: 10.0, Actual: 6.5

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Area of rect1 (10.0x5.0): " << rect1.calculateArea() << std::endl;
    std::cout << "Area of rect2 (2.5x4.0): " << rect2.calculateArea() << std::endl;

    // Test with polymorphism
    Shape* s1 = &rect1;
    Shape* s2 = &rect2;
    std::cout << "Area via Shape* for rect1: " << s1->calculateArea() << std::endl;
    std::cout << "Area via Shape* for rect2: " << s2->calculateArea() << std::endl;

    return 0;
}