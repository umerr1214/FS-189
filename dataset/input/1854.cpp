#include <iostream>
#include <iomanip>

class Box {
private:
    double length;
    double width;
    double height;

public:
    // Semantic error: The constructor takes parameters but does not initialize the member variables.
    // The member variables 'length', 'width', 'height' will remain uninitialized.
    // Accessing them later leads to undefined behavior.
    Box(double l, double w, double h) {
        // Correct initialization would be: : length(l), width(w), height(h) {}
        // Or: this->length = l; this->width = w; this->height = h;
    }

    friend double calculateVolume(const Box& b);
};

double calculateVolume(const Box& b) {
    // Accessing uninitialized members of 'b' leads to undefined behavior.
    return b.length * b.width * b.height;
}

int main() {
    Box b1(2.0, 3.0, 4.0);
    // The values 2.0, 3.0, 4.0 are passed to the constructor but not used to initialize members.
    // b1.length, b1.width, b1.height are uninitialized, leading to garbage values for volume.
    std::cout << std::fixed << std::setprecision(3) << "Volume of box 1: " << calculateVolume(b1) << std::endl;

    Box b2(1.5, 2.5, 3.5);
    std::cout << std::fixed << std::setprecision(3) << "Volume of box 2: " << calculateVolume(b2) << std::endl;
    return 0;
}