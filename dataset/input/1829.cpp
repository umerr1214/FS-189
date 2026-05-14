#include <iostream>
#include <string>

class Shape {
protected:
    std::string color;
public:
    Shape(std::string c = "unknown") : color(c) {}
    void displayColor() {
        std::cout << "Color: " << color << std::endl;
    }
};

class ColoredCircle : public Shape {
public:
    ColoredCircle(std::string c) : Shape(c) {}
    void changeColor(std::string newColor) {
        // Logical Error: Assigning to a local variable 'tempColor' instead of the protected member 'color'.
        // The 'color' member of the base class 'Shape' is not modified.
        std::string tempColor = newColor;
    }
};

int main() {
    ColoredCircle myCircle("blue");
    std::cout << "Initial: ";
    myCircle.displayColor(); // Expected: Color: blue
    myCircle.changeColor("red");
    std::cout << "After change attempt: ";
    myCircle.displayColor(); // Expected: Color: red, but will be Color: blue due to the logical error
    return 0;
}