#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Box {
private:
    double length;
    double width;
    double height;

public:
    Box(double l, double w, double h) : length(l), width(w), height(h) {}

    friend double calculateVolume(const Box& b);
};

double calculateVolume(const Box& b) {
    // Logical error: The volume is calculated by summing the dimensions instead of multiplying them.
    return b.length + b.width + b.height;
}

int main() {
    Box b1(2.0, 3.0, 4.0);
    std::cout << std::fixed << std::setprecision(3) << "Volume of box 1: " << calculateVolume(b1) << std::endl; // Expected: 24.000, Actual: 9.000

    Box b2(1.5, 2.5, 3.5);
    std::cout << std::fixed << std::setprecision(3) << "Volume of box 2: " << calculateVolume(b2) << std::endl; // Expected: 13.125, Actual: 7.500
    return 0;
}