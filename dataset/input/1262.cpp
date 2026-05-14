#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Constructor with default values
    Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    // Getters for x and y
    int getX() const { return x; }
    int getY() const { return y; }

    // Setters for x and y
    void setX(int val) { x = val; }
    void setY(int val) { y = val; }

    // Readability/Efficiency Issue:
    // The operator uses getters and setters to access and modify internal members.
    // For simple primitive members like 'int x' and 'int y', this adds unnecessary
    // function call overhead (minor) and verbosity, reducing readability without
    // significant benefit in encapsulation within the operator itself.
    Point& operator++() {
        setX(getX() + 1); // Access and modify via methods
        setY(getY() + 1); // Access and modify via methods
        return *this;
    }

    // Method to print the point coordinates using getters
    void print() const {
        std::cout << "(" << getX() << ", " << getY() << ")";
    }
};

int main() {
    Point p(10, 20);
    std::cout << "Original point: ";
    p.print();
    std::cout << std::endl;

    // Basic increment
    ++p;
    std::cout << "After ++p: ";
    p.print();
    std::cout << std::endl;

    // Demonstrating the reference return
    Point& p_ref = ++p;
    std::cout << "After ++p (via ref): ";
    p_ref.print();
    std::cout << std::endl;

    // Confirming p_ref is actually p and can be modified
    p_ref.setX(100);
    std::cout << "After p_ref.setX(100): ";
    p.print(); // p should now reflect the change made via p_ref
    std::cout << std::endl;

    return 0;
}