#include <iostream>
#include <string> // Required for std::string, though not directly used in the core logic

class Box {
private:
    double length;
    double width;
    double height;

public:
    // Constructor allows potentially invalid (e.g., negative) dimensions.
    // This design choice is a robustness issue as it doesn't prevent an invalid state.
    Box(double l, double w, double h) : length(l), width(w), height(h) {}

    // Friend declaration for calculateVolume
    friend double calculateVolume(const Box& b);
};

// Non-member friend function to calculate volume.
// This function directly uses the dimensions provided, without validating them.
// If the Box object was created with negative dimensions, this will return a non-physical negative volume.
double calculateVolume(const Box& b) {
    return b.length * b.width * b.height;
}

int main() {
    // Test cases demonstrating the robustness issue
    Box box1(10.0, 5.0, 2.0);
    std::cout << calculateVolume(box1) << std::endl;

    Box box2(-10.0, 5.0, 2.0); // Box with a negative length
    std::cout << calculateVolume(box2) << std::endl; // Results in a negative volume, which is non-physical

    Box box3(0.0, 5.0, 2.0); // Box with zero length
    std::cout << calculateVolume(box3) << std::endl; // Results in zero volume, which is physically plausible but might be an edge case

    Box box4(10.0, -5.0, -2.0); // Box with two negative dimensions
    std::cout << calculateVolume(box4) << std::endl; // Results in a positive volume, but from invalid initial state

    return 0;
}