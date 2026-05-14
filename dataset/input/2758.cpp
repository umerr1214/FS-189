#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual ~Shape() = default;
};

// Derived class: Square
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double calculateArea() const override {
        return side * side;
    }
}; // Missing semicolon here, intentionally to create a syntax error

// Derived class: Circle
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
    // Create a vector of unique_ptr to Shape for automatic memory management
    std::vector<std::unique_ptr<Shape>> shapes;

    // Store instances of Square and Circle
    shapes.push_back(std::make_unique<Square>(5.0));
    shapes.push_back(std::make_unique<Circle>(3.0));
    shapes.push_back(std::make_unique<Square>(7.5));
    shapes.push_back(std::make_unique<Circle>(2.5));

    std::cout << "Calculating areas using runtime polymorphism:\n";

    // Iterate through the array and call calculateArea() for each object
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->calculateArea() << std::endl;
    }

    return 0;
}