#include <iostream>
#include <algorithm> // Required for std::max
#include <string> // Required for std::string, though not directly used in the core logic

class Box {
private:
    double length;
    double width;
    double height;

public:
    // Constructor with basic input validation to ensure non-negative dimensions.
    // This improves the robustness and correctness of the Box object's state.
    Box(double l, double w, double h)
        : length(std::max(0.0, l)),
          width(std::max(0.0, w)),
          height(std::max(0.0, h)) {
        // Dimensions are ensured to be non-negative.
        // For strictly positive dimensions, one might throw an exception here.
    }

    // Friend declaration for calculateVolume.
    // Uses a const reference, which is the idiomatic and efficient way to pass objects.
    friend double calculateVolume(const Box& b);
};

// Non-member friend function to calculate volume.
// Takes Box object by const reference (const Box&) for efficiency,
// avoiding unnecessary copying, and to clearly indicate that the function
// will not modify the Box object.
double calculateVolume(const Box& b) {
    return b.length * b.width * b.height;
}

int main() {
    Box box1(10.0, 5.0, 2.0);
    std::cout << calculateVolume(box1) << std::endl;

    Box box2(3.0, 4.0, 5.0);
    std::cout << calculateVolume(box2) << std::endl;

    Box box3(-5.0, 2.0, 3.0); // Invalid input, handled by constructor (length becomes 0.0)
    std::cout << calculateVolume(box3) << std::endl;

    Box box4(0.0, 2.0, 3.0); // Zero length input, handled by constructor (length remains 0.0)
    std::cout << calculateVolume(box4) << std::endl;

    return 0;
}