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

    // Semantic error: No custom copy constructor provided.
    // The compiler-generated copy constructor will be used,
    // which correctly copies members but doesn't print a message,
    // thus failing to "demonstrate when the copy constructor is called" via observable output.
    // Point(const Point& other) : x(other.x), y(other.y) {
    //     std::cout << "Copy constructor called. Point(" << x << ", " << y << ") copied from (" << other.x << ", " << other.y << ")" << std::endl;
    // }

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
    Point p2(10, 20);
    p2.display();

    std::cout << std::endl;

    // 3. Demonstrate copy constructor: Initialization
    std::cout << "Initializing p3 from p2:" << std::endl;
    Point p3 = p2; // Compiler-generated copy constructor called implicitly
    p3.display();

    std::cout << std::endl;

    // 4. Demonstrate copy constructor: Pass by value
    std::cout << "Calling processPoint with p2 by value..." << std::endl;
    processPoint(p2); // Compiler-generated copy constructor called implicitly
    std::cout << "Returned from processPoint." << std::endl;
    p2.display();

    std::cout << "--- Main End ---" << std::endl;
    return 0;
}