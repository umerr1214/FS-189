#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Base class - Robustness Issue: Missing virtual destructor
class Shape {
public:
    Shape(const std::string& name) : name_(name) {
        std::cout << "Constructing Shape: " << name_ << std::endl;
    }
    // ERROR: This destructor is NOT virtual.
    // When deleting derived objects through a base pointer, only this base destructor will be called.
    ~Shape() {
        std::cout << "Destructing Shape: " << name_ << std::endl;
    }
    virtual void draw() const = 0; // Pure virtual function
    std::string getName() const { return name_; }
protected:
    std::string name_;
};

// Derived class 1
class Rectangle : public Shape {
public:
    Rectangle(double width, double height)
        : Shape("Rectangle"), width_(width), height_(height) {
        std::cout << "  Constructing Rectangle (" << width_ << "x" << height_ << ")" << std::endl;
    }
    // This destructor will NOT be called polymorphically due to the missing virtual keyword in Shape's destructor.
    ~Rectangle() override {
        std::cout << "  Destructing Rectangle (" << getName() << ")" << std::endl;
    }
    void draw() const override {
        std::cout << "Drawing a Rectangle: " << width_ << "x" << height_ << std::endl;
    }
private:
    double width_;
    double height_;
};

// Derived class 2
class Circle : public Shape {
public:
    Circle(double radius)
        : Shape("Circle"), radius_(radius) {
        std::cout << "  Constructing Circle (r=" << radius_ << ")" << std::endl;
    }
    // This destructor will NOT be called polymorphically due to the missing virtual keyword in Shape's destructor.
    ~Circle() override {
        std::cout << "  Destructing Circle (" << getName() << ")" << std::endl;
    }
    void draw() const override {
        std::cout << "Drawing a Circle: radius " << radius_ << std::endl;
    }
private:
    double radius_;
};

// Driver code
int main() {
    std::vector<Shape*> shapes;

    std::cout << "--- Creating shapes ---" << std::endl;
    shapes.push_back(new Rectangle(10.0, 5.0));
    shapes.push_back(new Circle(7.5));
    shapes.push_back(new Rectangle(3.0, 8.0));
    std::cout << "-----------------------" << std::endl << std::endl;

    std::cout << "--- Drawing shapes ---" << std::endl;
    for (const auto& shape : shapes) {
        shape->draw();
    }
    std::cout << "----------------------" << std::endl << std::endl;

    std::cout << "--- Deleting shapes (Robustness Issue: non-virtual destructor) ---" << std::endl;
    // Due to the missing 'virtual' keyword in Shape's destructor,
    // only Shape's destructor will be called for each object,
    // leading to memory leaks for the Rectangle and Circle specific parts
    // and undefined behavior.
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear(); // Clear the vector of now-invalidated pointers
    std::cout << "---------------------------------------------------" << std::endl;

    std::cout << "\nProgram finished." << std::endl;
    return 0;
}