#include <iostream>
#include <vector>
#include <string>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision
#include <sstream> // For output to string stream

// Base class - MISSING VIRTUAL DESTRUCTOR
class Shape {
public:
    virtual double calculateArea() const = 0;
    // The destructor is NOT virtual. This is a robustness issue.
    // When deleting derived objects through a base class pointer,
    // only the base class destructor will be called, leading to
    // potential memory leaks or undefined behavior for derived class resources.
    ~Shape() {
        // This message will be printed, but Circle/Rectangle destructors won't if deleted via Shape*
        // std::cout << "Shape destructor called (non-virtual)." << std::endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
    ~Circle() {
        // This destructor will NOT be called when `delete` is called on a `Shape*` pointing to a `Circle`
        // std::cout << "Circle destructor called." << std::endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const override {
        return width * height;
    }
    ~Rectangle() {
        // This destructor will NOT be called when `delete` is called on a `Shape*` pointing to a `Rectangle`
        // std::cout << "Rectangle destructor called." << std::endl;
    }
};

// Test cases driver function
std::string run_test_cases() {
    std::vector<Shape*> shapes; // Using raw pointers

    // Populate with Circle and Rectangle objects
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Circle(2.5));
    shapes.push_back(new Rectangle(10.0, 2.0));

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);

    // Iterate and call calculateArea()
    for (const auto& shape : shapes) {
        oss << "Area: " << shape->calculateArea() << "\n";
    }

    // Clean up memory. This is where the robustness issue (memory leak potential) manifests.
    // Because Shape's destructor is not virtual, only Shape's destructor will be called for each object,
    // potentially leaving resources allocated by derived classes unreleased.
    for (auto& shape_ptr : shapes) {
        delete shape_ptr; // This will only call Shape::~Shape()
    }

    return oss.str();
}

int main() {
    std::cout << run_test_cases();
    return 0;
}