#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}

    // Const version: for const objects or when the object's state should not be modified.
    // Returns the x-coordinate by value.
    int getX() const {
        return x;
    }

    // Non-const version: for non-const objects when the x-coordinate might be modified.
    // Returns a reference to the x-coordinate, allowing direct modification.
    int& getX() {
        return x;
    }

    void print() const {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    std::cout << "Demonstrating Point class with overloaded getX() methods." << std::endl;

    Point p1(10, 20);
    std::cout << "p1 (non-const): ";
    p1.print();

    // Call non-const getX() and modify x
    std::cout << "Calling non-const getX() on p1 to modify x to 15." << std::endl;
    p1.getX() = 15;
    std::cout << "p1 after modification: ";
    p1.print();

    const Point p2(30, 40);
    std::cout << "p2 (const): ";
    p2.print();

    // Call const getX() on p2
    std::cout << "Calling const getX() on p2: " << p2.getX() << std::endl;
    // p2.getX() = 35; // This would be a compile-time error, as expected.

    std::cout << "\nExplanation of getX() calls:" << std::endl;
    std::cout << "The 'const int getX() const' version is called when the Point object itself is const (like p2) or when the method is called on an rvalue (temporary object)." << std::endl;
    std::cout << "The 'int& getX()' version is called when the Point object is non-const (like p1) and allows modification of the internal x-coordinate via the returned reference." << std::endl;
    std::cout << "It's important to be careful when using the non-const version, especially with temporary objects." << std::endl;

    // Robustness Issue: Attempting to modify a temporary object
    // This line causes undefined behavior as it tries to modify a temporary rvalue.
    // The explanation above implies this without explicitly warning against it.
    std::cout << "\n--- Demonstrating a potential robustness issue (Undefined Behavior) ---" << std::endl;
    std::cout << "Attempting to modify a temporary Point object's x-coordinate:" << std::endl;
    Point(50, 60).getX() = 55; // Undefined behavior
    std::cout << "Value of x after attempting to modify temporary: " << Point(50, 60).getX() << std::endl; // This will create a *new* temporary Point(50, 60) and get its x.
    std::cout << "Note: The actual effect of modifying a temporary is undefined and may not be immediately apparent." << std::endl;

    return 0;
}