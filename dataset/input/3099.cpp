#include <iostream> // Required for std::cout, std::ostream

class Vector2D {
private:
    double x;
    double y;

public:
    // Constructor to initialize members with default values
    Vector2D(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}

    // Friend declaration for the overloaded insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec);
};

// Overloaded insertion operator as a non-member (friend) function
// CORRECT VERSION: Directly writes to the output stream.
std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
    // Directly write components to the output stream in the specified format.
    // This is the most efficient and idiomatic way for simple formatting.
    os << "(" << vec.x << ", " << vec.y << ")";
    return os; // Return the stream for chaining
}

int main() {
    std::cout << "--- Correct Version Example ---" << std::endl;

    // Test cases for various Vector2D objects
    Vector2D v1(1.0, 2.5);
    std::cout << "Vector v1: " << v1 << std::endl; // Expected: (1, 2.5)

    Vector2D v2(-3.14, 0.0);
    std::cout << "Vector v2: " << v2 << std::endl; // Expected: (-3.14, 0)

    Vector2D v3(100.0, -200.0);
    std::cout << "Vector v3: " << v3 << std::endl; // Expected: (100, -200)

    Vector2D v4; // Default constructed (x=0.0, y=0.0)
    std::cout << "Vector v4 (default): " << v4 << std::endl; // Expected: (0, 0)

    Vector2D v5(7.7); // Only x initialized, y uses default
    std::cout << "Vector v5 (partial): " << v5 << std::endl; // Expected: (7.7, 0)

    std::cout << "--- End Example ---" << std::endl;
    return 0;
}