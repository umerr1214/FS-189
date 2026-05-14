#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class Vector2D {
private:
    double x; // Private x-coordinate
    double y; // Private y-coordinate

public:
    // Constructor with default arguments for x and y
    // Uses member initializer list for efficient initialization.
    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Friend declarations for non-member operators to allow direct access to private members.
    // This is a common and efficient pattern for arithmetic operators on classes.
    friend Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);
};

// Overloaded binary '+' operator for vector addition.
// Implemented as a non-member friend function for symmetry and direct access to private members.
// It takes two constant references to Vector2D objects and returns a new Vector2D object by value.
// This ensures that the original operands remain unchanged (immutability) and a new result is produced.
Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs) {
    // Directly constructs and returns a new Vector2D object with the sum of coordinates.
    // This is the most efficient way, leveraging RVO (Return Value Optimization).
    return Vector2D(lhs.x + rhs.x, lhs.y + rhs.y);
}

// Overload the output stream operator (<<) for easy and intuitive printing of Vector2D objects.
// It takes an output stream reference and a constant reference to a Vector2D object.
std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main() {
    // Set output precision for doubles to ensure consistent formatting.
    std::cout << std::fixed << std::setprecision(1);

    // Test 1: Addition of two positive vectors
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    Vector2D v3 = v1 + v2;
    std::cout << v3 << std::endl; // Expected: (4.0, 6.0)

    // Test 2: Addition involving negative and decimal coordinates
    Vector2D v_neg1(-1.0, 2.5);
    Vector2D v_neg2(3.5, -4.0);
    Vector2D v_neg_res = v_neg1 + v_neg2;
    std::cout << v_neg_res << std::endl; // Expected: (2.5, -1.5)

    // Test 3: Chained addition to demonstrate correct behavior with multiple operations
    Vector2D v_chain1(1.0, 1.0);
    Vector2D v_chain2(2.0, 2.0);
    Vector2D v_chain3(3.0, 3.0);
    Vector2D v_chain_res = v_chain1 + v_chain2 + v_chain3;
    std::cout << v_chain_res << std::endl; // Expected: (6.0, 6.0)

    // Test 4: Addition with a zero vector to ensure correct handling of zero values
    Vector2D v_zero(0.0, 0.0);
    Vector2D v_nonzero(5.0, 6.0);
    Vector2D v_zero_res = v_zero + v_nonzero;
    std::cout << v_zero_res << std::endl; // Expected: (5.0, 6.0)

    return 0;
}