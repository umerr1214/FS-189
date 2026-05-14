#include <iostream>

class Point {
public:
    int x;
    int y;

    // Constructor with default values
    Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    // Correct implementation:
    // Overloads the prefix increment operator (++).
    // Increments both x and y coordinates.
    // Returns a reference to the modified object (*this).
    Point& operator++() {
        ++x; // Increment x coordinate
        ++y; // Increment y coordinate
        return *this; // Return a reference to the modified object
    }

    // Method to print the point coordinates
    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1(10, 20);
    std::cout << "Original point p1: ";
    p1.print();
    std::cout << std::endl;

    // Basic increment operation
    ++p1;
    std::cout << "After ++p1: ";
    p1.print();
    std::cout << std::endl;

    Point p2(0, 0);
    std::cout << "Original point p2: ";
    p2.print();
    std::cout << std::endl;

    // Demonstrating correct behavior for chaining increment operations
    // (++p2) increments p2 to (1,1), then (++(result)) increments p2 again to (2,2)
    Point& p_ref = ++(++p2);
    std::cout << "After ++(++p2): ";
    p_ref.print(); // Expected: (2, 2)
    std::cout << std::endl;

    // Confirming p_ref is actually p2 and can be modified
    p_ref.x = 100;
    std::cout << "After p_ref.x = 100: ";
    p2.print(); // Expected: (100, 2)
    std::cout << std::endl;

    return 0;
}