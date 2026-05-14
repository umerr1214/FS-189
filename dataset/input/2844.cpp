#include <iostream>
#include <iomanip>

class Shape {
public:
    virtual double calculateArea() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Intentionally omit calculateArea() implementation.
    // This makes Rectangle an abstract class, leading to a semantic error
    // when trying to instantiate it directly.
    // double calculateArea() override {
    //     return length * width;
    // }
};

int main() {
    // Semantic error: trying to instantiate an abstract class 'Rectangle'
    // because it does not implement the pure virtual function 'calculateArea()'.
    Rectangle rect(10.0, 5.0); // This line will cause a compilation error.
    std::cout << std::fixed << std::setprecision(2);
    // If it compiled, this would print something.
    // std::cout << "Area of rectangle: " << rect.calculateArea() << std::endl;
    return 0;
}