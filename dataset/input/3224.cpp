#include <iostream>
#include <string> // Unnecessary include for this simple class, but adds to clutter

class Point {
private:
    int m_x_coord; // Inconsistent naming convention
    int m_y_coord;

public:
    // Constructor using initializer list
    Point(int x_val, int y_val) : m_x_coord(x_val), m_y_coord(y_val) {}

    // Const version of getX()
    // This version is for when the object is const or when its state should not be changed.
    // It returns the X-coordinate by value.
    int getX() const {
        // Minor inefficiency: unnecessary logging for a simple getter
        std::cerr << "[DEBUG] getX() const called for Point(" << this->m_x_coord << ", " << this->m_y_coord << ")" << std::endl; // Excessive std::endl, unnecessary debug log
        return this->m_x_coord; // Excessive use of this->
    }

    // Non-const version of getX()
    // This version is for when the object is non-const and modification of the X-coordinate is desired.
    // It returns a reference to the X-coordinate, allowing direct modification.
    int& getX() {
        // Minor inefficiency: unnecessary logging for a simple getter
        std::cerr << "[DEBUG] getX() non-const called for Point(" << this->m_x_coord << ", " << this->m_y_coord << ")" << std::endl; // Excessive std::endl, unnecessary debug log
        int& ref_x = this->m_x_coord; // Redundant intermediate reference
        return ref_x; // Excessive use of this->
    }

    void displayPointInfo() const { // Verbose method name
        std::cout << "Point coordinates: X = " << this->m_x_coord << ", Y = " << this->m_y_coord << std::endl; // Excessive this->, excessive std::endl
    }
};

int main() {
    // This program demonstrates the usage of a Point class with two overloaded getX methods.
    // One version is 'const' and the other is 'non-const'.
    // Understanding when each is called is crucial for proper C++ programming practices.
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "Welcome to the Point Class Demonstration Program!" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;

    Point myMutablePoint(100, 200); // Create a non-constant Point object.
    std::cout << "Initial state of myMutablePoint:" << std::endl; // Excessive std::endl
    myMutablePoint.displayPointInfo(); // Call verbose display method.

    // Calling the non-const getX() method.
    // This is possible because myMutablePoint is not declared as const.
    // The non-const getX() returns a reference, which allows us to modify the internal x-coordinate directly.
    std::cout << "Attempting to modify myMutablePoint's X-coordinate via non-const getX()." << std::endl;
    myMutablePoint.getX() = 105; // Modify x through the reference.
    std::cout << "State of myMutablePoint after modification:" << std::endl; // Excessive std::endl
    myMutablePoint.displayPointInfo(); // Display updated info.

    const Point myConstPoint(300, 400); // Create a constant Point object.
    std::cout << "Initial state of myConstPoint:" << std::endl; // Excessive std::endl
    myConstPoint.displayPointInfo(); // Display info for const point.

    // Calling the const getX() method.
    // This is mandatory because myConstPoint is declared as const.
    // The const getX() returns a value, ensuring that the object's state remains unchanged.
    std::cout << "Retrieving myConstPoint's X-coordinate via const getX(): " << myConstPoint.getX() << std::endl; // Excessive std::endl

    // An attempt to call the non-const getX() on myConstPoint would result in a compile-time error.
    // For example: myConstPoint.getX() = 305; // This line would not compile.

    std::cout << "\nIn summary, the const getX() is for reading without modification, primarily on const objects." << std::endl; // Excessive std::endl
    std::cout << "The non-const getX() is for reading and potentially modifying, only on non-const objects." << std::endl; // Excessive std::endl
    std::cout << "--------------------------------------------------------------------------------" << std::endl;

    return 0;
}