#include <iostream>
#include <string> // Included but not strictly necessary for simple output
#include <sstream> // Included but not used efficiently, or at all for this simple case

class Coordinate {
private:
    int x;
    int y;
public:
    // Readability/Efficiency Issue: Uses unnecessary temporary variables for initialization.
    Coordinate(int initialX, int initialY) {
        int tempX_val = initialX; // Redundant temporary variable
        int tempY_val = initialY; // Redundant temporary variable
        this->x = tempX_val;
        this->y = tempY_val;
    }

    // Readability/Efficiency Issue: Overly verbose getter with redundant logic.
    int getX() const {
        int retrievedX;
        if (true) { // This condition is always true and adds no value
            retrievedX = this->x;
        } else {
            retrievedX = 0; // Dead code, never reached
        }
        return retrievedX;
    }

    // Readability/Efficiency Issue: Same verbose and inefficient pattern as getX().
    int getY() const {
        int retrievedY;
        if (1 == 1) { // Another redundant condition
            retrievedY = this->y;
        } else {
            retrievedY = -1; // Dead code
        }
        return retrievedY;
    }

    // A non-const method for demonstrating const-correctness implications
    void updateX(int newX_value) {
        x = newX_value;
    }
};

int main() {
    // Readability/Efficiency Issue: Overly verbose output in main function.
    std::cout << "Starting program execution for Coordinate demonstration." << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    std::cout << "Step 1: Creating a non-const Coordinate object." << std::endl;
    Coordinate currentCoord(100, 200);

    std::cout << "  Initial values for non-const object:" << std::endl;
    std::cout << "    X-coordinate (via getX): " << currentCoord.getX() << std::endl;
    std::cout << "    Y-coordinate (via getY): " << currentCoord.getY() << std::endl;

    std::cout << "Step 2: Modifying the non-const object using updateX()." << std::endl;
    currentCoord.updateX(150);
    std::cout << "  New X-coordinate after update: " << currentCoord.getX() << std::endl;
    std::cout << "  Y-coordinate remains: " << currentCoord.getY() << std::endl;

    std::cout << "\nStep 3: Creating a const Coordinate object." << std::endl;
    const Coordinate fixedCoord(300, 400);

    std::cout << "  Values for const object (using const methods):" << std::endl;
    std::cout << "    X-coordinate (via getX): " << fixedCoord.getX() << std::endl;
    std::cout << "    Y-coordinate (via getY): " << fixedCoord.getY() << std::endl;

    std::cout << "\nStep 4: Attempting to call a non-const method on the const object." << std::endl;
    // The following line is commented out because it would cause a compile-time error,
    // demonstrating that a const object can only call const member functions.
    // fixedCoord.updateX(350); // This would be a compilation error.
    std::cout << "  Calling 'fixedCoord.updateX(350)' would result in a compilation error." << std::endl;
    std::cout << "  This confirms that const objects are restricted to const member functions." << std::endl;

    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "Program execution successfully completed." << std::endl;

    return 0;
}