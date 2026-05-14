#include <iostream>

class Coordinate {
private:
    int x;
    int y;
public:
    Coordinate(int _x, int _y) : x(_x), y(_y) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    // Robustness Issue: This method modifies no state but is not marked 'const'.
    // This design choice prevents const objects from calling it, which is
    // a limitation if the intent was for it to be a general utility for printing.
    void printCoordinate() { // Missing const keyword
        std::cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Coordinate c1(10, 20); // Non-const object
    const Coordinate c2(30, 40); // Const object

    std::cout << "Non-const object c1: ";
    c1.printCoordinate(); // OK: non-const object calls non-const method
    std::cout << std::endl;

    // Demonstrate const accessors on a const object
    std::cout << "Const object c2 using const accessors: (" << c2.getX() << ", " << c2.getY() << ")" << std::endl;

    // The following line is commented out because it would cause a compile-time error.
    // This error highlights the robustness issue: if printCoordinate() was intended
    // to be used by const objects, its design is flawed by not being 'const'.
    // std::cout << "Const object c2 (attempting to print): ";
    // c2.printCoordinate(); // COMPILE ERROR: object has type 'const Coordinate' but method is not const
    // std::cout << std::endl;

    std::cout << "Attempting to call non-const printCoordinate() on const object c2 would result in a compile error, demonstrating a robustness issue in the method's design." << std::endl;

    return 0;
}