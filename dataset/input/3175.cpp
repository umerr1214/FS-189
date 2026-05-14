#include <iostream>
#include <vector> // Not strictly needed for this robustless issue, but common.

// Base class Shape
class Shape {
public:
    // Virtual draw method
    virtual void draw() {
        std::cout << "Drawing a generic Shape.\n";
    }
    // MISSING VIRTUAL DESTRUCTOR: This is a robustness issue
    // If delete is called on a base class pointer pointing to a derived object,
    // and the base class destructor is not virtual, the derived class destructor
    // will not be called, leading to resource leaks or undefined behavior.
    // For this specific robustless example, the main issue will be forgetting
    // to delete objects at all.
};

// Derived class Circle
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle.\n";
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Rectangle.\n";
    }
};

// Function to demonstrate polymorphism (contains the robustness issue)
void run_demo() {
    // Create an array of Shape pointers
    Shape* shapes[2];

    // Dynamically allocate Circle and Rectangle objects
    shapes[0] = new Circle();
    shapes[1] = new Rectangle();

    // Demonstrate polymorphism by calling draw() on each Shape pointer
    for (int i = 0; i < 2; ++i) {
        shapes[i]->draw();
    }

    // ROBUSTNESS ISSUE: Forgetting to delete dynamically allocated memory.
    // This will cause a memory leak.
    // The correct code should have:
    // delete shapes[0];
    // delete shapes[1];
}

int main() {
    run_demo();
    return 0;
}