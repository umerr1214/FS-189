#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    // Parameterized constructor
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    // Copy constructor (LOGICAL ERROR: swaps x and y during copy)
    Vector2D(const Vector2D& other) : x(other.y), y(other.x) { // x gets other.y, y gets other.x
        // This is a logical error because it does not perform a direct copy of x to x and y to y.
    }

    // Method to display the vector
    void print() const {
        std::cout << "Vector2D(" << x << ", " << y << ")" << std::endl;
    }

    // Getter for x (for testing)
    double getX() const { return x; }
    // Getter for y (for testing)
    double getY() const { return y; }
};

int main() {
    Vector2D v1(10.5, 20.3);
    std::cout << "Original vector v1: ";
    v1.print(); // Expected: Vector2D(10.5, 20.3)

    Vector2D v2 = v1; // Uses the copy constructor with the logical error
    std::cout << "Copied vector v2 (from v1): ";
    v2.print(); // Expected: Vector2D(10.5, 20.3), Actual: Vector2D(20.3, 10.5)

    Vector2D v3(5.0, 7.0);
    std::cout << "Original vector v3: ";
    v3.print(); // Expected: Vector2D(5.0, 7.0)

    Vector2D v4(v3); // Another way to use copy constructor
    std::cout << "Copied vector v4 (from v3): ";
    v4.print(); // Expected: Vector2D(5.0, 7.0), Actual: Vector2D(7.0, 5.0)

    return 0;
}