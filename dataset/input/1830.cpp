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

// Semantic Error: Private inheritance makes Shape's public and protected members private in ColoredCircle.
// Therefore, displayColor() becomes private within ColoredCircle and cannot be accessed from main.
class ColoredCircle : private Shape {
public:
    ColoredCircle(std::string c) : Shape(c) {}
    void changeColor(std::string newColor) {
        color = newColor; // This is fine: ColoredCircle can access protected 'color'
    }
    // To fix, either use 'public Shape' or add 'using Shape::displayColor;' here.
};

int main() {
    ColoredCircle myCircle("blue");
    myCircle.displayColor(); // Semantic Error: 'displayColor' is inaccessible due to private inheritance
    myCircle.changeColor("red");
    myCircle.displayColor(); // Same error
    return 0;
}