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

    int getY() const {
        return y_val;
    }

    // A non-const function
    void setX(int newX) {
        x_val = newX;
    }
};

int main() {
    const Coordinate c(10, 20);

    // Calling const member functions on a const object
    std::cout << "Const object c.getX(): " << c.getX() << std::endl;
    std::cout << "Const object c.getY(): " << c.getY() << std::endl;

    // Semantic error: Attempting to call a non-const member function (setX)
    // on a const object (c). This is not allowed by C++.
    c.setX(30); 

    return 0;
}