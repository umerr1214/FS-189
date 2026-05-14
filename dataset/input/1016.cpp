#include <iostream>
#include <string>

// Base class for the 'fix' demonstration
class Shape {
public:
    Shape() { std::cout << "Shape constructor called.\n"; }
    // Correctly made virtual for the 'fix' demonstration part
    virtual ~Shape() { std::cout << "Shape destructor called.\n"; }

    virtual void draw() const { std::cout << "Drawing a generic shape.\n"; }
};

// Derived class for the 'fix' demonstration
class Circle : public Shape {
private:
    std::string name;
public:
    Circle(const std::string& n = "Default Circle") : name(n) { std::cout << "Circle constructor called (" << name << ").\n"; }
    ~Circle() override { std::cout << "Circle destructor called (" << name << ").\n"; }

    void draw() const override { std::cout << "Drawing a circle named " << name << ".\n"; }
};

int main() {
    // Inner classes to clearly demonstrate the 'problem' with non-virtual destructors
    class ProblematicShape {
    public:
        ProblematicShape() { std::cout << "ProblematicShape constructor called.\n"; }
        ~ProblematicShape() { std::cout << "ProblematicShape destructor called.\n"; } // Non-virtual
        virtual void draw() const { std::cout << "Drawing a problematic shape.\n"; }
    };

    class ProblematicCircle : public ProblematicShape {
    private:
        std::string name;
    public:
        ProblematicCircle(const std::string& n = "Prob Circle") : name(n) { std::cout << "ProblematicCircle constructor called (" << name << ").\n"; }
        ~ProblematicCircle() { std::cout << "ProblematicCircle destructor called (" << name << ").\n"; }
        void draw() const override { std::cout << "Drawing a problematic circle named " << name << ".\n"; }
    };

    std::cout << "--- Demonstrating problem (non-virtual destructor leads to partial destruction) ---\n";
    ProblematicShape* ps = new ProblematicCircle("Memory Leak Example");
    ps->draw();
    delete ps; // Only ProblematicShape destructor called, ProblematicCircle's is skipped
    std::cout << "--- End of problem demonstration ---\n";

    std::cout << "\n--- Demonstrating fix (virtual destructor) ---\n";
    // The base class 'Shape' (defined above main) now has a virtual destructor.
    // Logical error: The fix is implemented (Shape's destructor is virtual),
    // but the demonstration of the fix doesn't use a base pointer for deletion,
    // thereby failing to clearly show the benefit of the virtual destructor
    // in a polymorphic deletion scenario.
    Circle* c = new Circle("Fixed Circle Demo"); // Allocating derived directly
    c->draw();
    delete c; // Deleting derived directly. This will call both destructors even if Shape's was non-virtual,
              // thus not demonstrating the *polymorphic* fix via a base pointer.
    std::cout << "--- End of fix demonstration ---\n";

    return 0;
}