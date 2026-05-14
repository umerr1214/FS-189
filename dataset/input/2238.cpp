#include <iostream>
#include <string>

class Shape {
protected:
    std::string color;
public:
    // Shape only has a parameterized constructor, no default constructor.
    Shape(std::string c) : color(c) {}
    std::string getColor() const { return color; }
    void display() const {
        std::cout << "Shape color: " << color << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    // SEMANTIC ERROR: The Circle constructor fails to explicitly call a base class constructor.
    // Since Shape has no default constructor, this leads to a compilation error.
    Circle(std::string c, double r) : radius(r) { // Compiler will implicitly try to call Shape::Shape()
        // If Shape had a default constructor, this would compile but 'color' might be uninitialized
        // or default-initialized before this point, violating the intent.
        // As Shape has no default constructor, this is a direct compilation failure.
    }

    double getRadius() const { return radius; }
    void display() const {
        std::cout << "Circle color: " << color << ", radius: " << radius << std::endl;
    }
};

int main() {
    // This line will cause a compilation error due to the semantic error in Circle's constructor.
    Circle c("Green", 7.5);
    c.display();
    return 0;
}