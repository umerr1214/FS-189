#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::for_each if desired, but range-based for loop is simpler

// Base class
class Shape {
public:
    Shape(const std::string& name) : name_(name) {
        std::cout << "Constructing Shape: " << name_ << std::endl;
    }
    // Correct: Virtual destructor for polymorphic deletion
    virtual ~Shape() {
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
    ~Rectangle() override { // Correct: Uses override keyword for clarity
        std::cout << "  Destructing Rectangle (" << getName() << ")" << std::endl;
    }
    void draw() const override { // Correct: Uses override keyword for clarity
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
    ~Circle() override { // Correct: Uses override keyword for clarity
        std::cout << "  Destructing Circle (" << getName() << ")" << std::endl;
    }
    void draw() const override { // Correct: Uses override keyword for clarity
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

    std::cout << "--- Deleting shapes polymorphically ---" << std::endl;
    // Correct: Using a range-based for loop for clean deletion.
    // The virtual destructor in Shape ensures correct derived class destructors are called first,
    // followed by the base class destructor.
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear(); // Clear the vector of pointers after deletion
    std::cout << "---------------------------------------" << std::endl;

    std::cout << "\nProgram finished successfully." << std::endl;
    return 0;
}