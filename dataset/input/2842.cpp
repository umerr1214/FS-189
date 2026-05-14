#include <iostream>
#include <iomanip>

class Shape {
public:
    virtual double calculateArea() = 0;
}; // Intentionally missing semicolon here to cause a Syntax Error

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() override {
        return length * width;
    }
};

int main() {
    Rectangle rect(10.0, 5.0);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area of rectangle: " << rect.calculateArea() << std::endl;
    return 0;
}