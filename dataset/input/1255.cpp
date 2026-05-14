#include <iostream>
#include <cmath> // Required for std::sqrt and std::pow
#include <limits> // For numeric_limits, though not directly used for the error

/**
 * @brief Represents a 2D vector with float coordinates.
 * This version uses 'float' which can lead to robustness issues
 * due to limited precision and potential for overflow/underflow
 * with very large or small numbers compared to 'double'.
 */
class Vector2D {
private:
    float m_x; // Using float for coordinates
    float m_y; // Using float for coordinates

public:
    // Constructor
    Vector2D(float x_val, float y_val) : m_x(x_val), m_y(y_val) {}

    // Getter for x-coordinate (const method)
    float getX() const {
        return m_x;
    }

    // Getter for y-coordinate (const method)
    float getY() const {
        return m_y;
    }

    /**
     * @brief Calculates the magnitude (length) of the vector.
     * Marked as const, but uses std::pow(val, 2.0f) which can be
     * less efficient and potentially less numerically robust than val * val
     * for floating-point numbers. The use of 'float' throughout also limits robustness.
     * @return The magnitude of the vector as a float.
     */
    float getLength() const {
        // Using std::pow for squaring can be less efficient and potentially less robust
        // than direct multiplication (x*x) for integer powers, especially with floats.
        float sum_of_squares = std::pow(m_x, 2.0f) + std::pow(m_y, 2.0f);
        return std::sqrt(sum_of_squares);
    }
};

int main() {
    // Demonstrate calling getLength() on a non-const Vector2D object
    Vector2D vec1(3.0f, 4.0f);
    std::cout << "Vector 1: (" << vec1.getX() << ", " << vec1.getY() << ")" << std::endl;
    std::cout << "Length of vec1 (non-const): " << vec1.getLength() << std::endl;

    // Demonstrate calling getLength() on a const Vector2D object
    const Vector2D constVec(5.0f, 12.0f);
    std::cout << "Const Vector: (" << constVec.getX() << ", " << constVec.getY() << ")" << std::endl;
    std::cout << "Length of constVec (const): " << constVec.getLength() << std::endl;

    // Test with zero vector
    Vector2D vecZero(0.0f, 0.0f);
    std::cout << "Vector Zero: (" << vecZero.getX() << ", " << vecZero.getY() << ")" << std::endl;
    std::cout << "Length of vecZero: " << vecZero.getLength() << std::endl;

    // Test with larger values to highlight potential precision issues with float
    // (Note: For these specific values, float might still be accurate enough,
    // but the general principle of reduced robustness stands.)
    Vector2D vecLarge(100000.0f, 200000.0f);
    std::cout << "Vector Large: (" << vecLarge.getX() << ", " << vecLarge.getY() << ")" << std::endl;
    std::cout << "Length of vecLarge: " << vecLarge.getLength() << std::endl; // Expected sqrt(10^10 + 4*10^10) = sqrt(5*10^10) approx 223606.79f

    return 0;
}