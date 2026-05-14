#include <iostream>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor is crucial for polymorphism
};

// Derived class 1
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const override {
        return width + height; // LOGICAL ERROR: Should be width * height
    }
};

// Derived class 2
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Rectangle(5, 4)); // Expected area: 20, Actual will be: 9 (5+4)
    shapes.push_back(new Circle(3));       // Expected area: 28.27431
    shapes.push_back(new Rectangle(2, 10)); // Expected area: 20, Actual will be: 12 (2+10)

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Calculating areas:" << std::endl;
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "Shape " << i + 1 << " area: " << shapes[i]->calculateArea() << std::endl;
    }

    // Clean up memory to prevent leaks
    for (Shape* s : shapes) {
        delete s;
    }
    shapes.clear();

    return 0;
}