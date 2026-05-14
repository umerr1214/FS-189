#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr, std::make_unique
#include <iomanip> // For std::fixed, std::setprecision

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual function
    virtual ~Shape() {
        // std::cout << "Shape destructor called." << std::endl;
    }
};

// Derived class Square
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double calculateArea() const override {
        return side * side;
    }
    ~Square() {
        // std::cout << "Square destructor called." << std::endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
    ~Circle() {
        // std::cout << "Circle destructor called." << std::endl;
    }
};

// The actual program logic that will be tested
void student_main() {
    // Demonstrate runtime polymorphism using a vector of smart pointers
    // std::unique_ptr ensures automatic memory management, preventing leaks.
    std::vector<std::unique_ptr<Shape>> shapes;

    // Store instances of Square and Circle using std::make_unique for safe allocation.
    shapes.push_back(std::make_unique<Square>(4.0));
    shapes.push_back(std::make_unique<Circle>(2.5));

    std::cout << std::fixed << std::setprecision(5);

    // Iterate through the vector using a range-based for loop, which is clean and efficient.
    // Runtime polymorphism automatically calls the correct calculateArea() method for each object.
    for (const auto& shape_ptr : shapes) {
        // Using dynamic_cast here to print specific shape names for clarity in output.
        // For pure polymorphism demonstration, `std::cout << "Area: " << shape_ptr->calculateArea() << std::endl;`
        // would also be a valid and simpler approach.
        if (dynamic_cast<Square*>(shape_ptr.get())) {
            std::cout << "Area of Square: " << shape_ptr->calculateArea() << std::endl;
        } else if (dynamic_cast<Circle*>(shape_ptr.get())) {
            std::cout << "Area of Circle: " << shape_ptr->calculateArea() << std::endl;
        } else {
            std::cout << "Area of unknown shape: " << shape_ptr->calculateArea() << std::endl;
        }
    }

    // Memory is automatically deallocated when the 'shapes' vector and its
    // contained std::unique_ptr objects go out of scope. No explicit 'delete'
    // calls are needed, making the code robust, concise, and less error-prone.
}

int main() {
    student_main();
    return 0;
}