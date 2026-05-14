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
} // Syntax Error: Missing semicolon after class definition

class ColoredCircle : public Shape {
public:
    ColoredCircle(std::string c) : Shape(c) {}
    void changeColor(std::string newColor) {
        color = newColor; // Accessing protected member
    }
};

int main() {
    ColoredCircle myCircle("blue");
    myCircle.displayColor();
    myCircle.changeColor("red");
    myCircle.displayColor();
    return 0;
}