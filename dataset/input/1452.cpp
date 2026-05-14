#include <iostream>

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Semantic Error: The 'friend' declaration for calculateArea is missing.
    // friend double calculateArea(const Rectangle& rect);
};

double calculateArea(const Rectangle& rect) {
    // This will cause a compilation error because calculateArea is not a friend
    // and attempts to access private members (width, height).
    return rect.width * rect.height;
}

int main() {
    Rectangle r(5.0, 10.0);
    std::cout << "Area: " << calculateArea(r) << std::endl;
    return 0;
}