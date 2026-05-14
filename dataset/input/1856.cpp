#include <iostream>
#include <string> // Required for std::string, though not directly used in the core logic

class Box {
private:
    double length;
    double width;
    double height;

public:
    // Constructor
    Box(double l, double w, double h) : length(l), width(w), height(h) {}

    // Friend declaration for calculateVolume.
    // The signature matches the inefficient pass-by-value approach.
    friend double calculateVolume(Box b);
};

// Non-member friend function to calculate volume.
// This function takes the Box object by value, which is less efficient
// than passing by const reference, as it involves copying the entire object.
// Additionally, it uses an unnecessary intermediate variable, slightly reducing conciseness.
double calculateVolume(Box b) { // Pass-by-value parameter
    // Calculate the base area first, an unnecessary intermediate step
    double baseArea = b.length * b.width;
    // Then multiply by height to get the total volume
    double totalVolume = baseArea * b.height;
    return totalVolume;
}

int main() {
    Box box1(10.0, 5.0, 2.0);
    std::cout << calculateVolume(box1) << std::endl;

    Box box2(3.0, 4.0, 5.0);
    std::cout << calculateVolume(box2) << std::endl;

    return 0;
}