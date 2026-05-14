#include <iostream>

class Box {
private:
    double length;
    double width;
    double height;

public:
    // Syntax error: Missing type specifier for parameter 'h'
    Box(double l, double w, h) : length(l), width(w), height(h) {}

    friend double calculateVolume(const Box& b);
};

double calculateVolume(const Box& b) {
    return b.length * b.width * b.height;
}

int main() {
    Box b1(2.0, 3.0, 4.0);
    std::cout << "Volume of box 1: " << calculateVolume(b1) << std::endl;

    Box b2(1.5, 2.5, 3.5);
    std::cout << "Volume of box 2: " << calculateVolume(b2) << std::endl;
    return 0;
}