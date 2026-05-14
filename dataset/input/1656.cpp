#include <iostream>

class Vector2D {
public: // SEMANTIC ERROR: Members x and y are public, violating the 'private' requirement.
    double x;
    double y;

public:
    // Parameterized constructor
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    // Copy constructor (performs deep copy for primitive types)
    Vector2D(const Vector2D& other) : x(other.x), y(other.y) {
        // For primitive types like double, member-wise copy is a deep copy.
        // No dynamic memory to manage here.
    }

    // Method to display the vector
    void print() const {
        std::cout << "Vector2D(" << x << ", " << y << ")" << std::endl;
    }

    // Setter for x (to demonstrate public access violation)
    void setX(double new_x) { x = new_x; }
};

int main() {
    Vector2D v1(10.5, 20.3);
    std::cout << "v1: ";
    v1.print();

    // Direct access to public members, demonstrating the semantic error
    v1.x = 100.0;
    std::cout << "v1 after direct x modification: ";
    v1.print(); // Expected: Vector2D(100.0, 20.3)

    Vector2D v2 = v1; // Uses the copy constructor
    std::cout << "v2 (copy of v1): ";
    v2.print();

    // Verify v2 is independent
    v2.y = 500.0;
    std::cout << "v2 after direct y modification: ";
    v2.print(); // Expected: Vector2D(100.0, 500.0)
    std::cout << "v1 (should be unchanged): ";
    v1.print(); // Expected: Vector2D(100.0, 20.3)

    return 0;
}