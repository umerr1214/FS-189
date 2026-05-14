#include <iostream>
#include <string>

// Base class
class Shape {
public:
    Shape() { std::cout << "Shape constructor called.\n"; }
    // Intentionally non-virtual for the problem demonstration part
    ~Shape() { std::cout << "Shape destructor called.\n"; }

    virtual void draw() const { std::cout << "Drawing a generic shape.\n"; }
}; // Missing semicolon here intentionally for syntax error

// Derived class
class Circle : public Shape {
private:
    std::string name;
public:
    Circle(const std::string& n = "Default Circle") : name(n) { std::cout << "Circle constructor called (" << name << ").\n"; }
    ~Circle() { std::cout << "Circle destructor called (" << name << ").\n"; }

    void draw() const override { std::cout << "Drawing a circle named " << name << ".\n"; }
};

int main() {
    std::cout << "--- Demonstrating problem (non-virtual destructor) ---\n";
    Shape* s1 = new Circle("Problematic Circle");
    s1->draw();
    delete s1; // This will only call Shape's destructor

    std::cout << "\n--- Demonstrating fix (virtual destructor) ---\n";
    // To fix, Shape's destructor needs to be virtual.
    // This section is commented out or will cause further errors due to the primary syntax error.
    // For a fully working fix demonstration, the Shape destructor would need to be changed to virtual.
    // As this is a syntax error example, the focus is on the compilation failure.
    // If the above syntax error was fixed, this would be the place to show the virtual destructor.
    // Shape* s2 = new Circle("Fixed Circle");
    // delete s2; // Would call both destructors if Shape's was virtual

    return 0;
}