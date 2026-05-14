#include <iostream>
#include <string>
#include <utility> // For std::move

class Shape {
protected:
    std::string color;
public:
    // Constructor initializes color, passing by value for simplicity (not the primary robustness issue here).
    Shape(std::string c) : color(std::move(c)) {}

    // Robustness Issue: displayInfo is NOT virtual.
    // This means that when a Shape pointer points to a Circle object,
    // calling displayInfo through that pointer will invoke Shape's version,
    // not Circle's, leading to incorrect polymorphic behavior.
    void displayInfo() const {
        std::cout << "Shape Info - Color: " << color << '\n';
    }

    // No virtual destructor, which can lead to resource leaks if derived objects are
    // deleted via a base pointer, but the non-virtual displayInfo is the main focus.
    ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
public:
    // Constructor for Circle, initializes base Shape part and its own radius.
    Circle(std::string c, double r) : Shape(std::move(c)), radius(r) {}

    // This method "hides" Shape::displayInfo rather than overriding it,
    // because the base method is not virtual.
    void displayInfo() const {
        // Calling base method to show shared info
        Shape::displayInfo();
        std::cout << "Circle Info - Radius: " << radius << '\n';
    }
    ~Circle() = default;
};

int main() {
    // Test case 1: Direct object calls
    std::cout << "--- Direct Object Calls ---\n";
    Shape s("Blue");
    s.displayInfo();

    Circle c("Red", 5.0);
    c.displayInfo();

    // Test case 2: Polymorphic calls (demonstrates the robustness issue)
    std::cout << "\n--- Polymorphic Calls (Robustness Issue Demonstrated) ---\n";
    Shape* s_ptr1 = &s;
    Shape* s_ptr2 = &c; // A Shape pointer pointing to a Circle object

    std::cout << "Calling displayInfo via Shape* to Shape object:\n";
    s_ptr1->displayInfo(); // Correctly calls Shape::displayInfo

    std::cout << "Calling displayInfo via Shape* to Circle object:\n";
    // INCORRECT BEHAVIOR: Calls Shape::displayInfo, NOT Circle::displayInfo,
    // because displayInfo in Shape is not virtual.
    s_ptr2->displayInfo();

    // Another example with dynamic allocation
    std::cout << "\n--- Dynamic Allocation Example ---\n";
    Shape* dynamic_s = new Shape("Green");
    Shape* dynamic_c = new Circle("Yellow", 10.0);

    dynamic_s->displayInfo();
    dynamic_c->displayInfo(); // Still calls Shape::displayInfo, not Circle::displayInfo

    delete dynamic_s;
    delete dynamic_c; // Potential memory leak if Circle has complex resources and Shape has no virtual destructor.

    return 0;
}