#include <iostream>
#include <vector>
#include <string>
// No <memory> needed as we're intentionally demonstrating a leak

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual function
    virtual ~Shape() {
        // A virtual destructor is good practice. In this specific example,
        // it highlights that if 'delete' were called, the correct destructor
        // would be invoked. However, we intentionally omit 'delete' in main.
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const override {
        return width * height;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return 3.14159265358979323846 * radius * radius; // More precise PI
    }
};

int main() {
    std::vector<Shape*> shapes;

    // Store instances of Rectangle and Circle using raw pointers
    shapes.push_back(new Rectangle(10.0, 5.0));
    shapes.push_back(new Circle(7.0));
    shapes.push_back(new Rectangle(3.5, 8.0));
    shapes.push_back(new Circle(2.5));

    std::cout << "Calculating areas (Robustness Issue - Memory Leak):\n";
    // Iterate through the array and call calculateArea()
    for (const auto& shape_ptr : shapes) {
        std::cout << "Area: " << shape_ptr->calculateArea() << std::endl;
    }

    // CRITICAL ROBUSTNESS ISSUE: MEMORY LEAK
    // The dynamically allocated objects (Rectangle, Circle) are never deleted.
    // This means memory is not freed when the program finishes or the 'shapes' vector goes out of scope.
    // For a correct version, one would need to iterate through 'shapes' and call 'delete' on each pointer.
    // For example:
    // for (Shape* shape_ptr : shapes) {
    //     delete shape_ptr;
    // }
    // shapes.clear(); // To ensure the vector itself is empty after cleanup.

    return 0;
}