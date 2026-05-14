#include <iostream>
#include <string>

class Rectangle {
private:
    // Semantic error: length and width are declared static, meaning they are shared across all instances.
    // This violates the semantic meaning of individual Rectangle objects having their own dimensions.
    static double length;
    static double width;

public:
    // Constructor
    Rectangle(double l = 1.0, double w = 1.0) {
        // For static members, initialization is typically outside the class or in a static block (C++11 onwards for in-class init).
        // Here, the constructor effectively sets the *shared* dimensions for the first time or re-sets them.
        if (l <= 0) l = 1.0;
        if (w <= 0) w = 1.0;
        length = l; // Modifies the static member
        width = w;  // Modifies the static member
    }

    // Getters
    double getLength() const { return length; }
    double getWidth() const { return width; }

    // Setters
    void setLength(double l) {
        if (l <= 0) {
            std::cout << "Error: Invalid length (value " << l << "). Length must be positive and was not updated." << std::endl;
        } else {
            length = l; // Modifies the static member
        }
    }

    void setWidth(double w) {
        if (w <= 0) {
            std::cout << "Error: Invalid width (value " << w << "). Width must be positive and was not updated." << std::endl;
        } else {
            width = w; // Modifies the static member
        }
    }

    double calculateArea() const {
        return length * width;
    }

    void printDimensions() const {
        std::cout << "Length: " << length << ", Width: " << width << std::endl;
    }
};

// Definition of static members outside the class
double Rectangle::length = 1.0;
double Rectangle::width = 1.0;

int main() {
    Rectangle rect1(5.0, 10.0);
    std::cout << "Rect1 initial dimensions: ";
    rect1.printDimensions(); // Length: 5, Width: 10

    Rectangle rect2(20.0, 30.0); // This constructor call changes static members
    std::cout << "Rect2 initial dimensions: ";
    rect2.printDimensions(); // Length: 20, Width: 30
    std::cout << "Rect1 dimensions after Rect2 creation: ";
    rect1.printDimensions(); // Semantic Error: Rect1's dimensions have changed to Rect2's initial dimensions

    rect1.setLength(7.5); // This modifies the static length
    std::cout << "Rect1 after setting length to 7.5: ";
    rect1.printDimensions(); // Length: 7.5, Width: 30
    std::cout << "Rect2 dimensions after Rect1 length change: ";
    rect2.printDimensions(); // Semantic Error: Rect2's length has also changed

    rect2.setWidth(2.0); // This modifies the static width
    std::cout << "Rect2 after setting width to 2.0: ";
    rect2.printDimensions(); // Length: 7.5, Width: 2
    std::cout << "Rect1 dimensions after Rect2 width change: ";
    rect1.printDimensions(); // Semantic Error: Rect1's width has also changed

    rect1.setLength(-3.0); // Invalid, should not update
    std::cout << "Rect1 after setting length to -3.0: ";
    rect1.printDimensions(); // Length: 7.5, Width: 2 (correctly not updated)
    std::cout << "Rect2 dimensions after Rect1 invalid length change: ";
    rect2.printDimensions(); // Length: 7.5, Width: 2 (still shared)

    return 0;
}