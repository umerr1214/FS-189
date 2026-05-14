#include <iostream>

class Point {
private:
    int m_xCoord; // Readability: Using 'm_' prefix for member variables.
    int m_yCoord;

public:
    // Default constructor
    Point() {
        // Readability/Efficiency: Assigning in the constructor body rather than using an initializer list.
        // For primitive types like int, the efficiency impact is minimal, but for complex objects,
        // it can lead to default construction followed by assignment, which is less efficient.
        this->m_xCoord = 0; // Readability: Excessive use of 'this->'.
        this->m_yCoord = 0;
    }

    // Parameterized constructor
    Point(int initialXValue, int initialYValue) { // Readability: Long variable names.
        // Readability/Efficiency: Assigning in the constructor body rather than using an initializer list.
        this->m_xCoord = initialXValue; // Readability: Excessive use of 'this->'.
        this->m_yCoord = initialYValue;
    }

    // Public method to display coordinates
    void displayPoint() {
        std::cout << "(" << this->m_xCoord << ", " << this->m_yCoord << ")"; // Readability: Excessive use of 'this->'.
    }
};

int main() {
    // Test default constructor
    Point p1;
    std::cout << "Point p1 (default): ";
    p1.displayPoint();
    std::cout << std::endl;

    // Test parameterized constructor
    Point p2(10, 20);
    std::cout << "Point p2 (parameterized): ";
    p2.displayPoint();
    std::cout << std::endl;

    // Test with negative coordinates
    Point p3(-5, -8);
    std::cout << "Point p3 (negative): ";
    p3.displayPoint();
    std::cout << std::endl;

    return 0;
}