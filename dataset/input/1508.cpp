#include <iostream>
#include <string>

class Shape {
protected:
    std::string color;
public:
    // Efficiency Issue: Passing std::string by value.
    // This causes an unnecessary copy of the string object when the constructor is called.
    Shape(std::string c) : color(c) {
        // A copy of 'c' is made when passed into the function,
        // and then another copy is made to initialize 'color'.
    }

    // displayInfo is virtual for correctness, but Circle's implementation will demonstrate redundancy.
    virtual void displayInfo() const {
        std::cout << "Shape Info - Color: " << color << '\n';
    }
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
public:
    // Efficiency Issue: Passing std::string by value.
    // This again causes an unnecessary copy of the string object.
    Circle(std::string c, double r) : Shape(c), radius(r) {} // 'c' is copied to pass to Shape constructor.

    // Readability / Efficiency Issue: Redundant information printing.
    // The base method prints the color, and then this method prints it again.
    void displayInfo() const override {
        Shape::displayInfo(); // Prints "Shape Info - Color: [color]"
        std::cout << "Circle Info - Color: " << color // Redundant printing of color
                  << ", Radius: " << radius << '\n';
    }
    ~Circle() = default;
};

int main() {
    Shape s("Orange");
    s.displayInfo();

    Circle c("Purple", 7.5);
    c.displayInfo();

    std::cout << "\n--- Polymorphic Calls ---\n";
    Shape* s_ptr = &c;
    s_ptr->displayInfo(); // Will call Circle's displayInfo due to virtual function

    // Demonstrating the copy overhead (conceptually, not easily measurable in this simple main)
    std::string temp_color = "Brown";
    // 'temp_color' is copied when passed to Circle's constructor.
    // Then, inside Circle's constructor, this copy is copied again to pass to Shape's constructor.
    Circle c2(temp_color, 1.0);
    c2.displayInfo();

    return 0;
}