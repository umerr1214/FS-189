#include <iostream> // Required for input/output operations

/**
 * @brief Represents a 2D point with integer coordinates.
 *
 * Provides methods to get and set x and y coordinates,
 * with validation to prevent setting negative values.
 */
class Point {
private:
    int x; // Private member for x-coordinate
    int y; // Private member for y-coordinate

public:
    /**
     * @brief Default constructor. Initializes point to (0, 0).
     */
    Point() : x(0), y(0) {}

    /**
     * @brief Parameterized constructor.
     * @param initialX The initial x-coordinate.
     * @param initialY The initial y-coordinate.
     */
    Point(int initialX, int initialY) : x(initialX), y(initialY) {}

    /**
     * @brief Gets the x-coordinate of the point.
     * @return The current x-coordinate.
     */
    int getX() const { // 'const' correctly indicates this method does not modify object state
        return x;
    }

    /**
     * @brief Gets the y-coordinate of the point.
     * @return The current y-coordinate.
     */
    int getY() const { // 'const' correctly indicates this method does not modify object state
        return y;
    }

    /**
     * @brief Sets the x-coordinate of the point.
     *
     * Validates that the input value is non-negative. If negative,
     * it prints an error message to `std::cerr` and does not update the coordinate.
     * @param val The new x-coordinate value.
     */
    void setX(int val) {
        if (val >= 0) {
            x = val;
        } else {
            std::cerr << "Error: X coordinate cannot be set to a negative value (" << val << "). Value retained: " << x << std::endl;
        }
    }

    /**
     * @brief Sets the y-coordinate of the point.
     *
     * Validates that the input value is non-negative. If negative,
     * it prints an error message to `std::cerr` and does not update the coordinate.
     * @param val The new y-coordinate value.
     */
    void setY(int val) {
        if (val >= 0) {
            y = val;
        } else {
            std::cerr << "Error: Y coordinate cannot be set to a negative value (" << val << "). Value retained: " << y << std::endl;
        }
    }
};

int main() {
    Point p1; // Create a point object
    std::cout << "Initial point p1: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;

    // Set valid coordinates
    p1.setX(10);
    p1.setY(20);
    std::cout << "Point p1 after setting (10, 20): (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;

    // Try to set negative coordinates (should be rejected)
    p1.setX(-5);
    p1.setY(-15);
    std::cout << "Point p1 after attempting (-5, -15): (" << p1.getX() << ", " << p1.getY() << ")" << std::endl; // Should still be (10, 20)

    // Set new valid coordinates
    p1.setX(30);
    p1.setY(40);
    std::cout << "Point p1 after setting (30, 40): (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;

    Point p2(100, 200); // Create another point with initial values
    std::cout << "Initial point p2: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
    p2.setY(-50); // Try setting negative
    std::cout << "Point p2 after attempting Y = -50: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl; // Should still be (100, 200)

    return 0;
}