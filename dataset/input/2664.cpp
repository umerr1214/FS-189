#include <iostream>
#include <string>
#include <vector>

// Abstract base class
class Shape {
public:
    Shape() { std::cout << "Shape constructor\n"; }
    virtual ~Shape() { std::cout << "Shape destructor\n"; } // VIRTUAL destructor is correctly present
    virtual void draw() const = 0;
};

// Derived class Circle with a SEMANTIC ERROR (memory leak)
class Circle : public Shape {
private:
    std::string name;
    int* data; // Dynamically allocated resource
    int data_size;
public:
    Circle(std::string n = "Generic Circle", int size = 5) : name(n), data_size(size) {
        std::cout << "Circle constructor (" << name << ")\n";
        data = new int[data_size]; // Allocate memory on the heap
        for (int i = 0; i < data_size; ++i) {
            data[i] = i;
        }
    }
    // SEMANTIC ERROR: Forgetting to deallocate 'data' in the destructor.
    // The virtual destructor mechanism works, but the derived class itself leaks memory.
    ~Circle() override {
        std::cout << "Circle destructor (" << name << ")\n";
        // delete[] data; // THIS LINE IS MISSING, causing a memory leak for 'data'
    }
    void draw() const override {
        std::cout << "Drawing a Circle: " << name << ". Data size: " << data_size << "\n";
    }
};

// Derived class Rectangle (correctly implemented for comparison/completeness)
class Rectangle : public Shape {
public:
    Rectangle() { std::cout << "Rectangle constructor\n"; }
    ~Rectangle() override { std::cout << "Rectangle destructor\n"; }
    void draw() const override {
        std::cout << "Drawing a Rectangle\n";
    }
};

int main() {
    std::cout << "Demonstrating virtual destructor with a SEMANTIC ERROR (memory leak in derived class):\n";

    std::cout << "--- Deleting Circle via Shape pointer (will leak 'data') ---\n";
    Shape* s1 = new Circle("My Leaky Circle", 10);
    s1->draw();
    delete s1; // Shape and Circle destructors are called polymorphically, but Circle's 'data' is leaked.

    std::cout << "\n--- Deleting Rectangle via Shape pointer (correct) ---\n";
    Shape* s2 = new Rectangle();
    s2->draw();
    delete s2; // Correct cleanup

    return 0;
}