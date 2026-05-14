#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Default constructor
    Point() : x(0), y(0) {
        std::cout << "Default constructor called. Point(" << x << ", " << y << ")" << std::endl;
    }

    // Parameterized constructor
    Point(int x_val, int y_val) : x(x_val), y(y_val) {
        std::cout << "Parameterized constructor called. Point(" << x << ", " << y << ")" << std::endl;
    }

    // Logical error: x and y are swapped during copy
    Point(const Point& other) : x(other.y), y(other.x) { // Swapped other.x and other.y
        std::cout << "Copy constructor called (with swapped coords). Point(" << x << ", " << y << ") copied from (" << other.x << ", " << other.y << ")" << std::endl;
    }

    // Getter methods
    int getX() const { return x; }
    int getY() const { return y; }

    void display() const {
        std::cout << "Point coordinates: (" << x << ", " << y << ")" << std::endl;
    }
};

// Function to demonstrate pass-by-value
void processPoint(Point p) {
    std::cout << "Inside processPoint function." << std::endl;
    p.display();
}

int main() {
    std::cout << "--- Main Start ---" << std::endl;

    // 1. Default constructor
    Point p1;
    p1.display();

    std::cout << std::endl;

    // 2. Parameterized constructor
    Point p2(10, 20); // p2 is (10, 20)
    p2.display();

    std::cout << std::endl;

    // 3. Demonstrate copy constructor: Initialization
    std::cout << "After initializing p3 from p2:" << std::endl;
    Point p3 = p2; // Due to logical error, p3 will be (20, 10) instead of (10, 20)
    p3.display();

    std::cout << std::endl;

    // 4. Demonstrate copy constructor: Pass by value
    std::cout << "Calling processPoint with p2 by value..." << std::endl;
    // The Point 'p' inside processPoint will also be copied with swapped coords
    processPoint(p2);
    std::cout << "Returned from processPoint." << std::endl;
    p2.display(); // p2 itself should remain (10,20)

    std::cout << "--- Main End ---" << std::endl;
    return 0;
}