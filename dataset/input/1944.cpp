#include <iostream>
#include <cmath> // Included but not strictly needed for this error scenario

class Shape {
public:
    virtual double calculateArea() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape { // Semantic Error: Circle is an abstract class
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // Missing implementation of double calculateArea() override { ... }
    // This makes Circle an abstract class.
};

int main() {
    std::cout.precision(4);
    std::cout << std::fixed;

    // This line will cause a semantic error (compile-time error):
    // cannot instantiate abstract class 'Circle'
    Circle c1(5.0); 
    // If it somehow compiled, calling calculateArea() would be undefined behavior.
    std::cout << "Area of circle with radius 5.0: " << c1.calculateArea() << std::endl;

    Circle c2(10.0);
    std::cout << "Area of circle with radius 10.0: " << c2.calculateArea() << std::endl;

    Circle c3(0.0);
    std::cout << "Area of circle with radius 0.0: " << c3.calculateArea() << std::endl;

    return 0;
}