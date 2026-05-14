#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class Vector2D {
private:
    double x;
    double y;

public:
    // Constructor to initialize members
    Vector2D(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}

    // Friend declaration for the overloaded insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec);
};

// Overloaded insertion operator as a non-member (friend) function
// ROBUSTNESS ISSUE: Modifies stream state (precision, fixed) without restoring it.
std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
    os << "(" << std::fixed << std::setprecision(10) << vec.x << ", " << vec.y << ")";
    // PROBLEM: The stream's formatting flags (std::fixed, std::setprecision(10))
    // are not restored to their original state after this operation.
    // This will affect all subsequent double outputs on the same stream.
    return os;
}

int main() {
    std::cout << "--- Robustness Issue Example (Stream State Modification) ---" << std::endl;

    Vector2D v1(1.234567890123, 2.5);
    std::cout << "Vector v1: " << v1 << std::endl; // Applies std::fixed and std::setprecision(10)

    // Subsequent double output will be affected by the previous operation
    std::cout << "Default double output (should be affected): " << 3.1415926535 << std::endl;

    Vector2D v2(-3.14, 0.0);
    std::cout << "Vector v2: " << v2 << std::endl; // Again applies std::fixed and std::setprecision(10)

    double test_val = 123.456;
    std::cout << "Another double value (should be affected): " << test_val << std::endl;

    std::cout << "--- End Example ---" << std::endl;
    return 0;
}