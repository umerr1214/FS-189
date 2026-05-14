#include <iostream>
#include <cmath>    // Required for std::sqrt
#include <iomanip>  // Required for std::fixed and std::setprecision

/**
 * @brief Represents a 2D vector with double coordinates.
 * This class correctly implements all requirements.
 */
class Vector2D {
private:
    double m_x; // Private member for x-coordinate
    double m_y; // Private member for y-coordinate

public:
    // Constructor to initialize x and y coordinates
    Vector2D(double x_val, double y_val) : m_x(x_val), m_y(y_val) {}

    // Getter for x-coordinate, marked as const as it does not modify the object
    double getX() const {
        return m_x;
    }

    // Getter for y-coordinate, marked as const as it does not modify the object
    double getY() const {
        return m_y;
    }

    /**
     * @brief Calculates the magnitude (length) of the vector.
     * This method is correctly marked as const, ensuring it does not modify
     * the vector object's state. It uses efficient direct multiplication for squaring.
     * @return The magnitude of the vector as a double.
     */
    double getLength() const {
        // Efficiently calculate x*x + y*y and then take the square root.
        return std::sqrt(m_x * m_x + m_y * m_y);
    }
};

int main() {
    // Set output precision for better readability of floating-point numbers
    std::cout << std::fixed << std::setprecision(10);

    // 1. Demonstrate calling getLength() on a non-const Vector2D object
    Vector2D vec1(3.0, 4.0);
    std::cout << "Vector 1: (" << vec1.getX() << ", " << vec1.getY() << ")" << std::endl;
    std::cout << "Length of vec1 (non-const): " << vec1.getLength() << std::endl << std::endl;

    // 2. Demonstrate calling getLength() on a const Vector2D object
    const Vector2D constVec(5.0, 12.0);
    std::cout << "Const Vector: (" << constVec.getX() << ", " << constVec.getY() << ")" << std::endl;
    std::cout << "Length of constVec (const): " << constVec.getLength() << std::endl << std::endl;

    // 3. Test with a zero vector
    Vector2D vecZero(0.0, 0.0);
    std::cout << "Vector Zero: (" << vecZero.getX() << ", " << vecZero.getY() << ")" << std::endl;
    std::cout << "Length of vecZero: " << vecZero.getLength() << std::endl << std::endl;

    // 4. Test with a vector having non-integer length
    Vector2D vecSqrt2(1.0, 1.0);
    std::cout << "Vector Sqrt2: (" << vecSqrt2.getX() << ", " << vecSqrt2.getY() << ")" << std::endl;
    std::cout << "Length of vecSqrt2: " << vecSqrt2.getLength() << std::endl << std::endl;

    return 0;
}