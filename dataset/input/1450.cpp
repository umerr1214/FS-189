#include <iostream>

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    friend double calculateArea(const Rectangle& rect);
} // Syntax Error: Missing semicolon here

double calculateArea(const Rectangle& rect) {
    return rect.width * rect.height;
}

int main() {
    Rectangle r(5.0, 10.0);
    std::cout << "Area: " << calculateArea(r) << std::endl;
    return 0;
}