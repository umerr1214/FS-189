#include <iostream>
#include <cmath> // Required for std::sqrt and std::pow
// No <iomanip> included, leading to less readable output formatting

/**
 * @brief Represents a 2D vector with double coordinates.
 * This version demonstrates readability and efficiency issues primarily
 * within the getLength() method's implementation and main's output.
 */
class Vector2D {
private:
    double x_coord; // Slightly less conventional naming (e.g., m_x, _x, or just x)
    double y_coord; // for class members, but acceptable.

public:
    // Constructor
    Vector2D(double initial_x, double initial_y) : x_coord(initial_x), y_coord(initial_y) {}

    // Getter for x-coordinate (const method)
    double getX() const {
        return x_coord;
    }

    // Getter for y-coordinate (const method)
    double getY() const {
        return y_coord;
    }

    /**
     * @brief Calculates the magnitude (length) of the vector.
     * Marked as const. This implementation is less efficient due to
     * using std::pow() for squaring and an unnecessary intermediate variable.
     * @return The magnitude of the vector as a double.
     */
    double getLength() const {
        // Using std::pow(val, 2.0) is less efficient than val * val for squaring.
        // The intermediate variable 'sum_of_squares' is also not strictly necessary,
        // adding slight verbosity without clear readability benefits here.
        double x_squared = std::pow(x_coord, 2.0);
        double y_squared = std::pow(y_coord, 2.0);
        double sum_of_squares = x_squared + y_squared; // Unnecessary intermediate variable
        return std::sqrt(sum_of_squares);
    }
};

int main() {
    // Demonstrate calling getLength() on a non-const Vector2D object
    Vector2D myVec(3.0, 4.0); // Variable name 'myVec' is okay, but could be more specific
    std::cout << "My Vector coordinates: " << myVec.getX() << ", " << myVec.getY() << std::endl;
    std::cout << "Resulting length (non-const): " << myVec.getLength() << std::endl; // Output not formatted

    // Demonstrate calling getLength() on a const Vector2D object
    const Vector2D constantVector(5.0, 12.0); // Variable name 'constantVector' is descriptive
    std::cout << "Constant Vector coordinates: " << constantVector.getX() << ", " << constantVector.getY() << std::endl;
    std::cout << "Resulting length (const): " << constantVector.getLength() << std::endl; // Output not formatted

    // Another case
    Vector2D anotherVec(1.0, 1.0);
    std::cout << "Another vector: " << anotherVec.getX() << ", " << anotherVec.getY() << std::endl;
    std::cout << "Length (non-const): " << anotherVec.getLength() << std::endl; // sqrt(2) approx 1.41421

    return 0;
}