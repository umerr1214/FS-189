#include <iostream>

class Coordinate {
private:
    int x;
    int y;
public:
    // Constructor using an initializer list for efficient and clean member initialization.
    Coordinate(int initialX, int initialY) : x(initialX), y(initialY) {}

    // const member function to retrieve the x-coordinate.
    // It guarantees that it will not modify the object's state.
    int getX() const {
        return x;
    }

    // const member function to retrieve the y-coordinate.
    // It guarantees that it will not modify the object's state.
    int getY() const {
        return y;
    }

    // A non-const member function that modifies the object's state.
    // This cannot be called by a const object.
    void setX(int newX) {
        x = newX;
    }

    // A const member function for printing, demonstrating that const objects
    // can call const utility methods.
    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    // 1. Create a non-const Coordinate object.
    Coordinate mutableCoord(10, 20);
    std::cout << "Mutable Coordinate (initial): ";
    mutableCoord.print(); // Non-const object can call const method
    std::cout << std::endl;

    // 2. Demonstrate non-const object calling a non-const method.
    mutableCoord.setX(15);
    std::cout << "Mutable Coordinate (after setX): ";
    mutableCoord.print();
    std::cout << std::endl;

    // 3. Create a const Coordinate object.
    const Coordinate fixedCoord(30, 40);
    std::cout << "Fixed Coordinate (const object): ";
    fixedCoord.print(); // Const object can call const method
    std::cout << std::endl;

    // 4. Demonstrate const object calling const getter methods.
    std::cout << "Fixed Coordinate X (using getX()): " << fixedCoord.getX() << std::endl;
    std::cout << "Fixed Coordinate Y (using getY()): " << fixedCoord.getY() << std::endl;

    // 5. Attempting to call a non-const method on a const object.
    // Uncommenting the line below would result in a compile-time error,
    // as 'setX()' is not a const member function and 'fixedCoord' is a const object.
    // fixedCoord.setX(35);

    std::cout << "Attempting to call setX() on 'fixedCoord' (a const object) would result in a compile-time error, as expected." << std::endl;

    return 0;
}