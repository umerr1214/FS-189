#include <iostream>
// No other headers like cmath are strictly needed for the class as defined by the question,
// but often useful for vector operations.

class Vector2D {
private:
    double x;
    double y;

public:
    // Parameterized constructor using initializer list for efficiency and clarity.
    // This directly initializes members, avoiding default construction followed by assignment.
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    // Copy constructor using initializer list.
    // For primitive types like 'double', a member-wise copy is a "deep copy" of their values,
    // as there's no dynamic memory or pointers involved.
    Vector2D(const Vector2D& other) : x(other.x), y(other.y) {}

    // Getter for x to access the private member
    double getX() const {
        return x;
    }

    // Getter for y to access the private member
    double getY() const {
        return y;
    }

    // A utility method to display the vector's coordinates
    void print() const {
        std::cout.precision(2); // Set precision for consistent output
        std::cout << std::fixed << "(" << x << ", " << y << ")";
    }
};

int main() {
    // Test parameterized constructor
    Vector2D v1(5.5, 6.6);
    std::cout << "Original vector v1: ";
    v1.print();
    std::cout << std::endl;

    // Test copy constructor
    Vector2D v2 = v1; // Uses copy constructor to create v2 from v1
    std::cout << "Copied vector v2 (from v1): ";
    v2.print();
    std::cout << std::endl;

    // Verify independence by printing values again (if setters were present,
    // we would modify v1 and check that v2 remains unchanged).
    std::cout << "Verifying values after creation and copy:" << std::endl;
    std::cout << "v1.getX(): " << v1.getX() << ", v1.getY(): " << v1.getY() << std::endl;
    std::cout << "v2.getX(): " << v2.getX() << ", v2.getY(): " << v2.getY() << std::endl;

    return 0;
}