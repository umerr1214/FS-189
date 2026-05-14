#include <iostream>

class Coordinate {
private:
    int x_val;
    int y_val;

public:
    Coordinate(int x, int y) : x_val(x), y_val(y) {}

    int getX() const {
        return x_val;
    }

    int getY() const
        return y_val; // Missing semicolon here
    }

    // A non-const function for demonstration purposes
    void setX(int newX) {
        x_val = newX;
    }
};

int main() {
    const Coordinate c(10, 20);

    // Calling const member functions on a const object
    std::cout << "Const object c.getX(): " << c.getX() << std::endl;
    std::cout << "Const object c.getY(): " << c.getY() << std::endl;

    // Attempting to call a non-const member function on a const object would result in a semantic error,
    // but the current error is syntax.
    // c.setX(30); // This line would cause a semantic error if uncommented and the syntax error was fixed.

    return 0;
}