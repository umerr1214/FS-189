#include <iostream>
#include <string>

class Shape {
protected:
    std::string color;
public:
    // Correct: Pass std::string by const reference to avoid unnecessary copies.
    Shape(const std::string& c) : color(c) {}

    // Correct: displayInfo is declared virtual for proper polymorphic behavior.
    virtual void displayInfo() const {
        std::cout << "Shape Info - Color: " << color << '\n';
    }
    // Correct: Virtual destructor for proper cleanup in polymorphic scenarios.
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
public:
    // Correct: Pass std::string by const reference to avoid unnecessary copies.
    Circle(const std::string& c, double r) : Shape(c), radius(r) {}

    // Correct: Uses override keyword, calls base method, and prints only its specific info.
    void displayInfo() const override {
        Shape::displayInfo(); // Prints "Shape Info - Color: [color]"
        std::cout << "Circle Info - Radius: " << radius << '\n';
    }
    ~Circle() = default;
};

int main() {
    Shape s("Blue");
    s.displayInfo();

    Circle c("Red", 5.0);
    c.displayInfo();

    std::cout << "\n--- Polymorphic Calls ---\n";
    Shape* s_ptr1 = &s;
    Shape* s_ptr2 = &c;

    std::cout << "Calling displayInfo via Shape* to Shape object:\n";
    s_ptr1->displayInfo();

    std::cout << "Calling displayInfo via Shape* to Circle object:\n";
    s_ptr2->displayInfo(); // Correctly calls Circle::displayInfo due to virtual function

    // Example with dynamic allocation
    std::cout << "\n--- Dynamic Allocation Example ---\n";
    Shape* dynamic_s = new Shape("Green");
    Shape* dynamic_c = new Circle("Yellow", 10.0);

    dynamic_s->displayInfo();
    dynamic_c->displayInfo(); // Correctly calls Circle::displayInfo

    delete dynamic_s;
    delete dynamic_c; // Virtual destructor ensures correct deletion

    return 0;
}