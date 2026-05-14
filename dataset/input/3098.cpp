#include <iostream>
#include <sstream> // Required for std::stringstream

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
// READABILITY / EFFICIENCY ISSUE: Uses std::stringstream unnecessarily.
std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
    // This approach uses a stringstream to build the output string,
    // then extracts the string and writes it to the output stream.
    // It's less efficient than direct stream manipulation and adds unnecessary complexity.
    std::stringstream ss;
    ss << "(" << vec.x << ", " << vec.y << ")"; // Build string in stringstream
    os << ss.str();                             // Extract and write the string
    return os;
}

int main() {
    std::cout << "--- Readability / Efficiency Issue Example (stringstream) ---" << std::endl;

    Vector2D v1(1.0, 2.5);
    std::cout << "Vector v1: " << v1 << std::endl;

    Vector2D v2(-3.14, 0.0);
    std::cout << "Vector v2: " << v2 << std::endl;

    Vector2D v3(100.0, -200.0);
    std::cout << "Vector v3: " << v3 << std::endl;

    Vector2D v4; // Default constructed
    std::cout << "Vector v4 (default): " << v4 << std::endl;

    std::cout << "--- End Example ---" << std::endl;
    return 0;
}