#include <iostream>

class Coordinate {
private:
    int x_val;
    int y_val;

public:
    Coordinate(int x, int y) : x_val(x), y_val(y) {}

    // Logical error: getX returns y_val
    int getX() const {
        return y_val; 
    }

    // Logical error: getY returns x_val
    int getY() const {
        return x_val;
    }

    // A non-const function for demonstration purposes (not called by const object)
    void setX(int newX) {
        x_val = newX;
    }
};

int main() {
    const Coordinate c(10, 20);

    // Calling const member functions on a const object
    std::cout << "Const object c.getX(): " << c.getX() << std::endl; // Expected 10, but will output 20
    std::cout << "Const object c.getY(): " << c.getY() << std::endl; // Expected 20, but will output 10

    // Demonstrate that a const object cannot call non-const functions
    // c.setX(30); // Uncommenting this would cause a semantic error

    return 0;
}