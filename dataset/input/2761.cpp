#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual function
    virtual ~Shape() {
        // In a real application, a message here could indicate destructor calls.
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
        // Using dynamic_cast here to print specific shape names,
        // though polymorphism itself means shapes[i]->calculateArea() is sufficient.
        if (dynamic_cast<Square*>(shapes[i])) {
            std::cout << "Area of Square: " << shapes[i]->calculateArea() << std::endl;
        } else if (dynamic_cast<Circle*>(shapes[i])) {
            std::cout << "Area of Circle: " << shapes[i]->calculateArea() << std::endl;
        } else {
            std::cout << "Area of unknown shape: " << shapes[i]->calculateArea() << std::endl;
        }
    }

    // --- ROBUSTNESS ISSUE: MEMORY LEAK ---
    // Objects allocated with 'new' are NOT deleted.
    // This will result in a memory leak as the program exits without freeing heap memory.
    // To fix this, a loop to 'delete' each pointer would be necessary:
    // for (int i = 0; i < num_shapes; ++i) {
    //     delete shapes[i];
    //     shapes[i] = nullptr; // Good practice to nullify dangling pointers
    // }
}

int main() {
    student_main();
    return 0;
}