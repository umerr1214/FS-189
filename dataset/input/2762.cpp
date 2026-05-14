#include <iostream>
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
    // Demonstrate runtime polymorphism using an array of Shape pointers
    const int num_shapes = 2;
    Shape* shapes[num_shapes]; // C-style array of raw Shape pointers

    // Store instances of Square and Circle
    shapes[0] = new Square(4.0);
    shapes[1] = new Circle(2.5);

    std::cout << std::fixed << std::setprecision(5);

    // Iterate through the array and call calculateArea() for each object
    for (int i = 0; i < num_shapes; ++i) {
        // Using dynamic_cast here to print specific shape names.
        // While functional, it's less direct for demonstrating polymorphism
        // which allows calling calculateArea() without knowing the exact type.
        if (dynamic_cast<Square*>(shapes[i])) {
            std::cout << "Area of Square: " << shapes[i]->calculateArea() << std::endl;
        } else if (dynamic_cast<Circle*>(shapes[i])) {
            std::cout << "Area of Circle: " << shapes[i]->calculateArea() << std::endl;
        } else {
            std::cout << "Area of unknown shape: " << shapes[i]->calculateArea() << std::endl;
        }
    }

    // --- READABILITY / EFFICIENCY ISSUE: MANUAL MEMORY MANAGEMENT ---
    // Although memory is correctly deallocated, using raw pointers and
    // manual 'new'/'delete' is less readable, more error-prone, and less
    // efficient in terms of development time than using C++ smart pointers
    // (e.g., std::unique_ptr) with `std::vector`. This approach increases
    // the risk of bugs (e.g., forgetting to delete, double-delete) and
    // makes the code less robust against exceptions or complex control flows.
    for (int i = 0; i < num_shapes; ++i) {
        delete shapes[i];
        shapes[i] = nullptr; // Good practice to nullify dangling pointers
    }
}

int main() {
    student_main();
    return 0;
}