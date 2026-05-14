#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Readability / Efficiency Issue: Not using initializer lists for constructors.
    // Instead, members are assigned in the constructor body. For primitive types like int,
    // the efficiency impact is minimal, but for complex types, it can lead to
    // an extra default construction followed by an assignment. It also affects readability
    // as initializer lists are the idiomatic C++ way to initialize members.
    Point() {
        this->x = 0; // Readability issue: Unnecessary use of 'this->'
        this->y = 0; // Readability issue: Unnecessary use of 'this->'
    }

    // Readability / Efficiency Issue: Not using initializer lists for constructors.
    // Readability issue: Unnecessary use of 'this->'
    Point(int x_val, int y_val) {
        this->x = x_val;
        this->y = y_val;
    }

    // Getters are correctly const-qualified.
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

int main() {
    // Test default constructor
    Point p1;
    std::cout << p1.getX() << " " << p1.getY() << std::endl;

    // Test parameterized constructor
    Point p2(5, 10);
    std::cout << p2.getX() << " " << p2.getY() << std::endl;

    // Test with negative coordinates
    Point p3(-3, 7);
    std::cout << p3.getX() << " " << p3.getY() << std::endl;

    return 0;
}