#include <iostream>

class Vector2D {
private:
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
} // Missing semicolon here, causing a syntax error

int main() {
    Vector2D v1(10.5, 20.3);
    std::cout << "v1: ";
    v1.print();

    Vector2D v2 = v1; // Uses the copy constructor
    std::cout << "v2 (copy of v1): ";
    v2.print();

    Vector2D v3(5.0, 7.0);
    std::cout << "v3: ";
    v3.print();

    // Demonstrate independent modification (for deep copy concept)
    // Even though it's primitive, it shows v1 and v2 are separate objects.
    // This part of the code won't compile due to the syntax error above.
    // v1.x = 100.0; // This would be an error if x was truly private and no setter
    // For demonstration, let's assume setters or direct access for testing purposes,
    // but the main point is the compilation failure.

    return 0;
}