#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Constructor to initialize x and y coordinates
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}

    // Const version of getX():
    // Called when the Point object is const or when the method is called on an rvalue (temporary object).
    // It returns the x-coordinate by value, ensuring the object's state is not modified.
    int getX() const {
        return x;
    }

    // Non-const version of getX():
    // Called when the Point object is non-const.
    // It returns a non-const reference to the x-coordinate, allowing direct modification of 'x'.
    int& getX() {
        return x;
    }

    // Helper method to display point coordinates
    void print() const {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Point Class with Overloaded getX() Methods ---" << std::endl;

    // 1. Using a non-const Point object
    Point p1(10, 20);
    std::cout << "\nInitial p1 (non-const): ";
    p1.print();

    // Calling non-const getX() on p1
    // Explanation: Since p1 is a non-const object, the non-const Point::getX() method is selected.
    // This version returns an 'int&', allowing us to modify the 'x' coordinate directly.
    std::cout << "Calling non-const getX() on p1: " << p1.getX() << std::endl;
    p1.getX() = 15; // Modify x through the returned reference
    std::cout << "p1 after modifying x to 15: ";
    p1.print();

    // 2. Using a const Point object
    const Point p2(30, 40);
    std::cout << "\nInitial p2 (const): ";
    p2.print();

    // Calling const getX() on p2
    // Explanation: Since p2 is a const object, only const methods can be called on it.
    // The const Point::getX() method is selected. It returns an 'int' by value,
    // preventing any modification to p2's internal state.
    std::cout << "Calling const getX() on p2: " << p2.getX() << std::endl;
    // p2.getX() = 35; // This line would cause a compile-time error, as expected.

    // 3. Calling getX() on a temporary (rvalue) object
    std::cout << "\nCalling getX() on a temporary Point object:" << std::endl;
    // Explanation: Temporary objects (rvalues) are implicitly const.
    // Therefore, the const Point::getX() method is selected.
    std::cout << "x-coordinate of temporary Point(50, 60): " << Point(50, 60).getX() << std::endl;
    // Point(50, 60).getX() = 55; // This would also be a compile-time error (cannot assign to rvalue of type 'const int')
                                // if getX() const returned `const int&`. If it returns `int` by value, it would be assigning to a temporary `int`.

    std::cout << "\n--- Summary of getX() overload resolution ---" << std::endl;
    std::cout << "1. If the object is non-const (lvalue), the non-const `int& getX()` is called." << std::endl;
    std::cout << "2. If the object is const (lvalue or rvalue), the const `int getX() const` is called." << std::endl;
    std::cout << "This design allows for both read-only access and controlled modification based on object const-ness." << std::endl;

    return 0;
}