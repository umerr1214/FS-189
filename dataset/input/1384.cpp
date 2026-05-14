#include <iostream>
#include <cmath> // Required for M_PI on some systems

// Define M_PI if not available (e.g., some MSVC versions)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Shape {
public:
    // SYNTAX ERROR: Typo in 'virtual' keyword
    virtuall double getArea() = 0;
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
    double getArea() override {
        return M_PI * radius * radius;
    }
};

int main() {
    // This main function won't compile due to the syntax error above.
    // It's included to make it a complete C++ program.
    // The actual testing would happen with a separate driver.
    // For demonstration, if it could compile:
    // Rectangle rect(5, 10);
    // Circle circ(7);
    // std::cout << "Rect area: " << rect.getArea() << std::endl;
    // std::cout << "Circ area: " << circ.getArea() << std::endl;
    return 0;
}